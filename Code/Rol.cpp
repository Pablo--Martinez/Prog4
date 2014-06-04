#include "Rol.h"

Rol::Rol(){}

Rol::Rol(Usuario* u){
	this->usuario = u;
}

Usuario* Rol::getUsuario(){
	return this->usuario;
}

Administrador::Administrador(){}

Administrador::Administrador(Usuario* u): Rol(u){}

set<Usuario*> Administrador::getUsuariosAlta(){
	return this->daDeAlta;
}

void Administrador::show(){
	cout << "Usuario:" << endl;
	this->getUsuario()->show();
	cout << "Usuarios dados de alta:" << endl;
	for (set<Usuario*>::iterator it=this->daDeAlta.begin(); it!=this->daDeAlta.end(); ++it){
		(*it)->show();
		cout << "----------------" << endl;
	}
}

Medico::Medico(){}

Medico::Medico(Usuario* u): Rol(u){}

set<Consulta*> Medico::getConsultasAtiende(){
	return this->atiende;
}

void Medico::show(){
	cout << "Usuario:" << endl;
	this->getUsuario()->show();
	cout << "Consultas que atiende:" << endl;
	for (set<Consulta*>::iterator it=this->atiende.begin(); it!=this->atiende.end(); ++it){
		(*it)->show();
		cout << "----------------" << endl;
	}
}

Socio::Socio(){}

Socio::Socio(Usuario* u): Rol(u){}

set<Consulta*> Socio::getConsultasSolicitadas(){
	return this->solicita;
}

void Socio::show(){
	cout << "Usuario: "<< endl;
	this->getUsuario()->show();;
	cout << "Consultas solicitadas:" << endl;
	for (set<Consulta*>::iterator it=this->solicita.begin(); it!=this->solicita.end(); ++it){
		(*it)->show();
		cout << "----------------" << endl;
	}
}
