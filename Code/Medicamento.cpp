#include "Medicamento.h"

Medicamento::Medicamento(){}

Medicamento::Medicamento(string nombre){
	this->nombre = nombre;
}

Medicamento::~Medicamento(){
	//delete this->nombre;
}

string Medicamento::getNombre(){
	return this->nombre;
}

void Medicamento::show(){
	if(this != NULL){
		cout << "Nombre: " << this->nombre << endl;
	}
}
