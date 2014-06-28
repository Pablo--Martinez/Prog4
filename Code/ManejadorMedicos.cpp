#include "ManejadorMedicos.h"

ManejadorMedicos* ManejadorMedicos::instancia = NULL;

ManejadorMedicos::ManejadorMedicos(){}

ManejadorMedicos* ManejadorMedicos::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorMedicos();
	return instancia;
}

//ManejadorMedicos::~ManejadorMedicos();

void ManejadorMedicos::agregarMedico(Medico* m){
	if (this->medicos.find(m->getUsuario()->getCI()) != this->medicos.end())
		throw std::invalid_argument("Medico ya existente");

	this->medicos[m->getUsuario()->getCI()] = m;
}
Medico* ManejadorMedicos::find(int ci){
	if(this->medicos.find(ci) != this->medicos.end())
		return this->medicos[ci];
	return NULL;
}

map<int,Medico*> ManejadorMedicos::getMedicos(){
	return this->medicos;
}

void ManejadorMedicos::show(){
	if(this != NULL){
		cout << "Medicos disponibles:" << endl;
		for (map<int,Medico*>::iterator it=this->medicos.begin(); it!=this->medicos.end(); ++it){
			it->second->show();
			cout << "----------------" << endl;
		}
	}
}
