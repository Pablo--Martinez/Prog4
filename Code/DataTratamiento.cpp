#include "DataTratamiento.h"

DataTratamiento::DataTratamiento() {}

DataTratamiento::~DataTratamiento() {}

DataTratamiento::DataTratamiento(string desc){
	this->descripcion = desc;
}

string DataTratamiento::getDescripcion(){
	return this->descripcion;
}