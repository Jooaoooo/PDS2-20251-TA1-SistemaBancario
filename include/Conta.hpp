#pragma once
#include <iostream>

class Conta{
private:
    int _id;
    int _saldoBasico;
    int _ativo;
    int _limite;
    bool _aprovada;  

    int bloquear_conta();
    int ativar_conta();

public:
    int gerar_id();
    void gerenciar_saldo();//será método puramente abstrato
    void definir_limite();

    void set_id(int id){
        _id=id;
    }
    int get_id(){
        return _id;
    }
    void set_saldoBasico(int saldoBasico){
        _saldoBasico=saldoBasico;
    }
    int get_saldoBasico(){
        return _saldoBasico;
    }
    void set_ativo(int ativo){
        _ativo=ativo;
    }
    int get_ativo(){
        return _ativo;
    }
    void set_limite(int limite){
        _limite=limite;
    }
    int get_limite(){
        return _limite;
    }

    void set_aprovada(bool aprovada) { _aprovada = aprovada; }
    bool get_aprovada() { return _aprovada; }
    
};
//PENDENTE:
/*
-fornecer dados para extrato
-aplicar tarifas mensais
*/