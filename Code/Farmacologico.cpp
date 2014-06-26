#include "Farmacologico.h"

Farmacologico::Farmacologico(){}

Farmacologico::Farmacologico(string descripcion):Tratamiento(descripcion){}

Farmacologico::~Farmacologico(){}

void Farmacologico::agregarMedicamento(Medicamento* m){
	this->medicamentos[m->getNombre()] = m;
}

map<string,Medicamento*> Farmacologico::getMedicamentos(){
	return this->medicamentos;
}

void Farmacologico::show(){
	if(this != NULL){
		cout << "Descripcion: " << this->getDescripcion() << endl;

		int i=0;
		for (map<string,Medicamento*>::iterator it=this->medicamentos.begin(); it!=this->medicamentos.end(); ++it){
			cout << "Medicamento" << i << ": " << endl;
			it->second->show();
			i++;
		}
	}
}



