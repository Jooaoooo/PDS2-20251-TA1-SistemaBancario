#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Conta.hpp"
#include "Cliente.hpp"
#include "RelatorioTemplate.hpp"

// Estruturas usadas pela classe Banco
struct Transacao {
    std::string data;
    double valor;
    int conta_origem;
    int conta_destino;
    bool aprovada = false; 
};

struct Cartao {
    std::string numero;
    int conta_cartao;
    bool bloqueado;
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
    int processar_folha_pagamento();
    std::vector<Transacao>& get_transacoes(); 
};