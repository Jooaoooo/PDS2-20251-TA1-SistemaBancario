#pragma once

#include <iostream>
#include <string>

#include "Conta.hpp"
#include "Cliente.hpp"


class ContaPj : public Conta {
private:
    bool validarCnpj();

public:
    ContaPj(std::shared_ptr<Cliente> titular, const std::string& senha, double saldoInicial = 0.0);

    void bloquear() override;
    void ativar() override;
    std::string getNomeTitular() const override;

    std::string getRazaoSocial() const;
    std::string getCnpj() const;
};