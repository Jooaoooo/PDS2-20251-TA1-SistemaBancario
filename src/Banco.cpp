#ifdef _WIN32
    #include"..\\include\\Banco.hpp"
    #include"..\\include\\ContaPf.hpp"
    #include"..\\include\\ContaPj.hpp"
    #include"..\\include\\Cliente.hpp"
    #include"..\\include\\RelatorioTemplate.hpp"
    #include "..\\include\\Conta.hpp"
#else
    #include"../include/Banco.hpp"
    #include"../include/ContaPf.hpp"
    #include"../include/ContaPj.hpp"
    #include"../include/Cliente.hpp"
    #include "../include/Conta.hpp"
    #include "../include/RelatorioTemplate.hpp"
#endif

#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include<memory>
#include<string>
#include<algorithm>
#include <limits>

std::vector<std::shared_ptr<Conta>>& Banco::getContas() { return contas; }
std::vector<Transacao>& Banco::getTransacoes() { return transacoes; }

void limparBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Banco::gerenciar_contas() {
    int opcao;
    std::cout << "\n--- Gerenciamento de Contas ---\n";
    std::cout << "1 - Abrir conta PF\n"
              << "2 - Abrir conta PJ\n"
              << "3 - Consultar conta existente\n"
              << "4 - Encerrar conta\n"
              << "5 - Listar contas existentes\n"
              << "Opcao: ";
    std::cin >> opcao;
    limparBuffer();

    switch (opcao) {
        case 1: { 
            std::string nome, cpf, rg, senha, endereco, email, telefone;
            std::cout << "Nome completo: ";
            std::getline(std::cin, nome);
            std::cout << "CPF: ";
            std::getline(std::cin, cpf);
            std::cout << "RG: ";
            std::getline(std::cin, rg);
            std::cout << "Senha: ";
            std::getline(std::cin, senha);
            std::cout << "Endereco: ";
            std::getline(std::cin, endereco);
            std::cout << "Email: ";
            std::getline(std::cin, email);
            std::cout << "Telefone: ";
            std::getline(std::cin, telefone);

            auto cliente = std::make_shared<Cliente>(nome, cpf, rg, senha, endereco, email, telefone);
            auto conta = std::make_shared<ContaPf>(cliente, senha);
            
            this->clientes.push_back(cliente);
            this->contas.push_back(conta);
            
            std::cout << "Conta PF criada com sucesso! ID: " << conta->getId() << std::endl;
            return conta->getId();
        }
        case 2: { 
            std::string razao_social, cnpj, rg_responsavel, senha, endereco, email, telefone;
            std::cout << "Razao Social (Nome empresa): ";
            std::getline(std::cin, razao_social);
            std::cout << "CNPJ: ";
            std::getline(std::cin, cnpj);
            std::cout << "RG do Responsavel: ";
            std::getline(std::cin, rg_responsavel);
            std::cout << "Senha: ";
            std::getline(std::cin, senha);
            std::cout << "Endereco: ";
            std::getline(std::cin, endereco);
            std::cout << "Email: ";
            std::getline(std::cin, email);
            std::cout << "Telefone: ";
            std::getline(std::cin, telefone);

            auto cliente = std::make_shared<Cliente>(razao_social, cnpj, rg_responsavel, senha, endereco, email, telefone);
            auto conta = std::make_shared<ContaPj>(cliente, senha);

            this->clientes.push_back(cliente);
            this->contas.push_back(conta);
            
            std::cout << "Conta PJ criada com sucesso! ID: " << conta->getId() << std::endl;
            return conta->getId();
        }
        case 3: { 
            int id;
            std::cout << "Informe o ID da conta: ";
            std::cin >> id;
            for (const auto& conta : this->contas) {
                if (conta->getId() == id) {
                    std::cout << "Conta encontrada! Titular: " << conta->getNomeTitular() << ", Saldo: R$" << conta->getSaldo() << std::endl;
                    return id;
                }
            }
            std::cout << "Conta nao encontrada!\n";
            return -1;
        }
        case 4: { 
            int id;
            std::cout << "Informe o ID da conta a encerrar: ";
            std::cin >> id;
            for (auto& conta : this->contas) {
                if (conta->getId() == id) {
                    conta->bloquear();
                    return id;
                }
            }
            std::cout << "Conta nao encontrada!\n";
            return -1;
        }
        case 5: { // Listar as contas
            if (contas.empty()) {
                std::cout << "Nenhuma conta cadastrada.\n";
                return 0;
            }
            for (const auto& conta : this->contas) {
                std::cout << "ID: " << conta->getId() << " - Titular: " << conta->getNomeTitular()
                          << " - Saldo: R$" << conta->getSaldo() << " - Ativa: " << (conta->isAtivo() ? "Sim" : "Nao") << "\n";
            }
            return contas.size();
        }
        default:
            std::cout << "Opcao invalida!\n";
            return -1;
    }
}

int Banco::validar_transacoes() {
    std::cout << "Validando transacoes...\n";
    int aprovadas = 0;
    for (auto& transacao : this->transacoes) {
        if (!transacao.aprovada && transacao.valor > 0) {
            if (transacao.valor <= 5000) {
                transacao.aprovada = true;
                aprovadas++;
                std::cout << "Transacao da conta " << transacao.conta_origem
                          << " aprovada automaticamente (valor <= 5000).\n";
            } else {
                std::cout << "Transacao da conta " << transacao.conta_origem
                          << " necessita de aprovacao manual (valor > 5000).\n";
            }
        }
    }
    if (aprovadas == 0) {
        std::cout << "Nenhuma nova transacao aprovada automaticamente.\n";
    }
    return aprovadas;
}

int Banco::bloquear_cartao() {
    std::string numero;
    std::cout << "Informe o numero do cartao a ser bloqueado: ";
    std::cin >> numero;
    for (auto& cartao : this->cartoes) {
        if (cartao.numero == numero) {
            cartao.bloqueado = true;
            std::cout << "Cartao final " << numero.substr(numero.length() - 4) << " bloqueado com sucesso!\n";
            return 1;
        }
    }
    std::cout << "Cartao nao encontrado!\n";
    return -1;
}

int Banco::gerar_relatorio() {
    std::ofstream relatorio("relatorio_banco.txt");
    if (!relatorio.is_open()) {
        std::cerr << "Erro ao criar arquivo de relatorio!\n";
        return -1;
    }

    relatorio << "--- Relatorio Geral do Banco ---\n\n";
    exibirTotal("Total de contas", this->contas.size());
    exibirTotal("Total de transacoes", this->transacoes.size());
    exibirTotal("Total de cartoes", this->cartoes.size());
    relatorio << "\n--- Detalhes das Contas ---\n";
    for (const auto& conta : this->contas) {
        relatorio << "ID: " << conta->getId() << " | Titular: " << conta->getNomeTitular()
                  << " | Saldo: R$" << conta->getSaldo() << " | Ativa: " << (conta->isAtivo() ? "Sim" : "Nao") << "\n";
    }

    relatorio.close();
    std::cout << "Relatorio 'relatorio_banco.txt' gerado com sucesso!\n";
    return 1;
}