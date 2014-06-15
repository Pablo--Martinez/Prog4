#include "Medico.h"

Medico::Medico(){}

Medico::Medico(Usuario* u): IObserver(u){}

Medico::~Medico(){}//FALTA HACER

map<Fecha,Consulta*> Medico::getConsultasAtiende(){
	return this->atiende;
}

void Medico::agregarConsulta(Consulta* c){
	//this->atiende.insert(c);
	this->atiende[c->getFechaConsulta()] = c;

}

void Medico::devolverConsulta(Consulta* c){
	//this->atiende.erase(c);
	this->atiende.erase(c->getFechaConsulta());
}

void Medico::seguir(Socio* s){
	s->attach(this);

}

void Medico::notify(int ci_socio, Medico* medico ,Fecha fecha ,bool seAgregoDiag){
	//this->notificaciones->getInstance();
	Notificacion* note = new Notificacion(medico,fecha,seAgregoDiag);
	this->notificaciones[ci_socio] = note;
}

DataMedico Medico::getDataMedico(){
	DataMedico dm = DataMedico(this->getUsuario());
	for(map<Fecha,Consulta*>::iterator it=this->atiende.begin();it!=this->atiende.end();++it){
		dm.agregarConsulta(&it->second->getDataConsulta());
	}
	return dm;
}

DataMedico Medico::obtenerHistorial(int ci_socio){
	bool encontre = false;
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	DataMedico dm = DataMedico(ms->find(ci_socio)->getUsuario()->getDataUsuario());
	for(map<Fecha,Consulta*>::iterator it = this->atiende.begin();it != this->atiende.end();++it){
		if(it->second->perteneceASocio(ci_socio)){
			encontre = true;
			DataConsulta dc = it->second->getDataConsulta();
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
		for (map<Fecha,Consulta*>::iterator it=this->atiende.begin(); it!=this->atiende.end(); ++it){
			it->second->show();
			cout << "----------------" << endl;
		}
	}
}

void Medico::showNotificaciones(){
	for(map<int, set<Notificacion*> >::iterator it = this->notificaciones->getNotificaciones(); it != this->notificaciones->getNotificaciones();++it){
		for(set<Notificacion*>::iterator notes = it->second.begin();notes != it->second.end();++notes)
			(*notes)->show();
	}
}
