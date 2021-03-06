#include "DataMedico.h"

DataMedico::DataMedico() {}

DataMedico::~DataMedico() {
	delete this->usuario;
	for(set<DataConsulta*>::iterator it = this->consultas.begin();it != this->consultas.end();++it){
		delete (*it);
	}
	this->consultas.clear();
}

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

void DataMedico::show(){
	if(this != NULL){
		cout << "\tCI: " << this->usuario->getCI() << endl;
		cout << "\tNombre medico: " << this->usuario->getNombre() << " " << this->usuario->getApellido() << endl;
		for(set<DataConsulta*>::iterator it = this->consultas.begin();it!=this->consultas.end();++it){
			(*it)->show();
		}
	}
}
