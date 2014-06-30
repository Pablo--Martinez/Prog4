#include "HistorialNotificaciones.h"

HistorialNotificaciones* HistorialNotificaciones::instancia = NULL;

HistorialNotificaciones::HistorialNotificaciones(){}

HistorialNotificaciones::~HistorialNotificaciones(){
	for(map<int,set<Notificacion*> >::iterator cat = this->notificaciones.begin();cat != this->notificaciones.end();++cat){
		for(set<Notificacion*>::iterator dr = cat->second.begin();dr != cat->second.end();++dr) {
			delete (*dr);
		}
		cat->second.clear();
	}
	this->notificaciones.clear();
} //FALTA HACER

HistorialNotificaciones* HistorialNotificaciones::getInstance(){
	if(instancia == NULL)
		instancia = new HistorialNotificaciones();
	return instancia;
}

map<int ,set<Notificacion*> > HistorialNotificaciones::getNotificaciones(){
	return this->notificaciones;
}

void HistorialNotificaciones::add(int ci_socio,Notificacion* note){
	this->notificaciones[ci_socio].insert(note);
}



