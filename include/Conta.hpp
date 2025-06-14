#pragma once

#include <memory>
#include "Cliente.hpp"

class Conta {
private:
    static int _proximoId;

protected:
    int _id;
    double _saldo;
    bool _ativo;
    double _limite;
    bool _aprovada;
    std::shared_ptr<Cliente> _titular;

    Conta(std::shared_ptr<Cliente> titular, double saldoInicial, double limiteInicial);

public:
    virtual ~Conta() = default;

    // Métodos virtuais puros
    virtual void bloquear() = 0;
    virtual void ativar() = 0;
    virtual std::string getNomeTitular() const = 0;

    // Métodos de operação
    void depositar(double valor);
    bool sacar(double valor);
    void aprovar();
    void definirLimite(double novoLimite);

    int getId() const;
    double getSaldo() const;
    double getLimite() const;
    bool isAtivo() const;
    bool isAprovada() const;
    std::shared_ptr<Cliente> getTitular() const;
};