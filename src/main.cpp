#include"Conta.hpp"
#include"Cliente.hpp"
#include"ContaPf.hpp"
#include"ContaPj.hpp"
#include"Banco.hpp"
#include"Gerente.hpp"
#include"RelatorioTemplate.hpp"
#include"Excecoes.hpp"
#include <iostream>

int main() {
    Banco banco;
    int opcao;

    do {
        std::cout << "\n=== MENU PRINCIPAL SPECTRAL BANK++ ===\n";
        std::cout << "1 - Gerenciar contas\n";
        std::cout << "2 - Realizar transacao\n";
        std::cout << "3 - Realizar saque\n";
        std::cout << "4 - Realizar deposito\n";
        std::cout << "5 - Validar transacoes\n";
        std::cout << "6 - Criar cartao\n";
        std::cout << "7 - Bloquear cartao\n";
        std::cout << "8 - Gerar relatorio geral\n";
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
                try {
                    banco.validar_transacoes();
                    } catch (const std::exception& e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                break;
            case 6:
                try{
                    banco.criar_cartao();
                } catch(const std::exception& e){
                    std::cerr << "Erro: " << e.what() << std::endl;
                }
                break;
            case 7:
                try {
                    banco.bloquear_cartao();
                    } catch (const std::exception& e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                break;
            case 8:
                try {
                    banco.gerar_relatorio();
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
