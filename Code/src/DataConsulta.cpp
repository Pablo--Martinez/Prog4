#include "DataConsulta.h"

DataConsulta::DataConsulta(){}

DataConsulta::DataConsulta(Fecha fecha_consulta){
	this->fecha_consulta = fecha_consulta;
}

DataConsulta::~DataConsulta(){}

Fecha DataConsulta::getFechaConsulta(){
	return this->fecha_consulta;
}

void DataConsulta::agregarDiagnostico(DataDiagnostico* dd){
	this->diagnosticos.insert(dd);
}
