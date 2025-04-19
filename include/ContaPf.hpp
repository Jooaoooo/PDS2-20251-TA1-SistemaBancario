#pragma once

#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Conta.hpp"
#endif
#include <iostream>

class ContaPf:public Conta{

    int calcularTesouro();
    int validarCpf();
    void gerarContaConjunta();
};