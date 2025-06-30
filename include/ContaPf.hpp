#pragma once

#include <iostream>
#include <string>

#include "Conta.hpp"
#include "Cliente.hpp"

/**
 * @Class ContaPf
 * @brief Armazena informações específicas para a conta Pf
 * 
 * armazena informações específicas para a conta Pf como o CPF e a Taxa Selic  
 * */
class ContaPf : public Conta {
private:


    const float _taxaSelic = 0.0125; ///< taxa mensal para o cálculo do tesouro
    
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
    ContaPf(std::shared_ptr<Cliente> titular, int id, const std::string& senha, double saldoInicial = 0.0);//V

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