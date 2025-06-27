#include "Banco.hpp"
#include "ContaPf.hpp"
#include "ContaPj.hpp"
#include "Cliente.hpp"
#include "Conta.hpp"
#include "RelatorioTemplate.hpp"
#include "Calendario.hpp"
#include "Excecoes.hpp"

#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include<memory>
#include<string>
#include<algorithm>
#include <limits>
#include <random>
#include <string>

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
    if (std::cin.fail()) throw EntradaInvalidaException();
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
            double saldoInicial;
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
            std::cout << "Quanto quer depositar inicialmente? (mínimo R$5000,00) ";
            while(1){
                std::cin >> saldoInicial;
                if(saldoInicial < 5000){
                    std::cout << "Saldo inicial inválido, digite novamente: " << std::endl;
                }else{
                    break;
                }
            }

            auto cliente = std::make_shared<Cliente>(razao_social, cnpj, rg_responsavel, senha, endereco, email, telefone);
            auto conta = std::make_shared<ContaPj>(cliente, senha, saldoInicial);

            this->clientes.push_back(cliente);
            this->contas.push_back(conta);
            
            std::cout << "Conta PJ criada com sucesso! ID: " << conta->getId() << std::endl;
            return conta->getId();
        }
        case 3: { 
            int id;
            std::cout << "Informe o ID da conta: ";
            std::cin >> id;
            if (std::cin.fail()) throw EntradaInvalidaException();

            for (const auto& conta : this->contas) {
                if (conta->getId() == id) {
                    std::cout << "Conta encontrada! Titular: " << conta->getNomeTitular() << ", Saldo: R$" << conta->getSaldo() << std::endl;
                    return id;
                }
            }
            throw ContaNaoEncontradaException(id);
        }
        case 4: { 
            int id;
            std::cout << "Informe o ID da conta a encerrar: ";
            std::cin >> id;
            if (std::cin.fail()) throw EntradaInvalidaException();

            for (auto& conta : this->contas) {
                if (conta->getId() == id) {
                    conta->bloquear();
                    return id;
                }
            }
            throw ContaNaoEncontradaException(id);
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
            throw EntradaInvalidaException();
    }
}

void Banco::validar_transacao(Transacao &transacao){
    if (transacao.valor <= 5000) {
        transacao.aprovada = true;
    } else {
        transacao.aprovada = false;
    }
}

int Banco::validar_transacoes() {
    std::cout << "Validando transacoes...\n";
    int aprovadas = 0;
    for (auto& transacao : this->transacoes) {
        this->validar_transacao(transacao);
        if (transacao.valor > 0){
            if (transacao.aprovada == true) {
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

int Banco::criar_cartao(){
    Calendario novaData;
    std::string id="";
    std::string num = "";
    int final=0;
    int existente=0;

    std::cout << "Informe o numero ID da conta : ";
    std::cin >> id;
    if (std::cin.fail()) throw EntradaInvalidaException();
    //if(!std::stoi(id)) throw EntradaInvalidaException();

    novaData.calcular_data();

    num += novaData.get_data(2);
    num += novaData.get_data(1);
    num += novaData.get_data(0);
    
    while(1){
        existente = 0;
        {//gera aleatório
            std::random_device rd; //fonte de entropia
            std::mt19937 gen(rd()); //engine de números pseudoaleatórios
            std::uniform_int_distribution<> dist(100, 999); //gera distribuiçao entre 100 e 999
            final = dist(gen);
        }
        for(auto& cartao : cartoes){
            if(cartao.numero == (num + std::to_string(final))) {
                existente++;
            }
        }
        if(!existente){
            num+=std::to_string(final);
            break;
        }
    }
    Cartao novoCartao;
    novoCartao.numero = num;
    novoCartao.conta_cartao = std::stoi(id);
    cartoes.push_back(novoCartao);
    return 1;
    //throw CartaoNaoEncontradoException(numero);
}

int Banco::bloquear_cartao() {
    std::string numero;
    std::cout << "Informe o numero do cartao a ser bloqueado: ";
    std::cin >> numero;
    if (std::cin.fail()) throw EntradaInvalidaException();

    for (auto& cartao : cartoes) {
        if (cartao.numero == numero) {
            cartao.bloqueado = true;
            std::cout << "Cartao final " << numero.substr(numero.length() - 4) << " bloqueado com sucesso!\n";
            return 1;
        }
    }
    throw CartaoNaoEncontradoException(numero);
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

    //int receber_transacoes(int id_remetente, float valor);//conta recebimentom = 1
int Banco::realizar_transacoes(int id_destinatario, float valor)
{
    if (valor <= 0) throw EntradaInvalidaException();
    if (static_cast<size_t>(id_destinatario) >= contas.size()) throw ContaNaoEncontradaException(id_destinatario);

    Transacao transac;//cria transac
    transac.conta_origem = 1;
    transac.conta_destino = id_destinatario;
    transac.valor = valor;
    this->validar_transacao(transac);
    if(transac.aprovada)
    {
        this->transacoes.push_back(transac);//adiciona transac para a lista
        this->contas[1]->sacar(valor);
        this->contas[id_destinatario]->depositar(valor);
        return 1;
    }
    return 0;
}
int Banco::receber_transacoes(int id_remetente, float valor){

    if (valor <= 0) throw EntradaInvalidaException();
    if (static_cast<size_t>(id_remetente) >= contas.size()) throw ContaNaoEncontradaException(id_remetente);

    Transacao transac;//cria transac
    transac.conta_origem = id_remetente;
    transac.conta_destino = 1;
    transac.valor = valor;
    this->validar_transacao(transac);
    if(transac.aprovada)
    {   
        this->transacoes.push_back(transac);//adiciona transac para a lista
        this->contas[id_remetente]->sacar(valor);
        this->contas[1]->depositar(valor);
        return 1;
    }
    return 0;
}