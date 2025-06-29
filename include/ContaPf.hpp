#pragma once

#include <iostream>
#include <string>

#include "Conta.hpp"
#include "Cliente.hpp"

class ContaPf : public Conta {
private:
    const float _taxaSelic = 0.0125;//ao mês
    bool validarCpf();

public:
    ContaPf(std::shared_ptr<Cliente> titular, int id, const std::string& senha, double saldoInicial = 0.0);//V

    void bloquear() override;
    void ativar() override;
    std::string getNomeTitular() const override;
    float calcualarTesouro(int tempo, float investimento);
    std::string getCpf() const;
};