#pragma once

#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Conta.hpp"
#endif
#include <iostream>

class ContaPj:public Conta{

    int validarCnpj();
    int validarSocio();
    int emitirCobraca();
};

//PENDENTE:
/*
-aplicar taxas específicas
-integrar com sistemas contábeis
*/