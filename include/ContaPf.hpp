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

#pragma once

#include "Conta.hpp"

class ContaPf : public Conta {
private:
    bool validarCpf();

public:
    ContaPf(std::shared_ptr<Cliente> titular, const std::string& senha, double saldoInicial = 0.0);

    void bloquear() override;
    void ativar() override;
    std::string getNomeTitular() const override;

    std::string getCpf() const;
};