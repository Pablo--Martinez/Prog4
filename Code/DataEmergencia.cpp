#include "DataEmergencia.h"

DataEmergencia::DataEmergencia(){}

DataEmergencia::DataEmergencia(Fecha fecha_consulta,string motivo): DataConsulta(fecha_consulta){
	this->motivo = motivo;
}

DataEmergencia::~DataEmergencia(){}

string DataEmergencia::getMotivo(){
	return this->motivo;
}


