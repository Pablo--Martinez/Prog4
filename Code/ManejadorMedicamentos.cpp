#include "ManejadorMedicamentos.h"

ManejadorMedicamentos* ManejadorMedicamentos::instancia = NULL;

ManejadorMedicamentos::ManejadorMedicamentos(){}

ManejadorMedicamentos* ManejadorMedicamentos::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorMedicamentos();
	return instancia;
}

ManejadorMedicamentos::~ManejadorMedicamentos(){
	for(map<string,Medicamento*>::iterator it = this->medicamentos.begin();it != this->medicamentos.end();++it){
		delete (it->second);
	}
	this->medicamentos.clear();
}

void ManejadorMedicamentos::ingresarMedicamento(){
	if (this->medicamentos.find(this->nombre) != this->medicamentos.end())
		throw std::invalid_argument("Medicamento ya existente");

		Medicamento* m = new Medicamento(this->nombre);
	this->medicamentos[this->nombre] = m;
}

Medicamento* ManejadorMedicamentos::find(string nombre){
	if(this->medicamentos.find(nombre) != this->medicamentos.end())
		return this->medicamentos[nombre];
	return NULL;
}

bool ManejadorMedicamentos::existeMedicamento(string nombre){
	this->nombre = nombre;
	return (this->medicamentos.find(nombre) != this->medicamentos.end());
}

void ManejadorMedicamentos::show(){
	if(this != NULL){
		cout << "Medicamentos:" << endl;
		for (map<string,Medicamento*>::iterator it=this->medicamentos.begin(); it!=this->medicamentos.end(); ++it){
			cout << "-";
			it->second->show();
		}
	}
}


