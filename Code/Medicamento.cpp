#include "Medicamento.h"

Medicamento::Medicamento(){}

Medicamento::Medicamento(string nombre){
	this->nombre = nombre;
}

string Medicamento::getNombre(){
	return this->nombre;
}

void Medicamento::show(){
	cout << "Nombre: " << this->nombre << endl;
}
