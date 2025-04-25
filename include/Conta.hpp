#pragma once
#include <iostream>

class Conta{
private:
    int _id;
    int _saldoBasico;
    int _ativo;
    int _limite;

    int bloquear_conta();
    int ativar_conta();
public:
    int gerar_id();
    void gerenciar_saldo();//será método puramente abstrato
    void definir_limite();
};
//PENDENTE:
/*
-fornecer dados para extrato
-aplicar tarifas mensais
*/