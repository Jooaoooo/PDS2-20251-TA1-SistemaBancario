#ifdef _WIN32
    #include"..\\include\\Cliente.hpp"
#else
    #include"../include/Cliente.hpp"
#endif

#include <cstdlib> 

Cliente::Cliente(std::string nome, std::string cpf_cnpj, std::string rg, std::string senha,
                 std::string endereco, std::string email, std::string telefone)
    : _nome(nome), _cpf_cnpj(cpf_cnpj), _rg(rg), _senha(senha),
      _endereco(endereco), _email(email), _telefone(telefone) {}

bool Cliente::autenticar_usuario(const std::string& senha, const std::string& rg) const {
    return (this->_senha == senha && this->_rg == rg);
}

void Cliente::atualizar_metodos_contato(const std::string& endereco, const std::string& email, const std::string& telefone) {
    this->_endereco = endereco;
    this->_email = email;
    this->_telefone = telefone;
}

std::string Cliente::get_dados(int dado) const {
    switch (dado) {
        case 0: return _nome;
        case 1: return _endereco;
        case 2: return _email;
        case 3: return _telefone;
        case 4: return _cpf_cnpj;
        case 5: return _rg;
        default: return "Dado inválido";
    }
}

// Getters
std::string Cliente::get_nome() const { return _nome; }
std::string Cliente::get_cpf_cnpj() const { return _cpf_cnpj; }
std::string Cliente::get_rg() const { return _rg; }
std::string Cliente::get_senha() const { return _senha; }
std::string Cliente::get_endereco() const { return _endereco; }
std::string Cliente::get_email() const { return _email; }
std::string Cliente::get_telefone() const { return _telefone; }