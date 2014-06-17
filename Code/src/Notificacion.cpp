#include "Notificacion.h"

Notificacion::Notificacion(){}

Notificacion::Notificacion(Medico* medico,Fecha fecha,bool nuevoDiag){
	this->diagnostico = medico;
	this->fecha = fecha;
	this->seAgregoDiag = nuevoDiag;
}

Notificacion::~Notificacion(){}


Fecha Notificacion::getFecha(){
	return this->fecha;
}

bool Notificacion::getSeAgregoDiag(){
	return this->seAgregoDiag;
}

Medico* Notificacion::getQuienDiagnostico(){
	return this->diagnostico;
}

void Notificacion::show(){
	cout << "Medico tratante: ";
	cout << this->diagnostico->getUsuario()->getCI() << ": " << this->diagnostico->getUsuario()->getNombre() << endl;
	cout << "Fecha: "; this->fecha.show();
	cout << "Se diagnostico: ";
	if (this->seAgregoDiag)
		cout << "Si" << endl;
	else
		cout << "No" << endl;
}



