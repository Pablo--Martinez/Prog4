#include "Quirurjico.h"

Quirurjico::Quirurjico(){
	this->cirujano = NULL;
}

Quirurjico::Quirurjico(string descripcion,Fecha operacion,Medico* medico):Tratamiento(descripcion){
	this->fecha = operacion;
	this->cirujano = medico;
}

Quirurjico::~Quirurjico(){}

Fecha Quirurjico::getFechaOperacion(){
	return this->fecha;
}

Medico* Quirurjico::getCirujano(){
	return this->cirujano;
}

void Quirurjico::show(){
	cout << "Descripcion: " << this->getDescripcion() << endl;
	cout << "Fecha intervencion: "; this->fecha.show();
	cout << "Cirujano: "; this->cirujano->show();
}
