#include "Tratamiento.h"

Tratamiento::Tratamiento(){}

Tratamiento::Tratamiento(string descripcion){
	this->descripcion = descripcion;
}

Tratamiento::~Tratamiento(){}

string Tratamiento::getDescripcion(){
	return this->descripcion;
}

Quirurjico::Quirurjico(){
	this->cirujano = NULL;
}

Quirurjico::Quirurjico(string descripcion,Fecha operacion,Medico* medico):Tratamiento(descripcion){
	this->fecha = operacion;
	this->cirujano = medico;
}

Quirurjico::~Quirurjico(){}

Fecha Quirurjico::getFechaOperacion(){
	return this->fecha;
}

Medico* Quirurjico::getCirujano(){
	return this->cirujano;
}

void Quirurjico::show(){
	cout << "Descripcion: " << this->getDescripcion() << endl;
	cout << "Fecha intervencion: "; this->fecha.show();
	cout << "Cirujano: "; this->cirujano->show();
}

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
