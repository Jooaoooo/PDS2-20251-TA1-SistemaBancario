#include "Calendario.hpp"

void Calendario::calcular_data(){
	auto agora = std::chrono::system_clock::now();
	std::time_t tempoAtual = std::chrono::system_clock::to_time_t(agora);
	std::tm* dataHora = std::localtime(&tempoAtual);

	this->_ano = 1900 + dataHora->tm_year;
	this->_mes = 1 + dataHora->tm_mon;
	this->_dia = 1 + dataHora->tm_mday;

	this->_data = "";
	this->_data += this->_dia;
	this->_data += " ";
	switch(this->_mes){
		case 1:
			this->_data += "Janeiro ";
			break;
		case 2:
			this->_data += "Fevereiro ";
			break;
		case 3:
			this->_data += "Março ";
			break;
		case 4:
			this->_data += "Abril ";
			break;
		case 5:
			this->_data += "Maio ";
			break;
		case 6:
			this->_data += "junho ";
			break;
		case 7:
			this->_data += "Julho ";
			break;
		case 8:
			this->_data += "Agosto ";
			break;
		case 9:
			this->_data += "Setembro ";
			break;
		case 10:
			this->_data += "Outubro ";
			break;
		case 11:
			this->_data += "Novembro ";
			break;
		case 12:
			this->_data += "Dezembro ";
			break;
	}
	this->_data += this->_ano;
}
int Calendario::get_data(int tipo){
	switch(tipo){
		case 0:
			return this->_dia;
		case 1:
			return this->_mes;
		case 2:
			return this->_ano;
		default:
			//error
			exit(1);//provisório
			//break;
	}
}
std::string Calendario::get_data(){
	return this->_data;
}
