//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Cliente.hpp"

#include "Excecoes.hpp"

TEST_CASE("Construtor e getters") {
	Cliente c("João", "12345678900", "MG123", "senha123", "Rua A", "[joao@email.com](mailto:joao@email.com)", "99999-0000");

	CHECK(c.get_nome() == "João");
	CHECK(c.get_cpf_cnpj() == "12345678900");
	CHECK(c.get_rg() == "MG123");
	CHECK(c.get_senha() == "senha123");
	CHECK(c.get_endereco() == "Rua A");
	CHECK(c.get_email() == "[joao@email.com](mailto:joao@email.com)");
	CHECK(c.get_telefone() == "99999-0000");
}

TEST_CASE("Autenticação") {
	Cliente c("Maria", "321", "SP456", "minhasenha", "End", "email", "tel");

	CHECK(c.autenticar_usuario("minhasenha", "SP456") == true);
	CHECK_FALSE(c.autenticar_usuario("senhaerrada", "SP456"));

	CHECK_FALSE(c.autenticar_usuario("minhasenha", "MG890"));

}

TEST_CASE("Atualização de métodos de contato") {
	Cliente c("Ana", "789", "RG", "senha", "End1", "email1", "tel1");
	c.atualizar_metodos_contato("End2", "email2", "tel2");

	CHECK(c.get_endereco() == "End2");
	CHECK(c.get_email() == "email2");
	CHECK(c.get_telefone() == "tel2");
}

TEST_CASE("get_dados válido") {
	Cliente c("João", "123", "RG", "senha", "End", "Email", "Tel");

	CHECK(c.get_dados(0) == "João");
	CHECK(c.get_dados(1) == "End");
	CHECK(c.get_dados(2) == "Email");
	CHECK(c.get_dados(3) == "Tel");
	CHECK(c.get_dados(4) == "123");
	CHECK(c.get_dados(5) == "RG");
}

TEST_CASE("get_dados inválido") {
	Cliente c("João", "123", "RG", "senha", "End", "Email", "Tel");

	CHECK_THROWS_AS(c.get_dados(6), EntradaInvalidaException);
	CHECK_THROWS_AS(c.get_dados(-1), EntradaInvalidaException);
}