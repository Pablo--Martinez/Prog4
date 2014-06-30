#include "DataConsulta.h"

DataConsulta::DataConsulta(){}

DataConsulta::DataConsulta(Fecha fecha_consulta/*, int ci*/){
	this->fecha_consulta = fecha_consulta;
	//this->ci = ci;
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

void DataConsulta::agregarDiagnostico(DataDiagnostico* dd){
	this->diagnosticos.insert(dd);
}
