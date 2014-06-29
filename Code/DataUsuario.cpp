#include "DataUsuario.h"

DataUsuario::DataUsuario() {}

DataUsuario::DataUsuario(int ci,string pass,string nombre,string apellido,Sexo sexo,int edad,bool activo, set<Rol*> roles){
	this->ci = ci;
	this->pass = pass;
	this->nombre = nombre;
	this->apellido = apellido;
	this->sexo = sexo;
	this->edad = edad;
	this->activo = activo;
	this->roles = roles;
}


DataUsuario::~DataUsuario() {}

int DataUsuario::getCI(){
	return this->ci;
}

string DataUsuario::getPass(){
	return this->pass;
}

string DataUsuario::getNombre(){
	return this->nombre;
}

string DataUsuario::getApellido(){
	return this->apellido;
}

set<Rol*> DataUsuario::getRoles(){
	return this->roles;
}

int DataUsuario::getEdad(){
	return this->edad;
}

Sexo DataUsuario::getSexo(){
	return this->sexo;
}

bool DataUsuario::getActivo(){
	return this->activo;
}



#include "DataUsuario.h"
