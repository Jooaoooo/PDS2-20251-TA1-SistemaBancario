#ifdef _WIN32
    #include"..\\include\\Cliente.hpp"
#else
    #include"../include/Cliente.hpp"
#endif
int Cliente::autenticar_usuario(std::string senha, std::string rg){
    if(this->_senha != senha){
        return 0;
    }
    if(this->_rg != rg){
        return 0;
    }
    return 1;
}
std::string Cliente::get_dados(int dado){
    if(dado == 0){//nome
        return this->_nome;
    }else if(dado == 1){//endereço
        return this->_endereco;
    }else if(dado == 2){//email
        return this->_email;
    }else if(dado == 3){//telefone
        return this->_telefone;
    }else{
        exit(1);
    }
}