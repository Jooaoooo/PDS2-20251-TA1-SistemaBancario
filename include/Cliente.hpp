#include<iostream>
#include"./ContaPf.hpp"
#include"./ContaPj.hpp"
class Cliente{
private:
    std::string nome_;
    std::string cpf_;
    std::string rg_;
    std::string senha_;
    std::string endereco_;
    std::string email_;
    std::string telefone_;
public:
    int autenticarUsuario(std::string senha, std::string rg);
    std::string getDados(int dado);
};