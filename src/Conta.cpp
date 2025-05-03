#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Conta.hpp"
#endif

int Conta::bloquear_conta() {
    if(!_ativo) { 
        return 0;
    }
    _ativo = false;
    return 1;
}

int Conta::ativar_conta() {
    if(_ativo) {  
        return 0;
    }
    _ativo = true;
    return 1;
}