#pragma once

#include <string>

class Cliente {
private:
    std::string _nome;
    std::string _cpf_cnpj;
    std::string _rg;
    std::string _senha;
    std::string _endereco;
    std::string _email;
    std::string _telefone;

public:
    Cliente(std::string nome, std::string cpf_cnpj, std::string rg, std::string senha,
            std::string endereco, std::string email, std::string telefone);

    bool autenticar_usuario(const std::string& senha, const std::string& rg) const;
    std::string get_dados(int dado) const;
    void atualizar_metodos_contato(const std::string& endereco, const std::string& email, const std::string& telefone);

    // Getters
    std::string get_nome() const;
    std::string get_cpf_cnpj() const;
    std::string get_rg() const;
    std::string get_senha() const;
    std::string get_endereco() const;
    std::string get_email() const;
    std::string get_telefone() const;
};