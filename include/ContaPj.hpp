#pragma once

#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
    #include"..\\include\\Cliente.hpp"
#else
    #include"../include/Conta.hpp"
    #include"../include/Cliente.hpp"
#endif
#include <iostream>
#include <string>

#include "Conta.hpp"

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