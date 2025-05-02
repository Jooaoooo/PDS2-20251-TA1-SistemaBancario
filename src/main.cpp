#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
    #include"..\\include\\Cliente.hpp"
    #include"..\\include\\ContaPf.hpp"
    #include"..\\include\\ContaPj.hpp"
    #include"..\\include\\Banco.hpp"
    #include"..\\include\\Gerente.hpp"
#else
    #include"../include/Conta.hpp"
    #include"../include/Cliente.hpp"
    #include"../include/ContaPf.hpp"
    #include"../include/ContaPj.hpp"
    #include"../include/Banco.hpp"
    #include"../include/Gerente.hpp"
#endif
#include<iostream>

int main(){
    Banco banco;
    int opcao;

    do {
        std::cout << "\n=== MENU DO BANCO ===\n";
        std::cout << "1 - Gerenciar contas\n";
        std::cout << "2 - Validar transações\n";
        std::cout << "3 - Bloquear cartão\n";
        std::cout << "4 - Gerar relatório\n";
        std::cout << "5 - Processar folha de pagamento\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                banco.gerenciar_contas();
                break;
            case 2:
                banco.validar_transacoes();
                break;
            case 3:
                banco.bloquear_cartao();
                break;
            case 4:
                banco.gerar_relatorio();
                break;
            case 5:
                banco.processar_folha_pagamento();
                break;
            case 0:
                std::cout << "Saindo do sistema...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}