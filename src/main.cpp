#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
    #include"..\\include\\Cliente.hpp"
    #include"..\\include\\ContaPf.hpp"
    #include"..\\include\\ContaPj.hpp"
    #include"..\\include\\Banco.hpp"
    #include"..\\include\\Gerente.hpp"
#else
    #include"../include/Conta.hpp"
    #include"../include/Cliente.hpp"
    #include"../include/ContaPf.hpp"
    #include"../include/ContaPj.hpp"
    #include"../include/Banco.hpp"
    #include"../include/Gerente.hpp"
#endif
#include<iostream>

int main(){
    std::cout << "Programa aberto";
    return 0;
}