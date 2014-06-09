#include "Rol.h"

Rol::Rol(){
	this->usuario = NULL;
}

Rol::Rol(Usuario* u){
	this->usuario = u;
}

Rol::~Rol(){}

Usuario* Rol::getUsuario(){
	return this->usuario;
}

Administrador::Administrador(){}

Administrador::Administrador(Usuario* u): Rol(u){}

Administrador::~Administrador(){}

set<Usuario*> Administrador::getUsuariosAlta(){
	return this->daDeAlta;
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

Medico::Medico(){}

Medico::Medico(Usuario* u): Rol(u){}

Medico::~Medico(){}

set<Consulta*> Medico::getConsultasAtiende(){
	return this->atiende;
}

void Medico::show(){
	if(this != NULL){
		cout << "Usuario:" << endl;
		this->getUsuario()->show();
		cout << "Consultas que atiende:" << endl;
		for (set<Consulta*>::iterator it=this->atiende.begin(); it!=this->atiende.end(); ++it){
			(*it)->show();
			cout << "----------------" << endl;
		}
	}
}

Socio::Socio(){}

Socio::Socio(Usuario* u): Rol(u){}

Socio::~Socio(){}

void Socio::agregarConsulta(Consulta* c){
	this->solicita.insert(c);
}

void Socio::devolverReserva(Fecha fecha_consulta){

}

set<Consulta*> Socio::getConsultasSolicitadas(){
	return this->solicita;
}

void Socio::show(){
	if(this != NULL){
		cout << "Usuario: "<< endl;
		this->getUsuario()->show();;
		cout << "Consultas solicitadas:" << endl;
		for (set<Consulta*>::iterator it=this->solicita.begin(); it!=this->solicita.end(); ++it){
			(*it)->show();
			cout << "----------------" << endl;
		}
	}
}
