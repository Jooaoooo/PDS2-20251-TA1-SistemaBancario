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

#include<iostream>
#include<vector>
#include<string>

class Gerente{
    public:
        // Métodos básicos de aprovação
        int aprovar_pj();
        int liberar_limite();
        int aprovar_negocio(); 

        // Funcionalidades pendentes implementadas
        bool auditar_transacoes_suspeitas(const std::vector<int>& transacoes);
        void gerar_relatorio_customizado(const std::string& tipo_relatorio, int periodo);
};
