//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Gerente.hpp"

TEST_CASE("Gerente - Autenticação correta e incorreta") {
	Gerente g("Fulano", "12345678900", "1234567", "senhaSegura");

	CHECK(g.autenticacao("12345678900", "1234567", "senhaSegura") == true);
	CHECK(g.autenticacao("12345678900", "1234567", "senhaErrada") == false);

	CHECK(g.autenticacao("cpfErrado", "1234567", "senhaSegura") == false);
}

TEST_CASE("Gerente - Construtor") {
	Gerente g("Fulano", "12345678900", "RG1234", "senhaSegura");

	CHECK(g.get_nome() == "Fulano");
	CHECK(g.get_cpf() == "12345678900");
	CHECK(g.get_rg() == "RG1234");

}