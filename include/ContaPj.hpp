#pragma once

#include <iostream>
#include <string>

#include "Conta.hpp"
#include "Cliente.hpp"
#include "Calendario.hpp"


class ContaPj : public Conta {
private:
    bool validarCnpj();
    Calendario _dataCriacao;


public:
    ContaPj(std::shared_ptr<Cliente> titular, const std::string& senha, double saldoInicial);

    void bloquear() override;
    void ativar() override;
    std::string getNomeTitular() const override;

    std::string getRazaoSocial() const;
    std::string getCnpj() const;
};