#pragma once

#ifdef _WIN32
    #include".\\ContaPf.hpp"
    #include".\\ContaPj.hpp"
#else
    #include"./ContaPf.hpp"
    #include"./ContaPj.hpp"
#endif
#include<iostream>
class Cliente{
private:
    std::string _nome;
    std::string _cpf;
    std::string _rg;
    std::string _senha;
    std::string _endereco;
    std::string _email;
    std::string _telefone;
public:
    int autenticar_usuario(std::string senha, std::string rg);
    std::string get_dados(int dado);

    void set_nome(const std::string& nome);
    void set_cpf(const std::string& cpf);
    void set_rg(const std::string& rg);
    void set_senha(const std::string& senha);
    void set_endereco(const std::string& endereco);
    void set_email(const std::string& email);
    void set_telefone(const std::string& telefone);

    std::string get_nome() const;
    std::string get_cpf() const;
    std::string get_rg() const;
    std::string get_senha() const;
    std::string get_endereco() const;
    std::string get_email() const;
    std::string get_telefone() const;

};