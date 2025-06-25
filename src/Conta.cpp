#include"Conta.hpp"

int Conta::_proximoId = 1;

Conta::Conta(std::shared_ptr<Cliente> titular, double saldoInicial, double limiteInicial)
    : _id(_proximoId++), _saldo(saldoInicial), _limite(limiteInicial),
      _ativo(true), _aprovada(false), _titular(titular) {}

void Conta::depositar(double valor) {
    if (valor > 0) {
        _saldo += valor;
    }
}

bool Conta::sacar(double valor) {
    if (valor > 0 && (_saldo + _limite) >= valor) {
        _saldo -= valor;
        return true;
    }
    return false;
}

void Conta::aprovar() { _aprovada = true; }
void Conta::definirLimite(double novoLimite) {
    if (novoLimite >= 0) {
        _limite = novoLimite;
    }
}

int Conta::getId() const { return _id; }
double Conta::getSaldo() const { return _saldo; }
double Conta::getLimite() const { return _limite; }
bool Conta::isAtivo() const { return _ativo; }
bool Conta::isAprovada() const { return _aprovada; }
std::shared_ptr<Cliente> Conta::getTitular() const { return _titular; }