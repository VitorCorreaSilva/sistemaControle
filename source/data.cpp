#include "data.hpp"

Data::Data(){}

Data::Data(int d, int m, int a){
	dia = d;
	mes = m;
	ano = a;
}

int Data::getDia(){
	return dia;
}

int Data::getMes(){
	return mes;
}

int Data::getAno(){
	return ano;
}

void Data::setDia(int d){
	dia = d;
}

void Data::setMes(int m){
	mes = m;
}

void Data::setAno(int a){
	ano = a;
}

string Data::toString()
{
	string data = to_string(dia) + '/' + to_string(mes) + '/' + to_string(ano);
    return data;
}

Data Data::now(){
	struct tm* dataHoraAtual;
	time_t segundos;
	time(&segundos);   

	dataHoraAtual = localtime(&segundos);  

	Data data(dataHoraAtual->tm_mday, dataHoraAtual->tm_mon + 1, dataHoraAtual->tm_year + 1900);

	return data;
}