#include"Gerente.hpp"
#include"Banco.hpp"
#include"ContaPf.hpp"
#include"ContaPj.hpp"
#include"Cliente.hpp"
#include"Conta.hpp"
#include"Excecoes.hpp"

#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include<memory>
#include<string>
#include<algorithm>
#include <limits>

std::vector<std::shared_ptr<Conta>> contas;
std::vector<Transacao> transacoes;
std::vector<Cartao> cartoes;
std::vector<std::shared_ptr<Cliente>> clientes;

int Gerente::aprovar_pj(Banco& banco) {
    std::cout << "\n==== APROVAR CONTA PJ ====\n";
    int count = 0;
    auto& contas = banco.getContas();

    std::cout << "Contas PJ pendentes de aprovacao:\n";
    for (const auto& conta : contas) {
        if (auto pj = std::dynamic_pointer_cast<ContaPj>(conta)) {
            if (pj->isAtivo() && !pj->isAprovada()) {
                std::cout << "ID: " << pj->getId()
                          << " | Razao Social: " << pj->getRazaoSocial()
                          << " | Saldo: R$" << pj->getSaldo() << std::endl;
                count++;
            }
        }
    }

    if (count == 0) {
        std::cout << "Nenhuma conta PJ pendente de aprovacao.\n";
        return -1;
    }

    int id;
    std::cout << "Digite o ID da conta PJ para aprovar (0 para cancelar): ";
    std::cin >> id;
    if (std::cin.fail()) throw EntradaInvalidaException();

    if (id == 0) return -1;

    for (auto& conta : contas) {
        if (conta->getId() == id && !conta->isAprovada()) {
            if (auto pj = std::dynamic_pointer_cast<ContaPj>(conta)) {
                pj->aprovar();
                pj->definirLimite(15000); 
                std::cout << "Conta PJ ID " << id << " aprovada com sucesso!\n";
                return id;
            }
        }
    }
    throw ContaNaoEncontradaException(id);
}

int Gerente::liberar_limite(Banco& banco) {
    std::cout << "\n=== LIBERAR LIMITE ===\n";
    auto& contas = banco.getContas();

    for (const auto& conta : contas) {
        std::cout << "ID: " << conta->getId()
                  << " | Titular: " << conta->getNomeTitular()
                  << " | Limite atual: R$" << conta->getLimite() << std::endl;
    }

    int id;
    double novo_limite;
    std::cout << "\nDigite o ID da conta: ";
    std::cin >> id;
    if (std::cin.fail()) throw EntradaInvalidaException();
    std::cout << "Digite o novo limite: ";
    std::cin >> novo_limite;
    if (std::cin.fail()) throw EntradaInvalidaException();

    for (auto& conta : contas) {
        if (conta->getId() == id) {
            conta->definirLimite(novo_limite);
            std::cout << "Limite da conta " << id << " atualizado para R$" << novo_limite << " com sucesso!\n";
            return id;
        }
    }
    throw ContaNaoEncontradaException(id);
}

int Gerente::aprovar_negocio(Banco& banco) {
    std::cout << "\n==== APROVAR NEGOCIO/TRANSACAO ====\n";
    auto& transacoes = banco.getTransacoes();
    std::vector<int> indices_pendentes;

    std::cout << "Transacoes pendentes de aprovacao (> R$5000):\n";
    for (size_t i = 0; i < transacoes.size(); ++i) {
        if (!transacoes[i].aprovada && transacoes[i].valor > 5000) {
            const auto& t = transacoes[i];
            std::cout << indices_pendentes.size() + 1 << ". Origem: " << t.conta_origem
                      << " | Destino: " << t.conta_destino
                      << " | Valor: R$" << t.valor << std::endl;
            indices_pendentes.push_back(i);
        }
    }

    if (indices_pendentes.empty()) {
        std::cout << "Nenhuma transacao pendente de aprovacao.\n";
        return -1;
    }

    int escolha;
    std::cout << "Digite o numero da transacao para aprovar (0 para cancelar): ";
    std::cin >> escolha;

    if (escolha <= 0 || escolha > static_cast<int>(indices_pendentes.size())) {
        std::cout << "Operacao cancelada ou escolha invalida.\n";
        return -1;
    }

    int index_transacao = indices_pendentes[escolha - 1];
    transacoes[index_transacao].aprovada = true;
    std::cout << "Transacao aprovada com sucesso!\n";
    return 1;
}

void Gerente::gerar_relatorio_customizado(Banco& banco, const std::string& tipo_relatorio, int periodo) {
     auto& contas = banco.getContas();
    if (periodo <= 0) {
        std::cout << "Periodo invalido. Deve ser maior que zero.\n";
        return;
    }

    std::cout << "\n==== RELATORIO: " << tipo_relatorio << " (Periodo: " << periodo << " dias) ====\n";

    if (tipo_relatorio == "contas_ativas") {
        int total_contas = contas.size();
        int contas_ativas = 0;
        double saldo_total = 0.0;
        for (const auto& conta : contas) {
            if (conta->isAtivo()) {
                contas_ativas++;
                saldo_total += conta->getSaldo();
            }
        }
        exibirTotal("Total de contas", total_contas);
        exibirPercentual("Contas ativas", contas_ativas, total_contas);
        exibirMedia("Saldo total nas contas ativas", saldo_total, 1);

    } else if (tipo_relatorio == "contas_aprovadas") {
        int total_contas = contas.size();
        int contas_aprovadas = 0;
        double limite_total = 0.0;
        for (const auto& conta : contas) {
            if (conta->isAprovada()) {
                contas_aprovadas++;
                limite_total += conta->getLimite();
            }
        }
        exibirTotal("Total de contas", total_contas);
        exibirPercentual("Contas aprovadas", contas_aprovadas, total_contas);
        exibirTotal("Limite total concedido", limite_total);

    } else if (tipo_relatorio == "saldo_medio") {
        int contas_ativas = 0;
        double saldo_total = 0.0;
        for (const auto& conta : contas) {
            if (conta->isAtivo()) {
                contas_ativas++;
                saldo_total += conta->getSaldo();
            }
        }
        exibirTotal("Contas ativas consideradas", contas_ativas);
        exibirMedia("Saldo medio", saldo_total, contas_ativas);

    } else if (tipo_relatorio == "limite_medio") {
        int contas_com_limite = 0;
        double limite_total = 0.0;
        for (const auto& conta : contas) {
            if (conta->getLimite() > 0) {
                contas_com_limite++;
                limite_total += conta->getLimite();
            }
        }
        exibirTotal("Contas com limite", contas_com_limite);
        exibirMedia("Limite medio", limite_total, contas_com_limite);

    } else {
        std::cout << "Tipo de relatorio invalido.\n";
    }
    std::cout << "===================================\n";
}