#include "Administrador.h"

Administrador::Administrador(){}

Administrador::Administrador(Usuario* u): Rol(u){}

Administrador::~Administrador(){
	for(set<DataAltaReactivacion*>::iterator da = this->deAltaReactivados.begin();da != this->deAltaReactivados.end();++da){
		delete (*da);
	}
	this->deAltaReactivados.clear();
}
/*
set<Usuario*> Administrador::getUsuariosAlta(){
	return this->daDeAlta;
}

set<Usuario*> Administrador::getUsuariosReactivados(){
	return this->reactiva;
}*/

tipoRol Administrador::getTipoRol() {
	return administrador;
}

void Administrador::agregarUsuarioAltaReactivacion(DataUsuario* du, Fecha f, bool esReactivacion){
    DataAltaReactivacion* usuarioDadoDeAlta= new DataAltaReactivacion(du, f, esReactivacion);
    this->deAltaReactivados.insert(usuarioDadoDeAlta);
}

set<DataAltaReactivacion*> Administrador::obtenerUsuariosAltaReactivacion(){
	return this->deAltaReactivados;
}

void Administrador::show(){
	if(this != NULL){
		cout << "Usuario:" << endl;
		this->getUsuario()->show();
		cout << "Usuarios dados de alta:" << endl;
		/*for (set<Usuario*>::iterator it=this->daDeAlta.begin(); it!=this->daDeAlta.end(); ++it){
			(*it)->show();
			cout << "----------------" << endl;
		}*/
	}
}
