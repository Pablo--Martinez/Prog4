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
	if (this->medicamentos.find(nombre) != this->medicamentos.end())
		throw std::invalid_argument("Medicamento ya existente");

		Medicamento* m = new Medicamento(nombre);
	this->medicamentos[nombre] = m;
}

Medicamento* ManejadorMedicamentos::find(string nombre){
	////Medicamento* m = new Medicamento(nombre);
	//Medicamento m = Medicamento(nombre);
	//map<string,Medicamento*>::iterator it = this->medicamentos.begin();
	//it = this->medicamentos.find(m);
	//while(it != this->medicamentos.end()){
	//	if((*it)->getNombre() == nombre){
	//		return *it;
	//	}
	//	++it;
	//}//
	if(this->medicamentos[nombre] == NULL)
		return this->medicamentos[nombre];
	return NULL;
}

bool ManejadorMedicamentos::existeMedicamento(string nombre){
	return this->medicamentos[nombre] != NULL;
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


