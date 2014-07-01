#include "Medico.h"

//Medico::Medico(){}

Medico::Medico(Usuario* u): IObserver(u){}

Medico::~Medico(){
	for(map<int, set<Notificacion*> >::iterator cat = this->notificaciones.begin(); cat != this->notificaciones.end();++cat){
		for(set<Notificacion*>::iterator dr = cat->second.begin();dr != cat->second.end();++dr) {
			delete (*dr);
		}
		cat->second.clear();
	}
	this->notificaciones.clear();
}

tipoRol Medico::getTipoRol() {
	return medico;
}

set<Consulta*> Medico::getConsultasAtiende(){
	return this->consultas;
}

void Medico::agregarConsulta(Consulta* c){
	this->consultas.insert(c);
}

void Medico::devolverConsulta(Consulta* c){
	this->consultas.erase(c);
}

void Medico::seguir(Socio* s){
	s->attach(this);

}

void Medico::notify(int ci_socio, Medico* medico ,Fecha fecha ,bool seAgregoDiag){
	Notificacion* note = new Notificacion(medico,fecha,seAgregoDiag);
	this->notificaciones[ci_socio].insert(note);
}

DataMedico* Medico::getDataMedico(){
	DataUsuario* du = this->getUsuario()->getDataUsuario();
	DataMedico* dm = new DataMedico(du);
	return dm;
}

DataMedico* Medico::obtenerHistorial(int ci_socio){
	bool encontre = false;
	DataMedico* dm = this->getDataMedico();
	for(set<Consulta*>::iterator it = this->consultas.begin();it != this->consultas.end();++it){
		if((*it)->perteneceASocio(ci_socio)){
			encontre = true;
			DataConsulta* dc = (*it)->getDataConsulta();
			dm->agregarConsulta(dc);
		}
	}
	if (encontre)
		return dm;
	else
		return NULL;
}

bool Medico::libreHoraYConsultas(int cantConsultas) {
	RelojSistema* rs = RelojSistema::getInstance();
	set<Consulta*> cons = this->consultas;
	int cant = 0;
	Fecha fecha_sist = rs->getFechaSistema();
	for(set<Consulta*>::iterator consulta = cons.begin();consulta != cons.end();++consulta) {
		Fecha f = (*consulta)->getFechaConsulta();
		if (f == fecha_sist) {
			return false;
		}
		else {
			cant++;
		}
	}
	return cant<cantConsultas;
}

bool Medico::libreParaFecha(Fecha fecha_consulta){
	set<Consulta*>::iterator consulta = this->consultas.begin();
	while(consulta != this->consultas.end()){
		if((*consulta)->getFechaConsulta() == fecha_consulta){
			return false;
		}
		++consulta;
	}
	return true;
}

void Medico::show(){
	if(this != NULL){
		cout << "Usuario:" << endl;
		this->getUsuario()->show();
	}
}

void Medico::showNotificaciones(int ci_socio){
	if(this->notificaciones.find(ci_socio) == this->notificaciones.end())
		std::invalid_argument("Este socio no tiene seguimiento");

	set<Notificacion*> notificaciones = this->notificaciones.find(ci_socio)->second;
	for(set<Notificacion*>::iterator notes = notificaciones.begin();notes != notificaciones.end();++notes)
		(*notes)->show();
}

map<int,set<Notificacion*> > Medico::getNotificaciones(){
	return this->notificaciones;
}
