#pragma once

#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Conta.hpp"
#endif
#include <iostream>

class ContaPf:public Conta{

    int calcular_tesouro();
    int validar_cpf();
    void gerar_conta_conjunta();
};