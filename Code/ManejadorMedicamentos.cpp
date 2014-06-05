#include "ManejadorMedicamentos.h"

ManejadorMedicamentos* ManejadorMedicamentos::instancia = NULL;

ManejadorMedicamentos::ManejadorMedicamentos(){}

ManejadorMedicamentos* ManejadorMedicamentos::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorMedicamentos();
	return instancia;
}
/*
ManejadorMedicamentos::~ManejadorMedicamentos(){
	for (set<Medicamento*>::iterator it=this->medicamentos.begin(); it!=this->medicamentos.end(); ++it){
		this->medicamentos.erase(*it);
		delete *it;
	}
	//delete this->instancia;
	//delete this;
}
*/
void ManejadorMedicamentos::agregarMedicamento(string nombre){
	//Medicamento* m = new Medicamento(nombre);
	//set<Medicamento*>::iterator it;
	//it = this->medicamentos.find(m);
	/*if (*it == NULL){
		this->medicamentos.insert(m);
	}*/
	//this->medicamentos.insert(m);

	if (this->find(nombre) == NULL){
		Medicamento* m = new Medicamento(nombre);
		this->medicamentos.insert(m);
	}
}

Medicamento* ManejadorMedicamentos::find(string nombre){
	//Medicamento* m = new Medicamento(nombre);
	//Medicamento m = Medicamento(nombre);
	set<Medicamento*>::iterator it = this->medicamentos.begin();
	//it = this->medicamentos.find(m);
	while(it != this->medicamentos.end()){
		if((*it)->getNombre() == nombre){
			return *it;
		}
		++it;
	}
	return NULL;
}

void ManejadorMedicamentos::show(){
	if(this != NULL){
		cout << "Medicamentos:" << endl;
		for (set<Medicamento*>::iterator it=this->medicamentos.begin(); it!=this->medicamentos.end(); ++it){
			cout << "-";
			(*it)->show();
		}
	}
}


