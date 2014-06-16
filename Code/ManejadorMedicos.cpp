#include "ManejadorMedicos.h"

ManejadorMedicos* ManejadorMedicos::instancia = NULL;

ManejadorMedicos::ManejadorMedicos(){}

ManejadorMedicos* ManejadorMedicos::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorMedicos();
	return instancia;
}

//~ManejadorMedicamentos();

void ManejadorMedicos::agregarMedico(Medico* m){
	if (this->medicos.find(m->getUsuario()->getCI()) == this->medicos.end()){
		this->medicos[m->getUsuario()->getCI()] = m;
	}
}
Medico* ManejadorMedicos::find(int ci){
	Medico* m = this->medicos[ci];
	return m;
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