#include"Conta.hpp"
#include"Cliente.hpp"
#include"ContaPf.hpp"
#include"ContaPj.hpp"
#include"Banco.hpp"
#include"Gerente.hpp"
#include"RelatorioTemplate.hpp"
#include <iostream>

int main() {
    Banco banco;
    int opcao;

    do {
        std::cout << "\n=== MENU PRINCIPAL DO BANCO ===\n";
        std::cout << "1 - Gerenciar contas\n";
        std::cout << "2 - Validar transacoes\n";
        std::cout << "3 - Bloquear cartao\n";
        std::cout << "4 - Gerar relatorio geral\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        if(std::cin.fail()) {
            std::cin.clear();
            opcao = -1; 
        }

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
            case 0:
                std::cout << "Saindo do sistema...\n";
                break;
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
