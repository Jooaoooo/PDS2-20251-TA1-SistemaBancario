/**
 *@file main.cpp 
 * @brief Software de sistema bancário 
 * 
 * Esse programa simula um software de sistema bancário, contendo
 * operações básicas que um banco pode conter com contas do tipo 
 * pessoa física, pessoa jurídica e também gerente.
 * 
 * @author Lucas Miller dos Santos Sousa
 * @author João Augusto Rosa Cunha
 * @author Alan Pessoa Silva
 * @author Natan Inoue dos Reis
 * 
 * @date abril de 2025
 * */

#include "Conta.hpp"
#include "Cliente.hpp"
#include "ContaPf.hpp"
#include "ContaPj.hpp"
#include "Banco.hpp"
#include "Gerente.hpp"
#include "RelatorioTemplate.hpp"
#include "Excecoes.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>


/**
 * @brief Realiza a leitura do arquivo de gerentes e armazena em um vector
 * @param gerentes - referência para vector de clientes
 * @return Retorna o tamanho do vector gerentes
 * */ 
int setup_gerentes(std::vector<Gerente>&gerentes);

/**
 * @brief Interface geral para o usuário
 * 
 * Contém a interfácie inicial para o cliente, contém 
 * instância de Banco e Gerente, além de criar a ponte entre
 * os dois
 * 
 * */
int main() {
    Banco banco;
    std::vector<Gerente> gerentes;
    setup_gerentes(gerentes);

    int opcao;

    do {
        std::cout << "\n=== MENU PRINCIPAL SPECTRAL BANK++ ===\n";
        std::cout << "1 - Gerenciar contas\n";
        std::cout << "2 - Realizar transacao\n";
        std::cout << "3 - Realizar saque\n";
        std::cout << "4 - Realizar deposito\n";
        std::cout << "5 - Criar cartao\n";
        std::cout << "6 - Bloquear cartao\n";
        std::cout << "7 - Menu gerente\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        if(std::cin.fail()) {
            std::cin.clear();
            opcao = -1; 
        }

        switch (opcao) {
            case 1:
                try {
                    banco.gerenciar_contas();
                    } catch (const std::exception& e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                break;
            case 2:
                try {
                    banco.realizar_transacao();
                    } catch (const std::exception& e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                break;
            case 3:
                try {
                    banco.realizar_saque();
                    } catch (const std::exception& e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                break;
            case 4:
                try {
                    banco.realizar_deposito();
                    } catch (const std::exception& e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                break;
            case 5:
                try{
                    banco.criar_cartao();
                } catch(const std::exception& e){
                    std::cerr << "Erro: " << e.what() << std::endl;
                }
                break;
            case 6:
                try {
                    banco.bloquear_cartao();
                    } catch (const std::exception& e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                break;
            case 7:
                try {
                    std::string cpf, rg, senha;
                    std::cout << "---Acesse como Gerente---" << std::endl
                    << "Digite as seguintes informacoes" << std::endl
                    << "cpf: ";
                std::cin >> cpf;
                if (std::cin.fail()) throw EntradaInvalidaException();
                
                std::cout << "rg: ";
                std::cin >> rg;
                if (std::cin.fail()) throw EntradaInvalidaException();
                
                std::cout << "senha: ";
                std::cin >> senha;
                if (std::cin.fail()) throw EntradaInvalidaException();
                
                int pos=-1;
                for(size_t i=0; i < gerentes.size(); i++){
                    if(gerentes[i].autenticacao(cpf,rg,senha)){
                        pos = 1;
                    }
                }
                if(pos == -1){
                    throw GerenteNaoEncontradaException();
                }else{
                    gerentes[pos].operacoes_gerente(banco);
                }
                
                    } catch (const std::exception& e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                break;
            case 0:
                std::cout << "Saindo do sistema...\n";
                break;
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}

int setup_gerentes(std::vector<Gerente>&gerentes){
    std::ifstream gerenteSheet("gerentes.spec", std::fstream::in);
    if (!gerenteSheet.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: gerentes.spec" << std::endl;
        return 0;
    }
    std::string linha="";
    while (std::getline(gerenteSheet, linha)) {
        std::stringstream ss(linha);
        std::string entrada;
        while(std::getline(ss, entrada, ',')){
            std::stringstream campos(entrada);
            std::string nome, cpf, rg, senha;
            if(std::getline(campos, nome, ';')
            && std::getline(campos, cpf, ';')
            && std::getline(campos, rg, ';')
            && std::getline(campos, senha, ';')){
                nome.erase(0,nome.find_first_not_of(" \n\r\t"));
                nome.erase(nome.find_last_not_of(" \n\r\t")+1);
            gerentes.emplace_back(nome, cpf, rg, senha);
            }

        }

    }
    return gerentes.size();
}