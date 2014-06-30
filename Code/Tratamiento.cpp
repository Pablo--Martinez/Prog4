#include "Tratamiento.h"

Tratamiento::Tratamiento(){}

Tratamiento::Tratamiento(string descripcion){
	this->descripcion = descripcion;
}

Tratamiento::~Tratamiento(){}//FALTA HACER

string Tratamiento::getDescripcion(){
	return this->descripcion;
}

DataTratamiento* Tratamiento::getDataTratamiento(){
	if(this != NULL){
		DataTratamiento* dt = new DataTratamiento(this->descripcion);
		return dt;
	}
	return NULL;
}
