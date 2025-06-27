#include"ContaPj.hpp"
#include <iostream>
#include "Exceções.hpp"

ContaPj::ContaPj(std::shared_ptr<Cliente> titular, const std::string& senha, double saldoInicial)
    : Conta(titular, saldoInicial, 0.0) { 
    std::cout << "Conta PJ criada para " << getRazaoSocial() << " com ID " << _id << std::endl;
}

void ContaPj::bloquear() {
    _ativo = false;
    std::cout << "Conta PJ ID " << _id << " bloqueada." << std::endl;
}

void ContaPj::ativar() {
    _ativo = true;
    std::cout << "Conta PJ ID " << _id << " ativada." << std::endl;
}

std::string ContaPj::getNomeTitular() const {
    return getRazaoSocial();
}

std::string ContaPj::getRazaoSocial() const {
    if (!_titular) throw ContaNaoEncontradaException(_id);
    return _titular->get_nome();
}

std::string ContaPj::getCnpj() const {
    if (!_titular) throw ContaNaoEncontradaException(_id);
    return _titular->get_cpf_cnpj();
}

bool ContaPj::validarCnpj() {
    return _titular && !_titular->get_cpf_cnpj().empty();
}