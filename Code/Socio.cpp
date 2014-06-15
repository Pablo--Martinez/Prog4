#include "Socio.h"


Socio::Socio(){}

Socio::Socio(Usuario* u): Rol(u){}

Socio::~Socio(){}//FALTA HACER

void Socio::agregarConsulta(Consulta* c){
	//this->solicita.insert(c);
	this->solicita[c->getFechaConsulta()] = c;
}

Consulta* Socio::devolverReserva(Fecha fecha_consulta){
	Consulta* res = this->solicita[fecha_consulta];
	this->solicita.erase(fecha_consulta);
	return res;
	/*map<Fecha,Consulta*>::iterator it = this->solicita.begin();
	while(it != this->solicita.end()){
		if((*it)->getFechaConsulta() == fecha_consulta){
			Consulta* c = *it;
			this->solicita.erase(it);
			//destroy c;
			break;
		}
		it++;
	}*/
}

map<Fecha,Consulta*> Socio::getConsultasSolicitadas(){
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
		for (map<Fecha,Consulta*>::iterator it=this->solicita.begin(); it!=this->solicita.end(); ++it){
			it->second->show();
			cout << "----------------" << endl;
		}
	}
}

