#include "Empresa.h"

using namespace std;

Empresa::Empresa(char* nombre, char* nombre_legal, int rut) {

	this->nombre = new char;
	this->nombre_legal = new char;

	strcpy(this->nombre,nombre);
	strcpy(this->nombre_legal,nombre_legal);
	if(rut >= 0)
		this->rut = rut;
	else
		throw std::invalid_argument("RUT invalido");

	this->empleados = new Empleado*[MAX_EMPLEADO];

	for (int i=0; i<MAX_EMPLEADO; i++)
		this->empleados[i] = NULL;
}

Empresa::~Empresa() {
	delete[] this->empleados;
    delete this->nombre;
    delete this->nombre_legal;
}

char* Empresa::get_nombre() {
	return this->nombre;
}

char* Empresa::get_nombre_legal() {
	return this->nombre_legal;
}

int Empresa::get_rut() {
	return this->rut;
}

Paga Empresa::total_sueldo_peso() {
	Paga p;
	for(int i=0;i<MAX_EMPLEADO;i++){
		if(this->empleados[i] != NULL){
			p = p + this->empleados[i]->get_sueldo_peso();
		}
	}
	return p;
}

Paga Empresa::total_sueldo_dolar() {
	Paga p;
	p = p.a_dolar();
	for(int i=0;i<MAX_EMPLEADO;i++){
		if(this->empleados[i] != NULL){
			p = p + this->empleados[i]->get_sueldo_dolar();
		}
	}
	return p;
}

void Empresa::agregar_empleado(Empleado* e) {
	int i;
	for (i = 0; i<MAX_EMPLEADO; i++) {
		if (this->empleados[i] == NULL) {
			this->empleados[i] = e;
			break;
		}
	}
	if (i == MAX_EMPLEADO) {
		throw std::invalid_argument("Max empleados completo");
	}

}

void Empresa::imprimir_empleados() {
	int i;
    cout << "Empleados: " << endl;
	for (i = 0; i<MAX_EMPLEADO; i++) {
		if (this->empleados[i] != NULL) {
			cout << this->empleados[i] << endl;
			cout << "--------------------------" << endl;
		}
	}
}

ostream& operator<<(ostream &o, Empresa &e){
	o << "Empresa: \n";
	o << "\tNombre: " << e.get_nombre() << endl;
	o << "\tNombre legal: " << e.get_nombre_legal() << endl;
	o << "\tRUT: " << e.get_rut() << endl;
	return o;
}
