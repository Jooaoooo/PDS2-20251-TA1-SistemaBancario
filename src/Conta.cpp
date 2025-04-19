#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Conta.hpp"
#endif

int Conta::gerarId(){//deve ser modificado
    int id;
    return id;
}
void Conta::gerenciarSaldo(){//deve ser modificado

}
void Conta::definirLimite(){//deve ser modificado

};
int Conta::bloquearConta(){
    if(this->ativo_ == 0){
        return 0;
    }
    this->ativo_ = 0;
    return 1;
}
int Conta::ativarConta(){
    if(this->ativo_ != 0){
        return 0;
    }
    this->ativo_ = 1;
    return 1;
}