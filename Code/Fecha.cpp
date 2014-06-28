#include "Fecha.h"

Fecha::Fecha(){}

Fecha::Fecha(int dia, int mes, int anio){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
	this->hora = 0;
	this->minutos = 0;
}

Fecha::Fecha(int dia, int mes, int anio, int hora, int minutos){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
	this->hora = hora;
	this->minutos = minutos;
}

Fecha::Fecha(const Fecha &fecha){
	this->dia = fecha.dia;
	this->mes = fecha.mes;
	this->anio = fecha.anio;
	this->hora = fecha.hora;
	this->minutos = fecha.minutos;
}

void Fecha::setDia(int dia){
	this->dia = dia;
}

void Fecha::setMes(int mes){
	this->mes = mes;
}

void Fecha::setAnio(int anio){
	this->anio = anio;
}

void Fecha::setHora(int hora){
	this->hora = hora;
}

void Fecha::setMinutos(int minutos){
	this->minutos = minutos;
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

int Fecha::getMinutos(){
	return this->minutos;
}

bool Fecha::operator ==(const Fecha &f){
	return (this->hora == f.hora && this->dia == f.dia &&
			this->mes == f.mes && this->anio == f.anio);
}

bool Fecha::operator<(const Fecha &f){
	return((this->anio < f.anio) || (this->anio == f.anio && this->mes < f.mes) ||
			(this->anio == f.anio && this->mes == f.mes && this->dia < f.dia) ||
			(this->anio == f.anio && this->mes == f.mes && this->dia == f.dia && this->hora < f.hora));
}

bool Fecha::operator >(const Fecha &f){
	return ((this->anio > f.anio) || (this->anio == f.anio && this->mes > f.mes) ||
			(this->anio == f.anio && this->mes == f.mes && this->dia > f.dia) ||
			(this->anio == f.anio && this->mes == f.mes && this->dia == f.dia && this->hora > f.hora));
}

void Fecha::show(){
	if(this != NULL){
		cout << this->dia << "-" << this->mes << "-" << this->anio << " " << this->hora << "hs" << endl;
	}
}
