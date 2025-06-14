// include/RelatorioUtils.hpp
#ifndef RELATORIO_UTILS_HPP
#define RELATORIO_UTILS_HPP

#include <iostream>
#include <string>

template <typename T>
void exibirTotal(const std::string& rotulo, T valor) {
    std::cout << rotulo << ": " << valor << std::endl;
}

template <typename T>
void exibirPercentual(const std::string& rotulo, T parte, T total) {
    double percentual = 0;
    if (total != 0) {
        percentual = static_cast<double>(parte) * 100 / total;
    }
    std::cout << rotulo << ": " << parte << " (" << percentual << "%)" << std::endl;
}

template <typename T1, typename T2>
void exibirMedia(const std::string& rotulo, T1 soma, T2 quantidade) {
    double media = 0;
    if (quantidade != 0) {
        media = static_cast<double>(soma) / quantidade;
    }
    std::cout << rotulo << ": R$ " << media << std::endl;
}

#endif // RELATORIO_UTILS_HPP
