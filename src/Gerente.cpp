#pragma once

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
extern std::vector<std::shared_ptr<Conta>> contas;
extern std::vector<Transacao> transacoes;
extern std::vector<Cartao> cartoes;
extern std::vector<std::shared_ptr<Cliente>> clientes;

#include <iostream>
#include <vector>

class Gerente {
private:
    std::vector<Conta*> contas_sob_analise;
    
public:
    int aprovar_pj(std::vector<Conta*>& contas);
    int liberar_limite(std::vector<Conta*>& contas);
    int aprovar_negocio();
    int auditar_transacoes_suspeitas();
    int gerenciar_relatorios_customizados();
    int gerenciar_equipe_atendimento();
};

int Gerente::aprovar_pj(std::vector<Conta*>& contas) {
    std::cout << "==== APROVAR CONTA PJ ====";
    int count = 0;
    
    for (Conta* conta : contas) {
        if (conta->get_ativo() && !conta->get_aprovada()) {
            std::cout << "ID: " << conta->get_id() 
                      << "Saldo: " << conta->get_saldoBasico() 
                      << "Limite: " << conta->get_limite() << std::endl;
            count++;
        }
    }
    
    if (count == 0) {
        std::cout << "Nenhuma conta pendente de aprovação." << std::endl;
        return -1;
    }
    
    int id;
    std::cout << "Digite o ID da conta a ser aprovada: ";
    std::cin >> id;
    
    for (Conta* conta : contas) {
        if (conta->get_id() == id && !conta->get_aprovada()) {
            conta->set_aprovada(true);
            conta->set_limite(15000);
            std::cout << "Conta aprovada com sucesso!" << std::endl;
            return id;
        }
    }
    
    std::cout << "ID não encontrado ou conta já aprovada." << std::endl;
    return -1;
}

int Gerente::liberar_limite(std::vector<Conta*>& contas) {
    std::cout << "=== LIBERAR LIMITE ===";
    
    for (Conta* conta : contas) {
        std::cout << "ID: " << conta->get_id() 
                  << "Saldo: " << conta->get_saldoBasico() 
                  << "Limite atual: " << conta->get_limite() << std::endl;
    }
    
    int id;
    double novo_limite;
    
    std::cout << "Digite o ID da conta: ";
    std::cin >> id;
    std::cout << "Digite o novo limite: ";
    std::cin >> novo_limite;
    
    for (Conta* conta : contas) {
        if (conta->get_id() == id) {
            conta->set_limite(novo_limite);
            std::cout << "Limite atualizado com sucesso!" << std::endl;
            return id;
        }
    }
    
    std::cout << "Conta não encontrada." << std::endl;
    return -1;
}
