#pragma once

#include "Banco.hpp"
#include "ContaPf.hpp"
#include "ContaPj.hpp"
#include "RelatorioTemplate.hpp"
#include "Cliente.hpp"
#include "Conta.hpp"


#include <string>
#include <vector>

/**
 * @class Gerente
 * @brief Armazena informações do gerente e realiza suas respectivas operações
 * 
 * Possui uma pequena interfaze para manipulações de gerente como
 * aprovar pj, gerar relatórios e validar transações. O gerente 
 * também tem suas informações pessoais e operaç~çoes de autenticação
 * */ 
class Gerente {

/**
 * @struct Contas_Liberadas
 * @brief Armazena informações de contas a serem liberadas
 * */
struct Contas_Liberadas{
    int id; ///< id da conta a ser liberada
    std::string data; ///< data que a conta foi liberada
};
private:
    std::string _nome; ///< nome do gerente
    std::string _cpf; ///< cpf do gerente
    std::string _rg; ///< rg do gerente
    std::string _senha; ///< senha do gerente

public:
    /**
     * @brief Armazena informações iniciais do Gerente
     * @param nome nome do gerente
     * @param cpf cpf do gerente
     * @param rg rg do gerente
     * @param senha senha do gerente
     * */
    Gerente(std::string nome, std::string cpf, std::string rg, std::string senha);
    
    /**
     * @brief Getter do nome do gerente
     * @return Retorna nome do gerente
     * */
    std::string get_nome() const;

    /**
     * @brief Getter do cpf do gerente
     * @return Retorna cpf do gerente
     * */ 
    std::string get_cpf() const;

    /**
     * @brief Getter do rg do gerente
     * @return Retorna rg do gerente
     * */
    std::string get_rg() const;

    /**
     * @brief Interface para execução de ações do gerente
     * 
     * Permite: 
     * >Aprovar conta Pj
     * >Validar transações
     * >Gerar relatório
     * @return Retorna se operação foi bem sucedida
     * */
    int operacoes_gerente(Banco& banco);

    /**
     * @brief Permite o gerente aprovar uma conta Pj
     * @param banco endereço da instância do banco
     * @return Retorna se operação foi bem sucedida
     * */
    int aprovar_pj(Banco& banco);

    /**
     * @brief Gera arquivo de relatório
     * @param banco endereço da instância do banco
     * 
     * Gera arquivo de relatório sorbe as operações realizadas
     * no banco 
     * */
    void gerar_relatorio(Banco& banco);

    /**
     * @brief Permite ao gerente aprovar transações
     * @param banco endereço da instância do banco
     * 
     * Permite ao gerente aprovar transações de valor superior
     * a 5000 reais
     * */
    void validar_transacoes(Banco& banco);

    /**
     * @brief Realiza processo de autenticação do Gerente para login
     * @param cpf Cpf do gerente
     * @param rg Rg do gerente
     * @param senha Senha do gerente
     * @return Retorna se encontrou o gerente com os dados informados
     * */
    bool autenticacao(std::string cpf, std::string rg, std::string senha);//O
    
    std::vector<Contas_Liberadas>liberadas; ///< vector de contas liberadas pelo gerente
};
