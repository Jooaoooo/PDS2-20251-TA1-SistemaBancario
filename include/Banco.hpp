#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Conta.hpp"
#include "Cliente.hpp"

// Estruturas de dados do Banco
struct Transacao {
    std::string data;
    double valor = 0;
    int conta_origem;
    int conta_destino;
    bool aprovada = false;
};

struct Cartao {
    std::string numero;
    int conta_cartao;
    bool bloqueado = false;
};

class Banco {
private:
    std::vector<std::shared_ptr<Conta>> contas;
    std::vector<Transacao> transacoes;
    std::vector<Cartao> cartoes;
    std::vector<std::shared_ptr<Cliente>> clientes;

public:
    int gerenciar_contas();
    int validar_transacoes();
    int bloquear_cartao();
    int gerar_relatorio();
    int realizar_transacoes(int id_destinatario, float valor);//conta origem = 1
    int receber_transacoes(int id_remetente, float valor);//conta recebimentom = 1

    // Getters para acesso controlado aos dados internos
    std::vector<std::shared_ptr<Conta>>& getContas();
    std::vector<Transacao>& getTransacoes();
};