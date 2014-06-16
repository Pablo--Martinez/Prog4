#include "Socio.h"


Socio::Socio(){}

Socio::Socio(Usuario* u): Rol(u){}

Socio::~Socio(){}//FALTA HACER

void Socio::agregarConsulta(Consulta* c){
	this->solicita.insert(c);
}

Consulta* Socio::devolverReserva(Fecha fecha_consulta){
	set<Consulta*>::iterator it = this->solicita.begin();
	while(it != this->solicita.end()){
		if((*it)->getFechaConsulta() == fecha_consulta){
			this->solicita.erase(it);
			return *it;
		}
		it++;
	}
	return NULL;
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

