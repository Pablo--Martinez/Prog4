#include "Rol.h"

Rol::Rol(){
	this->usuario = NULL;
}

Rol::Rol(Usuario* u){
	this->usuario = u;
}

Rol::~Rol(){}//FALTA HACER

Usuario* Rol::getUsuario(){
	return this->usuario;
}

IObserver::IObserver(Usuario* u):Rol(u){}

Administrador::Administrador(){}

Administrador::Administrador(Usuario* u): Rol(u){}

Administrador::~Administrador(){}//FALTA HACER

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

//Medico::Medico(){}

Medico::Medico(Usuario* u): IObserver(u){}

Medico::~Medico(){}//FALTA HACER

set<Consulta*> Medico::getConsultasAtiende(){
	return this->atiende;
}

void Medico::agregarConsulta(Consulta* c){
	this->atiende.insert(c);
}

void Medico::devolverConsulta(Consulta* c){
	this->atiende.erase(c);
}

void Medico::seguir(Socio* s){
	s->attach(this);

}

void Medico::notify(int ci_socio, Medico* medico ,Fecha fecha ,bool seAgregoDiag){
	//this->notificaciones->getInstance();
	Notificacion* note = new Notificacion(medico,fecha,seAgregoDiag);
	this->notificaciones[ci_socio].insert(note);
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

void Medico::showNotificaciones(){
	for(map<int, set<Notificacion*> >::iterator it = this->notificaciones.begin(); it != this->notificaciones.end();++it){
		for(set<Notificacion*>::iterator notes = it->second.begin();notes != it->second.end();++notes)
			(*notes)->show();
	}
}

Socio::Socio(){}

Socio::Socio(Usuario* u): Rol(u){}

Socio::~Socio(){}//FALTA HACER

void Socio::agregarConsulta(Consulta* c){
	this->solicita.insert(c);
}

void Socio::devolverReserva(Fecha fecha_consulta){
	set<Consulta*>::iterator it = this->solicita.begin();
	while(it != this->solicita.end()){
		if((*it)->getFechaConsulta() == fecha_consulta){
			Consulta* c = *it;
			this->solicita.erase(it);
			//destroy c;
			break;
		}
		it++;
	}
}

set<Consulta*> Socio::getConsultasSolicitadas(){
	return this->solicita;
}

void Socio::attach(IObserver* o){
	this->observadores.insert(o);
}

void Socio::unattach(IObserver* o){
	set<IObserver*>::iterator it = this->observadores.begin();
	while(it != this->observadores.end()){
		if((*it)->getUsuario()->getCI() == o->getUsuario()->getCI()){
			this->observadores.erase(it);
			return;
		}
		++it;
	}
}

void Socio::notifyall(Medico* medico,Fecha fecha,bool nuevoDiag){
	set<IObserver*>::iterator it = this->observadores.begin();
	cout << this->observadores.size()<< endl;
	while(it != this->observadores.end()){
		if(*it != medico)
			(*it)->notify(this->getUsuario()->getCI(),medico,fecha,nuevoDiag);
		it++;
	}
}

//set<DataMedico> Socio::obtenerMedicosDelPaciente(){}

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
