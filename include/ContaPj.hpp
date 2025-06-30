#pragma once

#include <iostream>
#include <string>

#include "Conta.hpp"
#include "Cliente.hpp"
#include "Calendario.hpp"

/**
 * @Class ContaPj
 * @brief Armazena informações específicas para a conta Pj
 * 
 * armazena informações específicas para a conta Pj como o CNPJ   
 * */
class ContaPj : public Conta {
private:

    /**
     * @brief valida o CNPJ cadastrado da conta Pj
     * @return se o CNPJ é ou não válido
     */
    bool validarCnpj();
    Calendario _dataCriacao; ///< data de criação da conta Pj


public:

    /**
     * @brief Armazena informações iniciais da conta Pj
     * @param titular cliente que possui a conta Pj
     * @param id id da conta Pj
     * @param senha senha da conta Pj
     * @param saldoInicial saldo inicial da conta Pj
     * */
    ContaPj(std::shared_ptr<Cliente> titular, int id, const std::string& senha, double saldoInicial);//V

    /**
     * @brief Método para bloquear a conta Pj
     */
    void bloquear() override;

    /**
     * @brief Método para obter o nome do titular da conta Pj
     * @return nome do titular da conta Pj
     */
    void ativar() override;

    /**
     * @brief Método para obter o nome do titular da conta Pj
     * @return nome do titular da conta Pj
     */
    std::string getNomeTitular() const override;

    /**
     * @brief Método para obter a razão social da conta Pj
     * @return razão social da conta Pj
     */
    std::string getRazaoSocial() const;

    /**
     * @brief Método para obter o CNPJ da conta Pj
     * @return CNPJ da conta Pj
     */
    std::string getCnpj() const;
};