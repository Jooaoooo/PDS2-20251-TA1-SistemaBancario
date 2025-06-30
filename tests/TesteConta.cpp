//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Conta.hpp"
#include "ContaPf.hpp" 
#include "Cliente.hpp"
#include "Excecoes.hpp"

TEST_CASE("Criação da conta e acesso a atributos") {
	auto cliente = std::make_shared<Cliente>("João", "12345678900", "MG123456", "senha", "Rua A", "[joao@mail.com](mailto:joao@mail.com)", "31999999999");
	ContaPf conta(cliente, 1, "senha", 0.0);

	CHECK(conta.getSaldo() == 0.0);
	CHECK(conta.getLimite() == 0.0);
	CHECK(conta.isAtivo() == true);
	CHECK(conta.isAprovada() == false);
	CHECK(conta.getTitular() == cliente);
	CHECK(conta.getId() > 0); // ID deve ser positivo
}

TEST_CASE("Depósito com valor válido e inválido") {
	auto cliente = std::make_shared<Cliente>("Maria", "98765432100", "SP123456", "senha", "Rua B", "[maria@mail.com](mailto:maria@mail.com)", "31988888888");
	ContaPf conta(cliente, 1, "senha", 0.0);

	CHECK(conta.depositar(50.0) == true);
	CHECK(conta.getSaldo() == doctest::Approx(50.0));

	CHECK_THROWS_AS(conta.depositar(0.0), EntradaInvalidaException);
	CHECK_THROWS_AS(conta.depositar(-10.0), EntradaInvalidaException);
}

TEST_CASE("Saque com valor válido, inválido e acima do limite") {
	auto cliente = std::make_shared<Cliente>("Carlos", "11122233344", "RJ123456", "senha", "Rua C", "[carlos@mail.com](mailto:carlos@mail.com)", "31977777777");
	ContaPf conta(cliente, 1, "senha", 0.0);

	CHECK_THROWS_AS(conta.sacar(0.0), EntradaInvalidaException);
	CHECK_THROWS_AS(conta.sacar(-10.0), EntradaInvalidaException);
	CHECK_THROWS_AS(conta.sacar(500.0), SaldoInsuficienteException); 
}

TEST_CASE("Definir limite válido e inválido") {
	auto cliente = std::make_shared<Cliente>("Pedro", "88899900011", "PE123456", "senha", "Rua E", "[pedro@mail.com](mailto:pedro@mail.com)", "31955555555");
	ContaPf conta(cliente, 1, "senha", 0.0);

	conta.definirLimite(500.0);
	CHECK(conta.getLimite() == doctest::Approx(500.0));

	CHECK_THROWS_AS(conta.definirLimite(-1.0), EntradaInvalidaException);
}

TEST_CASE("Aprovação da conta") {
	auto cliente = std::make_shared<Cliente>("Ana", "44455566677", "RS123456", "senha", "Rua D", "[ana@mail.com](mailto:ana@mail.com)", "31966666666");
	ContaPf conta(cliente, 1, "senha", 0.0);

	CHECK(conta.isAprovada() == false);
	conta.aprovar();
	CHECK(conta.isAprovada() == true);
}