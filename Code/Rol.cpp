#include "Rol.h"
#include "Administrador.h"
#include "Medico.h"
#include "Socio.h"

Rol::Rol(){
	//this->usuario = NULL;
}

Rol::Rol(Usuario* u){
	this->usuario = u;
}

Rol::~Rol(){}//FALTA HACER

Usuario* Rol::getUsuario(){
	return this->usuario;
}

bool Rol::esAdministrador(){
	if(dynamic_cast<Administrador*>(this) != NULL)
		return true;
	return false;
}

bool Rol::esMedico(){
	if(dynamic_cast<Medico*>(this) != NULL)
			return true;
		return false;
}

bool Rol::esSocio(){
	if(dynamic_cast<Socio*>(this) != NULL)
			return true;
		return false;
}
