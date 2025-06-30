#pragma once

#include <iostream>
#include <string>

#include "Conta.hpp"
#include "Cliente.hpp"
#include "Calendario.hpp"


class ContaPj : public Conta {
private:
    bool validarCnpj();//V
    Calendario _dataCriacao;


public:
    ContaPj(std::shared_ptr<Cliente> titular, int id, const std::string& senha, double saldoInicial);//V

    void bloquear() override;//V
    void ativar() override;//V
    std::string getNomeTitular() const override;//V

    std::string getRazaoSocial() const;//V
    std::string getCnpj() const;//V
};