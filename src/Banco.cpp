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
int Banco::posicao_id(int id){
    int pos = 0;
    int encontrado =0;
    for(auto & c : this->contas){
        if(id == c->getId()){
            encontrado++;
            break;
        }
        pos++;
    }
    if(!encontrado) throw ContaNaoEncontradaException(id);
    return pos;
}
bool Banco::verifica_id(int id){
    for(auto & c : this->contas){
        if(id == c->getId()){
            return true;
        }
    }
    throw CartaoNaoEncontradoException(std::to_string(id));
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
            
            // Geração do ID - corrigido com ponto-e-vírgula
            int id = contas.empty() ? 1 : (contas.back()->getId() + 1);
            
            auto conta = std::make_shared<ContaPf>(cliente, id, senha);
            
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
        while(true) {
            std::cin >> saldoInicial;
            if(std::cin.fail() || saldoInicial < 5000) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Saldo inicial inválido, digite novamente (mínimo R$5000,00): ";
            } else {
                break;
            }
        }
        std::cin.ignore(); // Limpar buffer após o cin >>

        auto cliente = std::make_shared<Cliente>(razao_social, cnpj, rg_responsavel, senha, endereco, email, telefone);
        
        // Geração do ID - mesma lógica da PF
        int id = contas.empty() ? 1 : (contas.back()->getId() + 1);
        
        auto conta = std::make_shared<ContaPj>(cliente, id, senha, saldoInicial);
        
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
    int id;
    std::string num = "";
    int final=0;
    int existente=0;

    std::cout << "Informe o numero ID da conta : ";
    std::cin >> id;
    if (std::cin.fail()) throw EntradaInvalidaException();
    //if(!std::stoi(id)) throw EntradaInvalidaException();
    verifica_id(id);

    novaData.calcular_data();

    num += std::to_string(novaData.get_data(2));
    num += std::to_string(novaData.get_data(1));
    num += std::to_string(novaData.get_data(0));
    
    while(1){//cria num do cartão
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
    novoCartao.conta_cartao = id;
    cartoes.push_back(novoCartao);
    int pos = posicao_id(id);
    this->contas[pos]->set_num_cartao(novoCartao.numero);
    std::cout << "Cartao criado com sucesso, o número do seu cartao é: " << 
    novoCartao.numero << std::endl;
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

int Banco::realizar_transacao(){
    int id_origem, id_destinatario;
    float valor;

    std::cout << "Qual o ID da conta de origem? ";
    std::cin >> id_origem;
    if (std::cin.fail()) throw EntradaInvalidaException();
    verifica_id(id_origem);

    std::cout << "Qual o ID do destinatario da transacao? ";
    std::cin >> id_destinatario;
    if (std::cin.fail()) throw EntradaInvalidaException();
    verifica_id(id_destinatario);

    if(id_origem == id_destinatario) {
        throw EntradaInvalidaException("Não pode transferir para a mesma conta");
    }

    std::cout << "Digite o valor que deseja transferir: ";
    std::cin >> valor;
    if (std::cin.fail()) throw EntradaInvalidaException();
 
    if (valor <= 0) throw EntradaInvalidaException();

    Transacao transac;
    transac.conta_origem = id_origem;
    transac.conta_destino = id_destinatario;
    transac.valor = valor;
    this->validar_transacao(transac);

    if(transac.aprovada) {
        int pos_origem = posicao_id(id_origem);
        int pos_destino = posicao_id(id_destinatario);
        
        this->contas[pos_origem]->sacar(valor);
        this->contas[pos_destino]->depositar(valor);
        
        this->transacoes.push_back(transac);
        std::cout << "Transacao realizada com sucesso!" << std::endl;
        return 1;
    }
    
    return 0;
}

int Banco::realizar_saque(){
    int id_conta;
    float valor;

    std::cout << "Qual o ID da conta? ";
    std::cin >> id_conta;
    if (std::cin.fail()) throw EntradaInvalidaException();
    verifica_id(id_conta);

    std::cout << "Digite o valor a sacar: ";
    std::cin >> valor;
    if (std::cin.fail()) throw EntradaInvalidaException();
    if (valor <= 0) throw EntradaInvalidaException();

    int pos = posicao_id(id_conta);
    this->contas[pos]->sacar(valor);

    Calendario novaData;
    novaData.calcular_data();
    Saque novoSaque;

    novoSaque.id_conta = id_conta;
    novoSaque.data = novaData.get_data();
    novoSaque.valor = valor;

    this->saques.push_back(novoSaque);
    std::cout << "Saque realizado com sucesso!" << std::endl;
    return 1;
}
    int Banco::realizar_deposito() {
    int id_conta;
    float valor;

    // Solicitar ID da conta
    std::cout << "Qual o ID da conta para deposito? ";
    std::cin >> id_conta;
    if (std::cin.fail()) throw EntradaInvalidaException();
    verifica_id(id_conta);

    // Solicitar valor do depósito
    std::cout << "Digite o valor a depositar: ";
    std::cin >> valor;
    if (std::cin.fail()) throw EntradaInvalidaException();
    if (valor <= 0) throw EntradaInvalidaException("Valor deve ser positivo");

    // Realizar o depósito
    int pos = posicao_id(id_conta);
    this->contas[pos]->depositar(valor);

    // Registrar o depósito
    Calendario novaData;
    novaData.calcular_data();
    Deposito novoDeposito;

    novoDeposito.id_conta = id_conta;
    novoDeposito.data = novaData.get_data();
    novoDeposito.valor = valor;

    this->depositos.push_back(novoDeposito);
    std::cout << "Deposito realizado com sucesso na conta ID " << id_conta << "!" << std::endl;
    
    return 1;
}