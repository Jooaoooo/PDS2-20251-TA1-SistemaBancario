#pragma once

#ifdef _WIN32
    #include"..\\include\\Banco.hpp"
    #include"..\\include\\ContaPf.hpp"
    #include"..\\include\\ContaPj.hpp"
    #include"..\\include\\Cliente.hpp"
    #include "..\\include\\RelatorioTemplate.hpp"
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Banco.hpp"
    #include"../include/ContaPf.hpp"
    #include"../include/ContaPj.hpp"
    #include "../include/RelatorioTemplate.hpp"
    #include"../include/Cliente.hpp"
    #include"../include/Conta.hpp"
#endif

#include <string>
#include <vector>

class Gerente {
public:
    int aprovar_pj(Banco& banco);
    int liberar_limite(Banco& banco);
    int aprovar_negocio(Banco& banco);
    void gerar_relatorio_customizado(Banco& banco, const std::string& tipo_relatorio, int periodo);
};
