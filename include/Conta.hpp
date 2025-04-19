#include <iostream>

class Conta{
private:
    int id_;
    int saldoBasico_;
    int ativo_;

    int bloquearConta();
    int ativarConta();
public:
    int gerarId();
    void gerenciarSaldo();
};