#ifdef _WIN32
    #include"..\\include\\Cliente.hpp"
#else
    #include"../include/Cliente.hpp"
#endif
int Cliente::autenticarUsuario(std::string senha, std::string rg){
    if(this->senha_ != senha){
        return 0;
    }
    if(this->rg_ != rg){
        return 0;
    }
    return 1;
}
std::string Cliente::getDados(int dado){
    if(dado == 0){//nome
        return this->nome_;
    }else if(dado == 1){//endereço
        return this->endereco_;
    }else if(dado == 2){//email
        return this->email_;
    }else if(dado == 3){//telefone
        return this->telefone_;
    }else{
        exit(1);
    }
}