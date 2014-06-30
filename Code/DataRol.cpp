#include "DataRol.h"

DataRol::DataRol() {}

DataRol::DataRol(tipoRol tipo){
	this->tipo = tipo;
}

DataRol::~DataRol() {}

tipoRol DataRol::getTipoRol(){
	return this->tipo;
}
