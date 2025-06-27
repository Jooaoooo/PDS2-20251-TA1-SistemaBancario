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
struct Saque {
    int id_conta;
    std::string data;
    double valor = 0;
};
struct Deposito {
    int id_conta;
    std::string data;
    double valor = 0;
};

struct Cartao {
    std::string numero;
    int conta_id;
    bool bloqueado = false;
};

class Banco {
private:
    std::vector<std::shared_ptr<Conta>> contas;
    std::vector<Transacao> transacoes;
    std::vector<Cartao> cartoes;
    std::vector<std::shared_ptr<Cliente>> clientes;
    std::vector<Saque> saques;
    std::vector<Deposito> depositos;

public:
    int gerenciar_contas();
    void validar_transacao(Transacao &transacao);
    int validar_transacoes();
    int criar_cartao();
    int bloquear_cartao();
    int gerar_relatorio();
    int realizar_transacao();//conta origem = 1
    int realizar_saque();
    int realizar_deposito();
    int posicao_id(int id);//retorna a posição do ID no vetor contas
    bool verifica_id(int id);
    bool autenticar_conta(int id_conta);
    bool verificar_cartao(int id_conta, const std::string& numero_cartao);

    // Getters para acesso controlado aos dados internos
    std::vector<std::shared_ptr<Conta>>& getContas();
    std::vector<Transacao>& getTransacoes();
};