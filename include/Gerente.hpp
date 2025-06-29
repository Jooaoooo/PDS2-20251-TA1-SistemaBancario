#pragma once

#include "Banco.hpp"
#include "ContaPf.hpp"
#include "ContaPj.hpp"
#include "RelatorioTemplate.hpp"
#include "Cliente.hpp"
#include "Conta.hpp"


#include <string>
#include <vector>

class Gerente {


struct Contas_Liberadas{
    int id;
    std::string data;
};
private:
    std::string _nome;
    std::string _cpf;
    std::string _rg;
    std::string _senha;

public:
    Gerente(std::string nome, std::string cpf, std::string rg, std::string senha);
    std::string get_nome() const; 
    std::string get_cpf() const;
    std::string get_rg() const;

    int operacoes_gerente(Banco& banco);
    int aprovar_pj(Banco& banco);
    void gerar_relatorio(Banco& banco);
    void validar_transacoes(Banco& banco);
    bool autenticacao(std::string cpf, std::string rg, std::string senha);
    
    std::vector<Contas_Liberadas>liberadas; 
};
