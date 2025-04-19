#pragma once
#include <iostream>

class Conta{
private:
    int id_;
    int saldoBasico_;
    int ativo_;
    int limite_;

    int bloquearConta();
    int ativarConta();
public:
    int gerarId();
    void gerenciarSaldo();//será método puramente abstrato
    void definirLimite();
};
//PENDENTE:
/*
-fornecer dados para extrato
-aplicar tarifas mensais
*/