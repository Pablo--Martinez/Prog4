#include "DataUsuario.h"

DataUsuario::DataUsuario() {}

DataUsuario::DataUsuario(int ci,string nombre,string apellido,Sexo sexo,int edad,bool activo){
	this->ci = ci;
	this->nombre = nombre;
	this->apellido = apellido;
	this->sexo = sexo;
	this->edad = edad;
	this->activo = activo;
}

DataUsuario::~DataUsuario() {}

int DataUsuario::getCI(){
	return this->ci;
}

string DataUsuario::getNombre(){
	return this->nombre;
}

string DataUsuario::getApellido(){
	return this->apellido;
}

int DataUsuario::getEdad(){
	return this->edad;
}

bool DataUsuario::getActivo(){
	return this->activo;
}

