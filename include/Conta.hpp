#pragma once
#include <iostream>

class Conta {
private:
    int _id;
    int _saldoBasico;
    bool _ativo;  // Alterado para bool
    int _limite;
    bool _aprovada;

    virtual int bloquear_conta();
    virtual int ativar_conta();

public:
    virtual ~Conta() = default;
    
    // Métodos que devem ser implementados pelas classes derivadas
    virtual int gerar_id() = 0;  
    virtual void gerenciar_saldo() = 0;  
    virtual void definir_limite() = 0;  

    // Getters e Setters
    virtual void set_id(int id) { _id = id; }
    virtual int get_id() const { return _id; }
    
    virtual void set_saldoBasico(int saldoBasico) { _saldoBasico = saldoBasico; }
    virtual int get_saldoBasico() const { return _saldoBasico; }
    
    virtual void set_ativo(bool ativo) { _ativo = ativo; }  // Alterado para bool
    virtual bool get_ativo() const { return _ativo; }  // Alterado para bool
    
    virtual void set_limite(int limite) { _limite = limite; }
    virtual int get_limite() const { return _limite; }
    
    virtual void set_aprovada(bool aprovada) { _aprovada = aprovada; }
    virtual bool get_aprovada() const { return _aprovada; }
};
