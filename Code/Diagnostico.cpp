#include "Diagnostico.h"

Diagnostico::Diagnostico(){}

Diagnostico::Diagnostico(string codigo, string etiqueta, string descripcion){
	this->codigo = codigo;
	this->etiqueta = etiqueta;
	this->descripcion = descripcion;
}

string Diagnostico::getCodigo(){
	return this->codigo;
}

string Diagnostico::getEtiqueta(){
	return this->etiqueta;
}

string Diagnostico::getDescripcion(){
	return this->descripcion;
}

void Diagnostico::agregarTratamiento(Tratamiento* tratamiento){
	this->tratamientos.push_back(tratamiento);
}

list<Tratamiento*> Diagnostico::getTratamientos(){
	return this->tratamientos;
}

void Diagnostico::show(){
	cout << "Representación: " << this->codigo << this->etiqueta << endl;
	cout << "Descripcion: " << this->descripcion << endl;
	
	list<Tratamiento*>::iterator pos;
	pos = this->tratamientos.begin();
	int i=0;
	while(pos != this->tratamientos.end()){
		cout << "Tratamiento" << i << ": " << endl;
		(*pos)->show();
		pos++;
		i++;
	};
}
