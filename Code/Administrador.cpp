#include "Administrador.h"

Administrador::Administrador(){}

Administrador::Administrador(Usuario* u): Rol(u){}

Administrador::~Administrador(){
	//delete this->criterio;
	for(set<Usuario*>::iterator u = this->daDeAlta.begin();u != this->daDeAlta.end();++u){
		delete (*u);
	}
	for(set<Usuario*>::iterator u = this->reactiva.begin();u != this->reactiva.end();++u){
		delete (*u);
	}
}

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
