#include "Fecha.h"

Fecha::Fecha(){}

Fecha::Fecha(int dia, int mes, int anio){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
	this->hora = 0;
}

Fecha::Fecha(int dia, int mes, int anio, int hora){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
	this->hora = hora;
}

Fecha::Fecha(Fecha &fecha){
	this->dia = fecha.dia;
	this->mes = fecha.mes;
	this->anio = fecha.anio;
	this->hora = fecha.hora;
}

int Fecha::getDia(){
	return this-> dia;
}

int Fecha::getMes(){
	return this->mes;
}

int Fecha::getAnio(){
	return this->anio;
}

int Fecha::getHora(){
	return this->hora;
}

void Fecha::show(){
	cout << this->dia << "-" << this->mes << "-" << this->anio << " " << this->hora << "hs" << endl;
}