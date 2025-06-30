#pragma once

#include <memory>
#include "Cliente.hpp"


/**
 * @Class Conta
 * @brief Armazena informações da conta
 * 
 * armazena informações da conta como saldo, limite e número do cartão
 * */
class Conta {
private:
    static int _proximoId; ///< utilizado na configuração dos ids das contas

protected:
    int _id; ///< id da conta
    double _saldo; ///< saldo da conta
    double _limite; ///< limite da conta
    bool _ativo; ///< diz se a conta está ou não ativa
    bool _aprovada; ///< diz se a conta está ou não aprovada
    std::shared_ptr<Cliente> _titular; ///< cliente que possui a conta
    std::string num_cartao; ///< número do cartão da conta do cliente

    /**
     * @brief Armazena informações iniciais da conta
     * @param titular cliente que possui a conta
     * @param id id da conta
     * @param saldoInicial saldo inicial da conta
     * @param limiteInicial limite inicial da conta
     * */
    Conta(std::shared_ptr<Cliente> titular,int id, double saldoInicial, double limiteInicial);//V

public:

    /**
     * @brief Destrutor padrão da classe Conta
     */
    virtual ~Conta() = default;

    // Métodos virtuais puros

    /**
     * @brief Método virtual puro para bloquear a conta
     */
    virtual void bloquear() = 0;

    /**
     * @brief Método virtual puro para ativar a conta
     */
    virtual void ativar() = 0;

    /**
     * @brief Método virtual puro para obter o nome do titular da conta
     * @return nome do titular da conta
     */
    virtual std::string getNomeTitular() const = 0;

    // Métodos de operação

    /**
     * @brief Realiza um depósito
     * @param valor Valor a ser depositado
     * @return se o depósito foi realizado com sucesso
     * */
    bool depositar(double valor);

    /**
     * @brief Realiza um saque
     * @param valor Valor a ser sacado
     * @return se o saque foi realizado com sucesso
     * */
    bool sacar(double valor);

    /**
     * @brief Aprova a conta
     * */
    void aprovar();

    /**
     * @brief Define um novo limite para a conta
     * @param novoLimite Valor a ser definido como novo limite da conta
     * */
    void definirLimite(double novoLimite);

    /**
     * @brief Retorna id da conta
     * @return id
     * */
    int getId() const;

    /**
     * @brief Retorna saldo da conta
     * @return saldo
     * */
    double getSaldo() const;

    /**
     * @brief Retorna limite da conta
     * @return limite
     * */
    double getLimite() const;

    /**
     * @brief Retorna se a conta está ou não ativa
     * @return Retorna se a conta está ou não ativa
     * */
    bool isAtivo() const;

    /**
     * @brief Retorna se a conta está ou não aprovada
     * @return Retorna se a conta está ou não aprovada
     * */
    bool isAprovada() const;

    /**
     * @brief Retorna o nome do titulardaconta
     * @return Nome do titular da conta
     * */
    std::shared_ptr<Cliente> getTitular() const;

    /**
     * @brief Define o número do cartão
     * @param num Numero do cartão a ser definido
     * */
    void set_num_cartao(std::string num);
};