#include"../include/Cliente.hpp"

int Cliente::autenticarUsuario(std::string senha, std::string rg){
    if(this->senha_ != senha){
        return 0;
    }
    if(this->rg_ != rg){
        return 0;
    }
    return 1;
}
