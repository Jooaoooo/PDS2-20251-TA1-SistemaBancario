#pragma once

#include <chrono>
#include <iostream>
#include <ctime>

struct Calendario{
	int _dia, _mes, _ano;
	std::string _data;
	void calcular_data();//inteiro
	int get_data(int tipo);//0: dia, 1: mes, 2: ano;
	std::string get_data();//string
};