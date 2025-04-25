#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Conta.hpp"
#endif

int Conta::gerar_id(){//deve ser modificado
    int id;
    return id;
}
void Conta::gerenciar_saldo(){//deve ser modificado

}
void Conta::definir_limite(){//deve ser modificado

};
int Conta::bloquear_conta(){
    if(this->_ativo == 0){
        return 0;
    }
    this->_ativo = 0;
    return 1;
}
int Conta::ativar_conta(){
    if(this->_ativo != 0){
        return 0;
    }
    this->_ativo = 1;
    return 1;
}