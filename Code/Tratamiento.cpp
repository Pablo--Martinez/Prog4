#include "Tratamiento.h"

Tratamiento::Tratamiento(){}

Tratamiento::Tratamiento(string descripcion){
	this->descripcion = descripcion;
}

string Tratamiento::getDescripcion(){
	return this->descripcion;
}

DataTratamiento* Tratamiento::getDataTratamiento(){
	DataTratamiento* dt = new DataTratamiento(this->descripcion);
	return dt;
}
