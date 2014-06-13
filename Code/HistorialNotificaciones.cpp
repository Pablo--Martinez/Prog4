#include "HistorialNotificaciones.h"

HistorialNotificaciones* HistorialNotificaciones::instancia = NULL;

HistorialNotificaciones::HistorialNotificaciones(){}

HistorialNotificaciones::~HistorialNotificaciones(){} //FALTA HACER

HistorialNotificaciones* HistorialNotificaciones::getInstance(){
	if(instancia == NULL)
		instancia = new HistorialNotificaciones();
	return instancia;
}

void HistorialNotificaciones::add(int ci_socio,Notificacion* note){
	this->notificaciones[ci_socio].insert(note);
}



