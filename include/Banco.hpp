#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Conta.hpp"
#include "Cliente.hpp"

// Estruturas de dados do Banco

/**
 * @struct Tansacao
 * @brief armazena informações de transação individual
 * */
struct Transacao {
    std::string data; ///< data de realização
    double valor = 0; ///< valor da transação
    int conta_origem; ///< data 
    int conta_destino; ///< destinatário
    bool aprovada = false; ///< operação aprovada?
};

/**
 * @struct Saque
 * @brief armazena informações de saque individual
 * */
struct Saque {
    int id_conta; ///< id da conta
    std::string data; ///< data da realização
    double valor = 0; ///< data do saque
};

/**
 * @struct Depósito
 * @brief armazena informações de depósito individual
 * */
struct Deposito {
    int id_conta; ///< id da conta
    std::string data; ///< data da realização
    double valor = 0; ///< data do depósito
};

/**
 * @struct Cartão
 * @brief armazena informações de cartão individual
 * */
struct Cartao {
    std::string numero; ///< número do cartão
    int conta_id; ///< id relacionado ao cartão
    bool bloqueado = false; ///< cartão bloqueado?
};

/**
 * @class Banco
 * @brief Contém operações e operações bancárias
 * 
 * Responsável por parte da interfácie do usuário e armazenamento
 *  e manipulação de contas, * cartões, transações, clientes,
 *  saques e depósitos 
 * */
class Banco {
private:
    std::vector<std::shared_ptr<Conta>> contas; ///< contas
    std::vector<Transacao> transacoes; ///< transações
    std::vector<Cartao> cartoes; ///< cartões
    std::vector<std::shared_ptr<Cliente>> clientes; ///< clientes
    std::vector<Saque> saques; ///< saques
    std::vector<Deposito> depositos; ///< depósitos

public:

    /**
     * @brief Interfácie para operações nas contas
     * @return Retorna se a operação foi bem sucedida
     * */
    int gerenciar_contas();

    /**
     * @brief Tem o poder de validar transações
     * 
     * No caso de a transação for de valor menor de 50000, 
     * a transação é aprovada automáticamente, em caso contrário,
     * deve ser aprovada pelo gerente
     * @return Retorna se foi aprovada ou não
     * */
    void validar_transacao(Transacao &transacao);

    /**
     * @brief Permite que o gerente aprove as transações
     * @return Retorna se operações foram bem sucedidas ou não
     * */
    int validar_transacoes();

    /**
     * @brief Permite criação de cartão para determinado ID
     * @return Retorna se operações foram bem sucedidas ou não
     * */
    int criar_cartao();

    /**
     * @brief Bloqueia o cartão do ID informado através do número do mesmo
     * @return Retorna se operações foram bem sucedidas ou não
     * */
    int bloquear_cartao();

    /**
     * @brief Gera relatório geral de operações que ocorreram no banco de feitas pelo gerente
     * @param mudanças feitas pelo gerente
     * @return Retorna se operações foram bem sucedidas ou não
     * */
    int gerar_relatorio(std::string dados);

    /**
     * @brief Permite realizar uma transação de um ID para outro ID
     * @return Retorna se operações foram bem sucedidas ou não
     * */
    int realizar_transacao();
    
    /**
     * @brief Permite realização de saque no ID informado
     * @return Retorna se operações foram bem sucedidas ou não
     * */
    int realizar_saque();

    /**
     * @brief Permite realização de depósito no ID informado
     * @return Retorna se operações foram bem sucedidas ou não
     * */
    int realizar_deposito();

    /**
     * @brief localiza a posição do ID, no vector de contas
     * @return Se encontrado, retorna a posição, caso contrário, emite mensagem de erro
     * */
    int posicao_id(int id);//retorna a posição do ID no vetor contas
    
    /**
     * @brief Verifica a existência de certo ID em contas
     * @return Se ID encontrado, retorna true, caso contrário, mensagem de erro
     * */
    bool verifica_id(int id);

    /**
     * @brief Realiza autenticação da conta com ID informado
     * @return Retorna se operações foram bem sucedidas ou não
     * */
    bool autenticar_conta(int id_conta);

    /**
     * @brief Verifica se o cartão existe e está acossiado à conta escolhida
     * @param id_conta Id da conta que qeur-se analizar
     * @param numero_cartao número do cartão qeu se deseja conferir
     * @return Retorna true, se carão existe e está acossiado à conta, em caso contrário, false
     * */
    bool verificar_cartao(int id_conta, const std::string& numero_cartao);

    /**
     * @brief Permite cliente gerar extrato da conta
     * @param informa Id para realizar extrato
     * @return Retorna se operações foram bem sucedidas ou não
     * */
    void gerar_extrato(int id_conta);
    
    // Getters para acesso controlado aos dados internos
    
    /**
     * @brief Retorna o vector de contas
     * @return Endereço do vector de contas
     * */
    std::vector<std::shared_ptr<Conta>>& getContas();
    
    /**
     * @brief Retorna o vector de transações
     * @return Endereço do vector de transações
     * */
    std::vector<Transacao>& getTransacoes();

    /**
     * @brief Retorna o vector se o vector de Contas está vazio
     * @return Retorna true se estver vazio e false em caso contrário
     * */
    bool isContasEmpty();

    /**
     * @brief Retorna o vector de contas
     * @return Endereço do vector de contas
     * */
    const std::vector<std::shared_ptr<Conta>>& getContas() const;
    
    /**
     * @brief Retorna o tamanho do vector de contas
     * @return Tamanho do vector de contas
     * */
    int contasSize();

};
