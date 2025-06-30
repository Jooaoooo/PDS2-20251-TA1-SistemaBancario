#pragma once

#include <memory>
#include "Cliente.hpp"

class Conta {
private:
    static int _proximoId;

protected:
    int _id;
    double _saldo;
    double _limite;
    bool _ativo;
    bool _aprovada;
    std::shared_ptr<Cliente> _titular;
    std::string num_cartao;

    Conta(std::shared_ptr<Cliente> titular,int id, double saldoInicial, double limiteInicial);//V

public:
    virtual ~Conta() = default;

    // Métodos virtuais puros
    virtual void bloquear() = 0;
    virtual void ativar() = 0;
    virtual std::string getNomeTitular() const = 0;

    // Métodos de operação
    bool depositar(double valor);//V
    bool sacar(double valor);//V
    void aprovar();//V
    void definirLimite(double novoLimite);//V

    int getId() const;
    double getSaldo() const;
    double getLimite() const;
    bool isAtivo() const;
    bool isAprovada() const;
    std::shared_ptr<Cliente> getTitular() const;
    void set_num_cartao(std::string num);
};