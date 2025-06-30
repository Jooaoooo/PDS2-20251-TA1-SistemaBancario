    #include"ContaPf.hpp"
    #include<math.h>
    #include "Excecoes.hpp"

ContaPf::ContaPf(std::shared_ptr<Cliente> titular, int id, const std::string& senha, double saldoInicial)
    : Conta(titular, id, saldoInicial, 0.0) {
        this->_aprovada = true;
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
    if (!_titular) throw ContaNaoEncontradaException(_id);
    return _titular->get_nome();
}

std::string ContaPf::getCpf() const {
    if (!_titular) throw ContaNaoEncontradaException(_id);
    return _titular->get_cpf_cnpj();
}

bool ContaPf::validarCpf() {
    return _titular && !_titular->get_cpf_cnpj().empty();
}
float ContaPf::calcularTesouro(int tempo, float investimento){
    float montante;
    montante = investimento*pow((1+this->_taxaSelic),tempo);
    return montante;
}