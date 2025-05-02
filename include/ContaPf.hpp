#pragma once

#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
    #include"..\\include\\Cliente.hpp"
#else
    #include"../include/Conta.hpp"
    #include"../include/Cliente.hpp"
#endif
#include <iostream>
#include <string>


class ContaPf:public Conta{
private:
    std::string _nome;
    std::string _cpf;
    std::string _rg;
    std::string _senha;
    
    // Métodos privados
    int calcular_tesouro();
    int validar_cpf();
    void gerar_conta_conjunta();
public:
    // Construtor
    ContaPf() = default;
    
    // Setters e Getters específicos para PF
    void set_nome(const std::string& nome) { _nome = nome; }
    std::string get_nome() const { return _nome; }
    
    void set_cpf(const std::string& cpf) { _cpf = cpf; }
    std::string get_cpf() const { return _cpf; }
    
    void set_rg(const std::string& rg) { _rg = rg; }
    std::string get_rg() const { return _rg; }
    
    void set_senha(const std::string& senha) { _senha = senha; }
    std::string get_senha() const { return _senha; }
};