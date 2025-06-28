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
private:
    std::string _nome;
    std::string _cpf;
    std::string _rg;
    std::string _senha;

public:
    Gerente(std::string nome, std::string cpf, std::string rg, std::string senha);
    int operacoes_gerente(Banco& banco);
    int aprovar_pj(Banco& banco);
    //int liberar_limite(Banco& banco);
    //int aprovar_negocio(Banco& banco);
    void gerar_relatorio_customizado(Banco& banco, const std::string& tipo_relatorio, int periodo);
    bool autenticacao(std::string cpf, std::string rg, std::string senha);
    //void mostrar();
    std::string get_nome();
};
