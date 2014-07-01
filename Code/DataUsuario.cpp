#include "DataUsuario.h"

DataUsuario::DataUsuario() {}

DataUsuario::DataUsuario(int ci,string pass,string nombre,string apellido,Sexo sexo,int edad,bool activo,bool esadmin,bool esmedico,bool essocio){
	this->ci = ci;
	this->pass = pass;
	this->nombre = nombre;
	this->apellido = apellido;
	this->sexo = sexo;
	this->edad = edad;
	this->activo = activo;
	this->esadmin = esadmin;
	this->esmedico = esmedico;
	this->essocio = essocio;
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

bool DataUsuario::esAdmin(){
	return this->esadmin;
}
bool DataUsuario::esMedico(){
	return this->esmedico;
}
bool DataUsuario::esSocio(){
	return this->essocio;
}

/*set<DataRol*> DataUsuario::getRoles(){
	return this->roles;
}*/

int DataUsuario::getEdad(){
	return this->edad;
}

Sexo DataUsuario::getSexo(){
	return this->sexo;
}

bool DataUsuario::getActivo(){
	return this->activo;
}

void DataUsuario::show(){
	cout << "CI usuario: " << this->ci << endl;
	cout << "Nombe completo: " << this->nombre << " " << this->apellido << endl;
	cout << "Edad: " << this->edad << endl;
}

#include "DataUsuario.h"
