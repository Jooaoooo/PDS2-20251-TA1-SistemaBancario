#pragma once

#include <chrono>
#include <iostream>
#include <ctime>

/**
 * @struct Calendario
 * @brief armazena informações de Data
 * */
struct Calendario{
	int _dia, _mes, _ano; ///< dia, mês, ano 
	std::string _data; ///< data em formato string ex: 29 de Junho de 2025
	void calcular_data(); ///< recolhe a hora atual
	int get_data(int tipo); ///< getter de data: 0: dia, 1: mês, 2: ano
	std::string get_data(); ///< getter de data em string
	std::string get_data_formatada(); ///< getter de data formatada no formato DD/MM/AAAA 
};