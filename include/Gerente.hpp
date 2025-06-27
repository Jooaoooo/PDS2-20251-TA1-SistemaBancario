#pragma once

#include "Banco.hpp"
#include "ContaPf.hpp"
#include "ContaPj.hpp"
#include "RelatorioTemplate.hpp"
#include "Cliente.hpp"
#include "Conta.hpp"


#include <string>
#include <vector>

class Gerente {
public:
    int aprovar_pj(Banco& banco);
    int liberar_limite(Banco& banco);
    int aprovar_negocio(Banco& banco);
    void gerar_relatorio_customizado(Banco& banco, const std::string& tipo_relatorio, int periodo);
};
