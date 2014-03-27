#include "Empleado.h"

Empleado::Empleado()
{
	this->nombre = NULL;
	this->ci = NULL;
	this->edad = 0;
	this->empresa = NULL;
}

Empleado::Empleado(char* nombre, char* ci, int edad, Paga valor_hora, Empresa* e)
{
	this->nombre = new char;
	this->ci = new char;
    strcpy(this->nombre,nombre);
    strcpy(this->ci,ci);
    this->edad = edad;
    this->valor_hora = valor_hora;
    if(e != NULL){
		this->empresa = e;
	}
	else{
		throw std::invalid_argument("La empresa no existe");
	}
}

/*
Empleado::Empleado(const Empleado &e){
	this->nombre = new char;
	this->ci = new char;
	strcpy(this->nombre,e.nombre);
    strcpy(this->ci,e.ci);
    this->edad = e.edad;
    this->valor_hora = e.valor_hora;
    this->empresa = e.empresa;
}
*/
Empleado::~Empleado(){
	delete nombre;
	delete ci; 
}

char* Empleado::get_nombre(){
	return this->nombre;
}

char* Empleado::get_ci(){
	return this->ci;
}

int Empleado::get_edad()
{
    return this->edad;
}

Paga Empleado::get_valor_hora()
{
    return this->valor_hora;
}

Empresa* Empleado::get_empresa()
{
	return this->empresa;
}
