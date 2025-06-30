#ifndef RELATORIO_UTILS_HPP
#define RELATORIO_UTILS_HPP

#include <iostream>
#include <string>
#include <iomanip>

template <typename T>

void exibirTotal(const std::string& rotulo, T valor) {
    std::cout << rotulo << ": " << valor << std::endl;
}

template <typename T>
void exibirPercentual(const std::string& rotulo, T parte, T total) {
    double percentual = 0.0;
    if (total != 0) {
        percentual = (static_cast<double>(parte) / total) * 100.0;
    }
    std::cout << rotulo << ": " << parte << " (" << std::fixed << std::setprecision(2) << percentual << "%)" << std::endl;
}

template <typename T1, typename T2>
void exibirMedia(const std::string& rotulo, T1 soma, T2 quantidade) {
    double media = 0.0;
    if (quantidade != 0) {
        media = static_cast<double>(soma) / quantidade;
    }
    std::cout << rotulo << ": R$ " << std::fixed << std::setprecision(2) << media << std::endl;
}

#endif 