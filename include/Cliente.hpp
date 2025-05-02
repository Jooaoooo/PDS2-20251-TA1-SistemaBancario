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

    void set_nome(const std::string& nome){
        _nome=nome;
    }
    std::string get_nome() const{
        return _nome;
    }
    void set_cpf(const std::string& cpf){
        _cpf=cpf;
    }
    std::string get_cpf() const{
        return _cpf;
    }
    void set_rg(const std::string& rg){
        _rg=rg;
    }
    std::string get_rg() const{
        return _rg;
    }
    void set_senha(const std::string& senha){
        _senha=senha;
    }
    std::string get_senha() const{
        return _senha;
    }
    void set_endereco(const std::string& endereco){
        _endereco=endereco;
    }
    std::string get_endereco() const{
        return _endereco;
    }
    void set_email(const std::string& email){
        _email=email;
    }
    std::string get_email() const{
        return _email;
    }
    void set_telefone(const std::string& telefone){
        _telefone=telefone;
    }
    std::string get_telefone() const{
        return _telefone;
    }
};