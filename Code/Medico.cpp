#include "Medico.h"

//Medico::Medico(){}

Medico::Medico(Usuario* u): IObserver(u){}

Medico::~Medico(){}//FALTA HACER

tipoRol Medico::getTipoRol() {
	return medico;
}

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

set<DataAltaReactivacion*> Medico::obtenerUsuariosAltaReactivacion() {
	set<DataAltaReactivacion*> setVacio;
	return setVacio;
}

void Medico::notify(int ci_socio, Medico* medico ,Fecha fecha ,bool seAgregoDiag){
	//this->notificaciones->getInstance();
	Notificacion* note = new Notificacion(medico,fecha,seAgregoDiag);
	this->notificaciones[ci_socio].insert(note);
}

DataMedico* Medico::getDataMedico(){
	DataUsuario* du = this->getUsuario()->getDataUsuario();
	DataMedico* dm = new DataMedico(du);
	for(set<Consulta*>::iterator it=this->atiende.begin();it!=this->atiende.end();++it){
		DataConsulta* dc = (*it)->getDataConsulta();
		dm->agregarConsulta(dc);
	}
	return dm;
}

DataMedico* Medico::obtenerHistorial(int ci_socio){
	bool encontre = false;
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	DataUsuario* du = ms->find(ci_socio)->getUsuario()->getDataUsuario();
	DataMedico* dm = new DataMedico(du);
	for(set<Consulta*>::iterator it = this->atiende.begin();it != this->atiende.end();++it){
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
	set<Consulta*> consultas = this->getConsultasAtiende();
	int cant = 0;
	Fecha fecha_sist = rs->getFechaSistema();
	for(set<Consulta*>::iterator consulta = consultas.begin();consulta != consultas.end();++consulta) {
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
	set<Consulta*>::iterator consulta = this->atiende.begin();
	while(consulta != this->atiende.end()){
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
		cout << "Consultas que atiende:" << endl;
		for (set<Consulta*>::iterator it=this->atiende.begin(); it!=this->atiende.end(); ++it){
			(*it)->show();
			cout << "----------------" << endl;
		}
	}
}

void Medico::showNotificaciones(int ci_socio){
	/*for(map<int, set<Notificacion*> >::iterator it = this->notificaciones.begin();it!=this->notificaciones.end();++it){
		for(set<Notificacion*>::iterator notes = it->second.begin();notes != it->second.end();++notes)
			(*notes)->show();
	}*/
	if(this->notificaciones.find(ci_socio) == this->notificaciones.end())
		std::invalid_argument("Este socio no tiene seguimiento");

	for(set<Notificacion*>::iterator notes = this->notificaciones.find(ci_socio)->second.begin();
			notes != this->notificaciones.find(ci_socio)->second.end();++notes)
		(*notes)->show();
}

map<int,set<Notificacion*> > Medico::getNotificaciones(){
	return this->notificaciones;
}
