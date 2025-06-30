//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cmath>
#include "ContaPf.hpp"
#include "Cliente.hpp"
#include "Excecoes.hpp"

TEST_CASE("Criação de ContaPf e atributos iniciais") {
	auto cliente = std::make_shared<Cliente>("João", "12345678900", "MG123456", "senha", "Rua A", "[joao@mail.com](mailto:joao@mail.com)", "31999999999");
	ContaPf conta_pf(cliente, 1, "senha", 1000.0);

	CHECK(conta_pf.getTitular() == cliente);
	CHECK(conta_pf.getSaldo() == doctest::Approx(1000.0));
	CHECK(conta_pf.isAtivo() == true);
	CHECK(conta_pf.isAprovada() == false);

	CHECK (conta_pf.getId() > 0);
}

TEST_CASE("Ativação e bloqueio da ContaPf") {
	auto cliente = std::make_shared<Cliente>("Maria", "98765432100", "SP123456", "senha", "Rua B", "[maria@mail.com](mailto:maria@mail.com)", "31988888888");
	ContaPf conta_pf(cliente, 1, "senha", 500.0);

	conta_pf.bloquear();
	CHECK(conta_pf.isAtivo() == false);

	conta_pf.ativar();
	CHECK(conta_pf.isAtivo() == true);
}

TEST_CASE("Acesso ao nome e CPF do titular") {
	auto cliente = std::make_shared<Cliente>("Carlos", "11122233344", "RJ123456", "senha", "Rua C", "[carlos@mail.com](mailto:carlos@mail.com)", "31977777777");
	ContaPf conta_pf(cliente, 1, "senha", 200.0);

	CHECK(conta_pf.getNomeTitular() == "Carlos");
	CHECK(conta_pf.getCpf() == "11122233344");
}


TEST_CASE("Cálculo do Tesouro Direto com taxa Selic") {
	auto cliente = std::make_shared<Cliente>("Pedro", "88899900011", "PE123456", "senha", "Rua E", "[pedro@mail.com](mailto:pedro@mail.com)", "31955555555");
	ContaPf conta_pf(cliente, 1, "senha", 1000.0);

	float investimento = 1000.0f;
	int tempo = 6;
	float taxaMensal = 0.0125f;

	float esperado = investimento * std::pow(1 + taxaMensal, tempo);
	float montante = conta_pf.calcularTesouro(tempo, investimento);

CHECK(montante == doctest::Approx(esperado).epsilon(0.001)); // tolerância de ~0.1%
}