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
};