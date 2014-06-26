#include "DataMedico.h"

DataMedico::DataMedico() {}

DataMedico::~DataMedico() {}

DataMedico::DataMedico(DataUsuario* du){
	this->usuario = du;
}

void DataMedico::agregarConsulta(DataConsulta* dc){
	this->consultas.insert(dc);
}

DataUsuario* DataMedico::getUsuario(){
	return this->usuario;
}

set<DataConsulta*> DataMedico::getConsultas(){
	return this->consultas;
}
