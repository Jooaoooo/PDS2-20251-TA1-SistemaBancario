#pragma once

#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Conta.hpp"
#endif
#include <iostream>

class ContaPj:public Conta{

    int validar_cnpj();
    int validar_socio();
    int emitir_cobraca();
};

//PENDENTE:
/*
-aplicar taxas específicas
-integrar com sistemas contábeis
*/