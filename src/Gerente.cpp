#include"Gerente.hpp"
#include"Banco.hpp"
#include"ContaPf.hpp"
#include"ContaPj.hpp"
#include"Cliente.hpp"
#include"Conta.hpp"
#include"Excecoes.hpp"
#include"Calendario.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <memory>
#include <string>
#include <algorithm>
#include <limits>

std::vector<std::shared_ptr<Conta>> contas;
std::vector<Transacao> transacoes;
std::vector<Cartao> cartoes;
std::vector<std::shared_ptr<Cliente>> clientes;

Gerente::Gerente(std::string nome, std::string cpf, std::string rg, std::string senha)
    :_nome(nome),_cpf(cpf), _rg(rg), _senha(senha) {};


int Gerente::operacoes_gerente(Banco& banco){
    std::cout << "Logado como " << this->_nome << "\n" 
                    << " Digite a operacao que deseja realizar: \n" << std::endl
                    << "1 - Aprovar pj\n"
                    << "2 - Validar transacoes\n"
                    << "3 - Listar contas existentes\n"
                    << "4 - Gerar relatorio\n"
                    << "0. Sair\n"
                    << "Opcao: ";
    int opc;
    std::cin >> opc;
    if (std::cin.fail()) throw EntradaInvalidaException();
    switch(opc){
        case 1:
            aprovar_pj(banco);
            break;
        case 2:
            validar_transacoes(banco);
            break;
        case 3:
            { // Listar as contas
                if (banco.isContasEmpty()) {
                    std::cout << "Nenhuma conta cadastrada.\n";
                    return 0;
                }
                for (const auto& conta : banco.getContas()) {
                    std::cout << "ID: " << conta->getId() << " - Titular: " << conta->getNomeTitular()
                              << " - Saldo: R$" << conta->getSaldo() << " - Ativa: " << (conta->isAtivo() ? "Sim" : "Nao") << "\n";
                }
                return banco.contasSize();
            }
            break;
        case 4:
            gerar_relatorio(banco);
            break;
        default:
            break;
    }


    return 1;
}

int Gerente::aprovar_pj(Banco& banco) {
    std::cout << "\n==== APROVAR CONTA PJ ====\n";
    int count = 0;
    auto& contas = banco.getContas();

    std::cout << "Contas PJ pendentes de aprovacao:\n";
    for (const auto& conta : contas) {
        if (auto pj = std::dynamic_pointer_cast<ContaPj>(conta)) {
            if (pj->isAtivo() && !pj->isAprovada()) {
                std::cout << "ID: " << pj->getId()
                          << " | Razao Social: " << pj->getRazaoSocial()
                          << " | Saldo: R$" << pj->getSaldo() << std::endl;
                count++;
            }
        }
    }

    if (count == 0) {
        std::cout << "Nenhuma conta PJ pendente de aprovacao.\n";
        return -1;
    }

    int id;
    std::cout << "Digite o ID da conta PJ para aprovar (0 para cancelar): ";
    std::cin >> id;
    if (std::cin.fail()) throw EntradaInvalidaException();

    if (id == 0) return -1;

    for (auto& conta : contas) {
        if (conta->getId() == id && !conta->isAprovada()) {
            if (auto pj = std::dynamic_pointer_cast<ContaPj>(conta)) {
                pj->aprovar();
                pj->definirLimite(15000); 
                std::cout << "Conta PJ ID " << id << " aprovada com sucesso!\n";
                Contas_Liberadas novaConta;
                Calendario novaData;
                novaData.calcular_data();
                novaConta.data = novaData.get_data_formatada();
                novaConta.id = pj->getId();
                liberadas.push_back(novaConta);
                return id;
            }
        }
    }
    throw ContaNaoEncontradaException(id);
}
bool Gerente::autenticacao(std::string cpf, std::string rg, std::string senha){
    if((this->_cpf == cpf) && (this->_rg == rg) && (this->_senha == senha)){
        return true;
    }
    return false;
}
void Gerente::gerar_relatorio(Banco& banco){
    std::string dados="--- Contas Aprovadas ---\n";
    for(const auto& cont: liberadas){
        dados+= "ID: " + std::to_string(cont.id)
        + " | Data: " + cont.data + "\n";
    }
    banco.gerar_relatorio(dados);
}
void Gerente::validar_transacoes(Banco& banco){
    banco.validar_transacoes();
};