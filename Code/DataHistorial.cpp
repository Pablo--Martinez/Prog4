#include "DataHistorial.h"

DataHistorial::DataHistorial() {}

DataHistorial::~DataHistorial() {
	delete this->usuario;
	for(set<DataMedico*>::iterator it = this->medico.begin();it != this->medico.end();++it){
		delete (*it);
	}
	this->medico.clear();
}

DataHistorial::DataHistorial(DataUsuario* du){
	this->usuario = du;
}

void DataHistorial::agregarMedico(DataMedico* dm){
	this->medico.insert(dm);
}

DataUsuario* DataHistorial::getUsuario(){
	return this->usuario;
}

set<DataMedico*> DataHistorial::getMedicos(){
	return this->medico;
}

void DataHistorial::show(){
	if(this != NULL){
		for(set<DataMedico*>::iterator it = this->medico.begin();it != this->medico.end();++it){
			(*it)->show();
		}
	}
}
