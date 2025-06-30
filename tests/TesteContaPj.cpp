//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "ContaPj.hpp"
#include "Cliente.hpp"
#include "Excecoes.hpp"

TEST_CASE("Criação da ContaPj e atributos iniciais") {
	auto cliente = std::make_shared<Cliente>("Empresa X", "12.345.678/0001-99", "SP123456", "senha", "Av. Central", "[empresa@email.com](mailto:empresa@email.com)", "1130000000");
	ContaPj conta_pj(cliente, 1,  "senha", 5000.0);

	CHECK(conta_pj.getTitular() == cliente);
	CHECK(conta_pj.getSaldo() == doctest::Approx(5000.0));
	CHECK(conta_pj.isAtivo() == true);
	CHECK(conta_pj.isAprovada() == false);
}

TEST_CASE("Ativação e bloqueio da ContaPj") {
	auto cliente = std::make_shared<Cliente>("Empresa Y", "98.765.432/0001-00", "RJ123456", "senha", "Rua Industrial", "[empresaY@email.com](mailto:empresaY@email.com)", "1122222222");
	ContaPj conta_pj(cliente, 1,  "senha", 10000.0);

	conta_pj.bloquear();
	CHECK(conta_pj.isAtivo() == false);

	conta_pj.ativar();
	CHECK(conta_pj.isAtivo() == true);
}

TEST_CASE("Acesso à razão social e CNPJ") {
	auto cliente = std::make_shared<Cliente>("Tech Corp", "55.666.777/0001-11", "MG123456", "senha", "Parque Tecnológico", "[tech@email.com](mailto:tech@email.com)", "1144444444");
	ContaPj conta_pj(cliente, 1, "senha", 8000.0);

	CHECK(conta_pj.getNomeTitular() == "Tech Corp");
	CHECK(conta_pj.getRazaoSocial() == "Tech Corp");
	CHECK(conta_pj.getCnpj() == "55.666.777/0001-11");
}

TEST_CASE("Exceções ao acessar titular nulo em ContaPj") {
	std::shared_ptr<Cliente> nulo;
	ContaPj conta_pj(nulo, 1, "senha", 200.0);

	CHECK_THROWS_AS(conta_pj.getRazaoSocial(), ContaNaoEncontradaException);

	CHECK_THROWS_AS(conta_pj.getCnpj(), ContaNaoEncontradaException);

}