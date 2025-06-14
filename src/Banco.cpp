#ifdef _WIN32
    #include"..\\include\\Banco.hpp"
    #include"..\\include\\ContaPf.hpp"
    #include"..\\include\\ContaPj.hpp"
    #include"..\\include\\Cliente.hpp"
    #include "..\\include\\Conta.hpp"
#else
    #include"../include/Banco.hpp"
    #include"../include/ContaPf.hpp"
    #include"../include/ContaPj.hpp"
    #include"../include/Cliente.hpp"
    #include "../include/Conta.hpp"
#endif

#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include<memory>
#include<string>
#include<algorithm>
#include <limits>

//Criação de vector para instanciar os tad´s
static std::vector<std::shared_ptr<Conta>> contas;
static std::vector<Transacao> transacoes;
static std::vector<Cartao> cartoes;
static std::vector<std::shared_ptr<Cliente>> clientes;

int Banco::gerenciar_contas(){
    //É necessário saber oque é possível ser gerenciado.
    int opcao;
    std::cout<<"Selecione uma opcao: \n";
    std::cout<<"1 - Abrir conta PF"<<std::endl<<"2 - Abrir conta PJ"<<std::endl
    <<"3 - Consultar conta existente"<<std::endl<<"4 - Encerrar conta"<<std::endl<<"5 - Listar as contas existentes"<<std::endl;
    std::cout<<"Opcao: ";
    std::cin>>opcao;
    switch(opcao){
        case 1:{ //Abertura de conta PF
            auto cliente = std::make_shared<Cliente>();
            auto conta = std::make_shared<ContaPf>();

            //Será utilizado a definição do contrato de Cliente
            std::cout<<"Nome PF: ";
            std::cin.ignore();
            std::string nome;
            std::getline(std::cin, nome);
            conta->set_nome(nome);

            std::cout<<"CPF: ";
            std::string cpf;
            std::getline(std::cin, cpf);
            conta->set_cpf(cpf);

            std::cout<<"RG: ";
            std::string RG;
            std::getline(std::cin, RG);
            conta->set_rg(RG);

            std::cout<<"Senha: ";
            std::string senha;
            std::getline(std::cin, senha);
            conta->set_senha(senha);

            conta->set_id(conta->gerar_id());
            conta->set_saldoBasico(0);
            conta->set_ativo(1);
            conta->set_limite(1000);

            clientes.emplace_back(cliente);
            contas.emplace_back(conta);
            std::cout << "Conta PF criada com sucesso! ID: "<<conta->get_id()<<std::endl;
            return conta->get_id();
        }
        case 2:{ // Abertura de conta PJ
            auto cliente = std::make_shared<Cliente>();
            auto conta = std::make_shared<ContaPj>();

            std::cout << "Razão Social (Nome empresa): ";
            std::cin.ignore();
            std::string razao_social;
            std::getline(std::cin, razao_social);
            conta->set_razao_social(razao_social);

            std::cout << "CNPJ: ";
            std::string cnpj;
            std::getline(std::cin, cnpj);
            conta->set_cnpj(cnpj);

            std::cout << "Inscrição Estadual: ";
            std::string ie;
            std::getline(std::cin, ie);
            conta->set_inscricao_estadual(ie);

            std::cout << "Senha: ";
            std::string senha;
            std::getline(std::cin, senha);
            conta->set_senha(senha);

            // Configuração inicial da conta
            conta->set_id(conta->gerar_id());
            conta->set_saldoBasico(0);
            conta->set_ativo(1);
            conta->set_limite(5000); // Limite maior para PJ

            contas.push_back(conta);
            clientes.push_back(cliente);
            
            std::cout << "Conta PJ criada com sucesso! ID: "<<conta->get_id()<< std::endl;
            return conta->get_id();
    }
    case 3:{ //Consultar conta pelo id
        int id;
            std::cout<<"Informe o ID da conta: ";
            std::cin>>id;
            
            for (const auto& conta : contas) {
                if (conta->get_id() == id) {
                    std::cout << "Conta encontrada!\n";
                    return id;
                }
            }
            std::cout << "Conta não encontrada!\n";
            return -1;
    }
    case 4:{ //Encerrar uma conta pelo id
        int id;
            std::cout << "Informe o ID da conta a encerrar: ";
            std::cin >> id;
            
            for (auto& conta : contas) {
                if (conta->get_id() == id) {
                    conta->set_ativo(0);
                    std::cout << "Conta encerrada com sucesso!\n";
                    return id;
                }
            }
            std::cout << "Conta não encontrada!\n";
            return -1;
    }
    case 5:{ //Listar as contas
        for (const auto& conta : contas) {
            std::cout << "ID: " << conta->get_id() << " - ";
            if (auto pf = std::dynamic_pointer_cast<ContaPf>(conta)) {
                std::cout << "PF: " << pf->get_nome();
            } else if (auto pj = std::dynamic_pointer_cast<ContaPj>(conta)) {
                std::cout << "PJ: " << pj->get_razao_social();
            }
            std::cout << " - Saldo: " << conta->get_saldoBasico() << "\n";
        }
        return contas.size();
    }
    default:
        std::cout << "Opção inválida!\n";
        return -1;
    }
}
int Banco::validar_transacoes() {
    std::cout << "Validando transações..." << std::endl;
    
    for (auto& transacao : transacoes) {
        if (transacao.valor <= 5000) {
            // Aprova a transação automaticamente se o valor for menor ou igual a 5000
            transacao.aprovada = true;
            std::cout << "Transação de ID " << transacao.conta_origem 
                      << " aprovada automaticamente (valor <= 5000)." << std::endl;
        } else if (transacao.valor > 0) {
            std::cout << "Transação de ID " << transacao.conta_origem 
                      << " não aprovada automaticamente (valor > 5000)." << std::endl;
        } else {
            std::cout << "Transação inválida detectada!" << std::endl;
            return -1; // Código de erro para transação inválida
        }
    }
    
    return 0; // Sucesso
}

int Banco::bloquear_cartao(){
    std::string numero;
    std::cout << "Informe o número do cartão: ";
    std::cin >> numero;
    
    for (auto& cartao : cartoes) {
        if (cartao.numero == numero) {
            cartao.bloqueado = true;
            std::cout << "Cartão bloqueado com sucesso!\n";
            return 1;
        }
    }
    std::cout << "Cartão não encontrado!\n";
    return -1;
}
int Banco::gerar_relatorio() {
    std::ofstream relatorio("relatorio_banco.txt");
    if (!relatorio) {
        std::cerr << "Erro ao criar relatório!\n";
        return -1;
    }

    int totalContas = contas.size();
    int totalTransacoes = transacoes.size();
    int totalCartoes = cartoes.size();

    relatorio << "Relatório do Banco\n";
    exibirTotal("Total de contas", totalContas);
    exibirTotal("Total de transações", totalTransacoes);
    exibirTotal("Total de cartões", totalCartoes);

    relatorio.close();
    std::cout << "Relatório gerado com sucesso!\n";
    return 1;
}