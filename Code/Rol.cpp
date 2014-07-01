#include "Rol.h"

Rol::Rol(){}

Rol::Rol(Usuario* u){
	this->usuario = u;
}

Rol::~Rol(){}//FALTA HACER

Usuario* Rol::getUsuario(){
	return this->usuario;
}
