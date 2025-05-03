#ifdef _WIN32
    #include"..\\include\\Cliente.hpp"
#else
    #include"../include/Cliente.hpp"
#endif

int Cliente::autenticar_usuario(std::string senha, std::string rg){
    if(this->_senha != senha){
        return 0;
    }
    if(this->_rg != rg){
        return 0;
    }
    return 1;
}

std::string Cliente::get_dados(int dado) {
    switch(dado) {
        case 0: return _nome;
        case 1: return _endereco;
        case 2: return _email;
        case 3: return _telefone;
        case 4: return _cpf;
        case 5: return _rg;
        default: 
            exit(1);
    }
}

// Setters
void Cliente::set_nome(const std::string& nome) { _nome = nome; }
void Cliente::set_cpf(const std::string& cpf) { _cpf = cpf; }
void Cliente::set_rg(const std::string& rg) { _rg = rg; }
void Cliente::set_senha(const std::string& senha) { _senha = senha; }
void Cliente::set_endereco(const std::string& endereco) { _endereco = endereco; }
void Cliente::set_email(const std::string& email) { _email = email; }
void Cliente::set_telefone(const std::string& telefone) { _telefone = telefone; }

// Getters
std::string Cliente::get_nome() const { return _nome; }
std::string Cliente::get_cpf() const { return _cpf; }
std::string Cliente::get_rg() const { return _rg; }
std::string Cliente::get_senha() const { return _senha; }
std::string Cliente::get_endereco() const { return _endereco; }
std::string Cliente::get_email() const { return _email; }
std::string Cliente::get_telefone() const { return _telefone; }

std::string Cliente::atualizar_metodos_contato(std::string endereco, std::string email, std::string telefone){
    this->set_endereco(endereco);
    this->set_email(email);
    this->set_telefone(telefone);
}