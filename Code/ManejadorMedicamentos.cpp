#include "ManejadorMedicamentos.h"

ManejadorMedicamentos* ManejadorMedicamentos::instancia = NULL;

ManejadorMedicamentos::ManejadorMedicamentos(){}

ManejadorMedicamentos* ManejadorMedicamentos::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorMedicamentos();
	return instancia;
}

//~ManejadorMedicamentos();

void ManejadorMedicamentos::agregarMedicamento(string nombre){
	Medicamento* m = new Medicamento(nombre);
	this->medicamentos.insert(m);
}

Medicamento* ManejadorMedicamentos::find(string nombre){
	//Medicamento* m = new Medicamento(nombre);
	Medicamento m = Medicamento(nombre);
	set<Medicamento*>::iterator it;
	it = this->medicamentos.find(&m);
}

void ManejadorMedicamentos::show(){
	for (set<Medicamento*>::iterator it=this->medicamentos.begin(); it!=this->medicamentos.end(); ++it){
		cout << "-";
		(*it)->show();
	}
}


