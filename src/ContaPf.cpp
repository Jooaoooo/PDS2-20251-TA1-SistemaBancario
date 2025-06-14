#ifdef _WIN32
    #include"..\\include\\ContaPf.hpp"
#else
    #include"../include/ContaPf.hpp"
#endif

ContaPf::ContaPf(std::shared_ptr<Cliente> titular, const std::string& senha, double saldoInicial)
    : Conta(titular, saldoInicial, 0.0) { 
    std::cout << "Conta PF criada para " << getNomeTitular() << " com ID " << _id << std::endl;
}

void ContaPf::bloquear() {
    _ativo = false;
    std::cout << "Conta PF ID " << _id << " bloqueada." << std::endl;
}

void ContaPf::ativar() {
    _ativo = true;
    std::cout << "Conta PF ID " << _id << " ativada." << std::endl;
}

std::string ContaPf::getNomeTitular() const {
    return _titular ? _titular->get_nome() : "Não existe";
}

std::string ContaPf::getCpf() const {
    return _titular ? _titular->get_cpf_cnpj() : "Não existe";
}

bool ContaPf::validarCpf() {
    return _titular && !_titular->get_cpf_cnpj().empty();
}