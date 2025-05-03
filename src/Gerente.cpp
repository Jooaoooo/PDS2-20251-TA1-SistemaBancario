
#ifdef _WIN32
    #include"..\\include\\Gerente.hpp"
    #include"..\\include\\Banco.hpp"
    #include"..\\include\\ContaPf.hpp"
    #include"..\\include\\ContaPj.hpp"
    #include"..\\include\\Cliente.hpp"
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Gerente.hpp"
    #include"../include/Banco.hpp"
    #include"../include/ContaPf.hpp"
    #include"../include/ContaPj.hpp"
    #include"../include/Cliente.hpp"
    #include"../include/Conta.hpp"
#endif

#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include<memory>
#include<string>
#include<algorithm>
#include <limits>

// Reutilizando os vetores globais da classe Banco
std::vector<std::shared_ptr<Conta>> contas;
std::vector<Transacao> transacoes;
std::vector<Cartao> cartoes;
std::vector<std::shared_ptr<Cliente>> clientes;

#include <iostream>
#include <vector>

int Gerente::aprovar_pj() {
    std::cout << "==== APROVAR CONTA PJ ====";
    int count = 0;

    for (auto& conta : contas) {
        if (auto pj = std::dynamic_pointer_cast<ContaPj>(conta)) {
            if (pj->get_ativo() && !pj->get_aprovada()) {
                std::cout << "ID: " << pj->get_id()
                          << " Razão Social: " << pj->get_razao_social()
                          << " Saldo: " << pj->get_saldoBasico() << std::endl;
                count++;
            }
        }
    }

    if (count == 0) {
        std::cout << "Nenhuma conta PJ pendente de aprovação.\n";
        return -1;
    }

    int id;
    std::cout << "Digite o ID da conta PJ para aprovar: ";
    std::cin >> id;

    for (auto& conta : contas) {
        if (auto pj = std::dynamic_pointer_cast<ContaPj>(conta)) {
            if (pj->get_id() == id && !pj->get_aprovada()) {
                pj->set_aprovada(true);
                pj->set_limite(15000);
                std::cout << "Conta PJ aprovada!" << std::endl;
                return id;
            }
        }
    }

    std::cout << "ID não encontrado ou conta já aprovada." << std::endl;
    return -1;
}

int Gerente::liberar_limite() {
    std::cout << "=== LIBERAR LIMITE ===";
    for (auto& conta : contas) {
        std::cout << "ID: " << conta->get_id()
                  << "Saldo: " << conta->get_saldoBasico()
                  << " Limite atual: " << conta->get_limite() << std::endl;
    }

    int id;
    double novo_limite;

    std::cout << "Digite o ID da conta: ";
    std::cin >> id;
    std::cout << "Digite o novo limite: ";
    std::cin >> novo_limite;

    for (auto& conta : contas) {
        if (conta->get_id() == id) {
            conta->set_limite(novo_limite);
            std::cout << "Limite atualizado com sucesso! " << std::endl;
            return id;
        }
    }

    std::cout << "Conta não encontrada. " << std::endl;
    return -1;
}

int Gerente::aprovar_negocio() {
    std::cout << "==== APROVAR NEGÓCIO/TRANSAÇÃO ====";
    
    std::vector<Transacao> transacoes_pendentes;
    for (const auto& transacao : transacoes) {
        if (!transacao.aprovada && transacao.valor > 5000) {
            transacoes_pendentes.push_back(transacao);
        }
    }

    if (transacoes_pendentes.empty()) {
        std::cout << "Nenhuma transação pendente de aprovação." << std::endl;
        return -1;
    }

    // Listar transações pendentes
    std::cout << "Transações pendentes de aprovação:\n";
    for (size_t i = 0; i < transacoes_pendentes.size(); ++i) {
        const auto& t = transacoes_pendentes[i];
        std::cout << i+1 << ". ID Origem: " << t.conta_origem 
                  << "ID Destino: " << t.conta_destino
                  << "Valor: " << t.valor
                  << "Data: " << t.data << std::endl;
    }

    // Selecionar transação para aprovar
    int escolha;
    std::cout << "Digite o número da transação para aprovar (0 para cancelar): ";
    std::cin >> escolha;

    if (escolha <= 0 || escolha > static_cast<int>(transacoes_pendentes.size())) {
        std::cout << "Operação cancelada." << std::endl;
        return -1;
    }

    // Aprovar a transação selecionada
    const auto& transacao_selecionada = transacoes_pendentes[escolha-1];
    for (auto& t : transacoes) {
        if (t.conta_origem == transacao_selecionada.conta_origem &&
            t.conta_destino == transacao_selecionada.conta_destino &&
            t.valor == transacao_selecionada.valor &&
            t.data == transacao_selecionada.data) {
            t.aprovada = true;
            std::cout << "Transação aprovada com sucesso!" << std::endl;
            return 1;
        }
    }

    std::cout << "Erro ao aprovar transação." << std::endl;
    return -1;
}