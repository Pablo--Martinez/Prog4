#include "DataHistorial.h"

DataHistorial::DataHistorial() {}

DataHistorial::DataHistorial(DataUsuario* du){
	this->usuario = du;
}

DataHistorial::~DataHistorial() {}

void DataHistorial::agregarMedico(DataMedico* dm){
	this->medico.insert(dm);
}

DataUsuario* DataHistorial::getUsuario(){
	return this->usuario;
}

set<DataMedico*> DataHistorial::getMedicos(){
	return this->medico;
}