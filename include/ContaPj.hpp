#pragma once

#ifdef _WIN32
    #include"..\\include\\Conta.hpp"
#else
    #include"../include/Conta.hpp"
#endif
#include <iostream>

class ContaPj:public Conta{

};