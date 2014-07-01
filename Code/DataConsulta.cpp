#include "DataConsulta.h"

DataConsulta::DataConsulta(){}

DataConsulta::DataConsulta(Fecha fecha_consulta){
	this->fecha_consulta = fecha_consulta;
}

DataConsulta::~DataConsulta(){
	for(set<DataDiagnostico*>::iterator it = this->diagnosticos.begin();it != this->diagnosticos.end();++it){
		delete (*it);
	}
	this->diagnosticos.clear();
}

Fecha DataConsulta::getFechaConsulta(){
	return this->fecha_consulta;
}

int DataConsulta::getCI(){
	return this->ci;
}

void DataConsulta::setCI(int ci){
	this->ci = ci;
}

set<DataDiagnostico*> DataConsulta::getDiagnosticos(){
	return this->diagnosticos;
}

void DataConsulta::agregarDiagnostico(DataDiagnostico* dd){
	this->diagnosticos.insert(dd);
}
