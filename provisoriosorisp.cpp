

#pragma once

#include <iostream>
#include <string>

#include "Conta.hpp"
#include "Cliente.hpp"


class ContaPf : public Conta {
private:
    const float _taxaSelic = 0.0125;///< taxa mensal para o cálculo do tesouro

    /**
     * @brief valida o cpf cadastrado da conta Pf
     * @return se o cpf é ou não válido
     */
    bool validarCpf();

public:

    /**
     * @brief Armazena informações iniciais da conta Pf
     * @param titular cliente que possui a conta Pf
     * @param id id da conta Pf
     * @param senha senha da conta Pf
     * @param saldoInicial saldo inicial da conta Pf inicializado com 0 reais
     * */
    ContaPf(std::shared_ptr<Cliente> titular, int id, const std::string& senha, double saldoInicial = 0.0);

    /**
     * @brief Método para bloquear a conta Pf
     */
    void bloquear() override;

    /**
     * @brief Método para ativar a conta Pf
     */
    void ativar() override;

    /**
     * @brief Método para obter o nome do titular da conta Pf
     * @return nome do titular da conta Pf
     */
    std::string getNomeTitular() const override;

    /**
     * @brief Método para calcular o tesouro com a Taxa Selic
     * @param tempo tempo pelo qual o investimento ficará aplicado
     * @param investimento valor investido
     * @return montante (valor obtido pelo investimento)
     */
    float calcularTesouro(int tempo, float investimento);

    /**
     * @brief Método para obter o CPF do titular da conta Pf
     * @return CPF do titular da conta Pf
     */
    std::string getCpf() const;
};






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
    ContaPj(std::shared_ptr<Cliente> titular, int id, const std::string& senha, double saldoInicial);

    /**
     * @brief Método para bloquear a conta Pj
     */
    void bloquear() override;

    /**
     * @brief Método para ativar a conta Pj
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