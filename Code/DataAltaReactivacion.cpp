#include "DataAltaReactivacion.h"

DataAltaReactivacion::DataAltaReactivacion() {}

DataAltaReactivacion::~DataAltaReactivacion() {}

DataAltaReactivacion::DataAltaReactivacion(DataUsuario* dataUsuario,Fecha fecha,bool esReactivacion){
	this->usuario = dataUsuario;
	this->fechaAltaReactivacion = fecha;
	this->tipoOperacion = esReactivacion;
}

DataUsuario* DataAltaReactivacion::getUsuario(){
	return this->usuario;
}

Fecha DataAltaReactivacion::getFecha(){
	return this->fechaAltaReactivacion;
}

bool DataAltaReactivacion::getTipoOperacion(){
	return this->tipoOperacion;
}
