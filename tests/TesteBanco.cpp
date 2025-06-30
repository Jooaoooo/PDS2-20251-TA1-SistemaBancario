#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Banco.hpp"
#include "ContaPf.hpp"
#include "ContaPj.hpp"
#include "Cliente.hpp"
#include "Excecoes.hpp"

TEST_CASE("Validar transações com valor limite") {
	Banco banco;
	Transacao t1;
	t1.conta_origem = 1;
	t1.conta_destino = 2;
	t1.valor = 3000;
	t1.data = "01/01/2024";
	t1.aprovada = false;

	Transacao t2;
	t2.conta_origem = 1;
	t2.conta_destino = 2;
	t2.valor = 7000;
	t2.data = "01/01/2024";
	t2.aprovada = false;

	banco.validar_transacao(t1);
	banco.validar_transacao(t2);

	CHECK(t1.aprovada == true);
	CHECK(t2.aprovada == false);
}

TEST_CASE("Banco::posicao_id retorna índice correto") {
	Banco banco;

	auto cliente1 = std::make_shared<Cliente>("João", "12345678900", "RG1", "senha1", "Rua A", "[joao@email.com](mailto:joao@email.com)", "99999-0000");
	auto cliente2 = std::make_shared<Cliente>("Maria", "98765432100", "RG2", "senha2", "Rua B", "[maria@email.com](mailto:maria@email.com)", "88888-0000");

	auto conta1 = std::make_shared<ContaPf>(cliente1, 1, "senha1");
	auto conta2 = std::make_shared<ContaPf>(cliente2, 2, "senha2");

	banco.getContas().push_back(conta1); // índice 0
	banco.getContas().push_back(conta2); // índice 1

	CHECK(banco.posicao_id(1) == 0);
	CHECK(banco.posicao_id(2) == 1);
}

TEST_CASE("Banco - getContas retorna as contas corretamente") {
	Banco banco;

	 auto cliente = std::make_shared<Cliente>("Ana", "12345678901", "MG123", "senha123", "Rua X", "[ana@email.com](mailto:ana@email.com)", "31999999999");

	auto conta = std::make_shared<ContaPf>(cliente, 1234, "minhasenha", 100.0);

	banco.getContas().push_back(conta);

	CHECK(banco.getContas().size() == 1);

	CHECK(banco.getContas()[0]->getTitular()->get_nome() == "Ana");
}

TEST_CASE("Banco - getTransacoes permite adicionar e acessar transações") {
	Banco banco;

	Transacao t;
	t.conta_origem = 1;
	t.conta_destino = 2;
	t.valor = 300;
	t.data = "01/01/2025";
	t.aprovada = true;

	banco.getTransacoes().push_back(t);

	CHECK(banco.getTransacoes().size() == 1);

	CHECK(banco.getTransacoes()[0].valor == 300);
	CHECK(banco.getTransacoes()[0].aprovada == true);
}

TEST_CASE("Validar múltiplas transações") {
	Banco banco;
	Transacao t1;
	t1.conta_origem = 1;
	t1.conta_destino = 2;
	t1.valor = 3000;
	t1.data = "01/01/2024";
	t1.aprovada = false;

	Transacao t2;
	t2.conta_origem = 1;
	t2.conta_destino = 2;
	t2.valor = 7000;
	t2.data = "01/01/2024";
	t2.aprovada = false;

	banco.getTransacoes().push_back(t1);
	banco.getTransacoes().push_back(t2);

	int aprovadas = banco.validar_transacoes();

	CHECK(aprovadas == 1);

	CHECK(banco.getTransacoes()[0].aprovada == true);
	CHECK(banco.getTransacoes()[1].aprovada == false);
}

TEST_CASE("verifica_id lança exceção se o ID não existir") {
	Banco banco;

	CHECK_THROWS_AS(banco.verifica_id(999), CartaoNaoEncontradoException);
}

TEST_CASE("verifica_id retorna true para conta existente") {
	Banco banco;

	auto cliente = std::make_shared<Cliente>("João", "12345678900", "RG1", "1234", "Rua A", "[joao@email.com](mailto:joao@email.com)", "99999-0000");
	auto conta = std::make_shared<ContaPf>(cliente, 1, "1234");

	banco.getContas().push_back(conta);

	CHECK(banco.verifica_id(1) == true);
}