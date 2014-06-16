#include "Medico.h"

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

DataMedico Medico::getDataMedico(Fecha fecha_sistema){
	DataUsuario du = this->getUsuario()->getDataUsuario(fecha_sistema);
	DataMedico dm = DataMedico(&du);
	for(set<Consulta*>::iterator it=this->atiende.begin();it!=this->atiende.end();++it){
		DataConsulta dc = (*it)->getDataConsulta();
		dm.agregarConsulta(&dc);
	}
	return dm;
}

DataMedico Medico::obtenerHistorial(int ci_socio, Fecha fecha_sistema){
	bool encontre = false;
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	DataUsuario du = ms->find(ci_socio)->getUsuario()->getDataUsuario(fecha_sistema);
	DataMedico dm = DataMedico(&du);
	for(set<Consulta*>::iterator it = this->atiende.begin();it != this->atiende.end();++it){
		if((*it)->perteneceASocio(ci_socio)){
			encontre = true;
			DataConsulta dc = (*it)->getDataConsulta();
			dm.agregarConsulta(&dc);
		}
	}
	if (encontre)
		return dm;
	else
		return NULL;
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
	for(map<int, set<Notificacion*> >::iterator it = this->notificaciones.begin();it!=this->notificaciones.end();++it){
		for(set<Notificacion*>::iterator notes = it->second.begin();notes != it->second.end();++notes)
			(*notes)->show();
	}
}
