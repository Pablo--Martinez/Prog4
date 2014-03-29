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
	this->nombre = new char[50];
	this->ci = new char[50];
    strcpy(this->nombre,nombre);
    strcpy(this->ci,ci);
    if(edad > 0){
		this->edad = edad;
	}
	else{
		throw std::invalid_argument("Edad incorrecta");
	}
    this->valor_hora = valor_hora;
    if(e != NULL){
		this->empresa = e;
	}
	else{
		throw std::invalid_argument("La empresa no existe");
	}
}

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
