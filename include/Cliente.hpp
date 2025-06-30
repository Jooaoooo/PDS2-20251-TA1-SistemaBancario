#pragma once

#include <string>

/**
 * @Class Cliente
 * @brief armazena informações do cliente
 * 
 * Armazena informações do cliente como nome, cpf, rg, 
 * senha, endereço, e-mail e telefone
 * */
class Cliente {
private:
    std::string _nome; ///< nome do cliente
    std::string _cpf_cnpj; ///< cpf do cliente
    std::string _rg; ///< rg do cliente
    std::string _senha; ///< senha do cliente
    std::string _endereco; ///< endreço do cliente
    std::string _email; ///< e-mail de contato do cliente
    std::string _telefone; ///< telefone de contato do cliente

public:

    /**
     * @brief Armazena informações iniciais de Cliente
     * @param nome nome do cliente
     * @param cpf_cnpf cpf ou cnpj do cliente
     * @param rg rg do cliente
     * @param senha senha do cliente
     * @param endereco endereço do cliente
     * @param email e-mail do cliente
     * @param telefone telefone do cliente
     * */
    Cliente(std::string nome, std::string cpf_cnpj, std::string rg, std::string senha,
            std::string endereco, std::string email, std::string telefone);

    /**
     * @brief Realiza verificação se é de fato o usuário com dados pessoais
     * @return Retorna se a operação foi bem sucedida
     * */
    bool autenticar_usuario(const std::string& senha, const std::string& rg) const;
    
    /**
     * @brief informa um dado desejado
     * @param dado que deseja obter
     * 
     * parâmetros podem ser:
     *  0: nome
     *  1: endereço
     *  2: e-mail
     *  3: telefone
     *  4: cpf/cnpj
     *  5: rg
     * @return Retorna a informação desejada
     * */
    std::string get_dados(int dado) const;

    /**
     * @brief Atualiza informações de contato
     * @param endereco endereço
     * @param email e-mail
     * @param telefone telefone
     * 
     * As informações são endereço, e-mail e telefone
     * */
    void atualizar_metodos_contato(const std::string& endereco, const std::string& email, const std::string& telefone);

    // Getters
    
    /**
     * @brief Retorna nome
     * @return Nome
     * */
    std::string get_nome() const;
    
    /**
     * @brief Retorna cpf/cnpj
     * @return Cpf/Cnpj
     * */
    std::string get_cpf_cnpj() const;
    
    /**
     * @brief Retorna rg
     * @return Rg
     * */
    std::string get_rg() const;
    
    /**
     * @brief Retorna senha
     * @return Senha
     * */
    std::string get_senha() const;
    
    /**
     * @brief Retorna endereço
     * @return Endereço
     * */
    std::string get_endereco() const;
    
    /**
     * @brief Retorna e-mail
     * @return E-mail
     * */
    std::string get_email() const;
    
    /**
     * @brief Retorna telefone
     * @return Telefone
     * */
    std::string get_telefone() const;
};