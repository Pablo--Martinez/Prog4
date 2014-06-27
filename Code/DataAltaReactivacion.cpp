#include "DataAltaReactivacion.h"

DataAltaReactivacion::DataAltaReactivacion() {}

DataAltaReactivacion::~DataAltaReactivacion() {}

DataAltaReactivacion::DataAltaReactivacion(DataUsuario* dataUsuario,Fecha fecha,bool esAlta){
	this->usuario = dataUsuario;
	this->fechaAltaReactivacion = fecha;
	this->esAlta = esAlta;
}

DataUsuario* DataAltaReactivacion::getUsuario(){
	return this->usuario;
}

Fecha DataAltaReactivacion::getFecha(){
	return this->fechaAltaReactivacion;
}

bool DataAltaReactivacion::getTipoOperacion(){
	return this->esAlta;
}
