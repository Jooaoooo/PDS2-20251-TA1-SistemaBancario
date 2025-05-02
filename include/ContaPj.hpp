#pragma once

#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
    #include"..\\include\\Cliente.hpp"
#else
    #include"../include/Conta.hpp"
    #include"../include/Cliente.hpp"
#endif
#include <iostream>
#include <string>

class ContaPj:public Conta{
private:
    std::string _razao_social;
    std::string _cnpj;
    std::string _inscricao_estadual;
    std::string _senha;
    std::string _endereco;

    int validar_cnpj();
    int validar_socio();
    int emitir_cobraca();
public:
    // Construtor
    ContaPj() = default;

    // Set e Get para PJ
    void set_razao_social(const std::string& razao_social){ 
        _razao_social = razao_social;
    }
    std::string get_razao_social() const{ 
        return _razao_social; 
    }

    void set_cnpj(const std::string& cnpj){ 
        _cnpj = cnpj; 
    }
    std::string get_cnpj() const{
        return _cnpj; 
    }

    void set_inscricao_estadual(const std::string& ie){ 
        _inscricao_estadual = ie; 
    }
    std::string get_inscricao_estadual() const{ 
        return _inscricao_estadual; 
    }

    void set_senha(const std::string& senha){ 
        _senha = senha; 
    }
    std::string get_senha() const{ 
        return _senha; 
    }

    void set_endereco(const std::string& endereco){ 
        _endereco = endereco; 
    }
    std::string get_endereco() const{ 
        return _endereco; 
    }
};

//PENDENTE:
/*
-aplicar taxas específicas
-integrar com sistemas contábeis
*/