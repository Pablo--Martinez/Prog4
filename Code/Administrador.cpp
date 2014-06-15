#include "Administrador.h"

Administrador::Administrador(){}

Administrador::Administrador(Usuario* u): Rol(u){}

Administrador::~Administrador(){}//FALTA HACER

set<Usuario*> Administrador::getUsuariosAlta(){
	return this->daDeAlta;
}

set<Usuario*> Administrador::getUsuariosReactivados(){
	return this->reactiva;
}

void Administrador::show(){
	if(this != NULL){
		cout << "Usuario:" << endl;
		this->getUsuario()->show();
		cout << "Usuarios dados de alta:" << endl;
		for (set<Usuario*>::iterator it=this->daDeAlta.begin(); it!=this->daDeAlta.end(); ++it){
			(*it)->show();
			cout << "----------------" << endl;
		}
	}
}
