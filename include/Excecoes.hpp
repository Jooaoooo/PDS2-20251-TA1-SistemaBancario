// include/Excecoes.hpp
#pragma once
#include <stdexcept>
#include <string>

class ContaNaoEncontradaException : public std::runtime_error {
public:
    ContaNaoEncontradaException(int id) : std::runtime_error("Conta com ID " + std::to_string(id) + " não encontrada.") {}
};

class CartaoNaoEncontradoException : public std::runtime_error {
public:
    CartaoNaoEncontradoException(const std::string& numero) : std::runtime_error("Cartão com número " + numero + " não encontrado.") {}
};
/*
class EntradaInvalidaException : public std::runtime_error {
public:
    EntradaInvalidaException() : std::runtime_error("Entrada inválida.") {}
};*/
class EntradaInvalidaException : public std::runtime_error {
public:
    EntradaInvalidaException(const std::string& msg = "Entrada inválida.") 
        : std::runtime_error(msg) {}
};

class SaldoInsuficienteException : public std::runtime_error {
public:
    SaldoInsuficienteException() : std::runtime_error("Saldo insuficiente para a operação.") {}
};
class GerenteNaoEncontradaException : public std::runtime_error {
public:
    GerenteNaoEncontradaException() : std::runtime_error("Gerente nao encontrado.") {}
};
class ContaNaoAprovada : public std::runtime_error {
public:
    ContaNaoAprovada() : std::runtime_error("Conta nao aprovada.") {}
};