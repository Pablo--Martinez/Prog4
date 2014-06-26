#include "RelojSistema.h"

RelojSistema* RelojSistema::instancia = NULL;

RelojSistema* RelojSistema::getInstance(){
	if(instancia == NULL)
		instancia = new RelojSistema();
	return instancia;
}

RelojSistema::RelojSistema() {
	this->fecha_sistema = Fecha();

}

RelojSistema::~RelojSistema() {
	// TODO Auto-generated destructor stub
}

Fecha RelojSistema::getFechaSistema(){
	return this->fecha_sistema;
}

void RelojSistema::modificarFechaSistema(int dia,int mes,int anio,int hora,int min){
	this->fecha_sistema.setDia(dia);
	this->fecha_sistema.setMes(mes);
	this->fecha_sistema.setAnio(anio);
	this->fecha_sistema.setHora(hora);
	this->fecha_sistema.setMinutos(min);
}

