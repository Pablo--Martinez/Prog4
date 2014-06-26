#include "DataDiagnostico.h"

DataDiagnostico::DataDiagnostico() {}

DataDiagnostico::~DataDiagnostico() {}

DataDiagnostico::DataDiagnostico(DataRep* dr,string desc){
	this->descripicon = desc;
	this->representacion = dr;
}

void DataDiagnostico::agregarTratamiento(DataTratamiento* dt){
	this->tratamientos.insert(dt);
}

DataRep* DataDiagnostico::getDataRep(){
	return this->representacion;
}

string DataDiagnostico::getDescripcion(){
	return this->descripicon;
}

set<DataTratamiento*> DataDiagnostico::getTratamientos(){
	return this->tratamientos;
}
