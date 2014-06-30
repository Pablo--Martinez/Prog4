#include "DataEmergencia.h"

DataEmergencia::DataEmergencia(){}

DataEmergencia::DataEmergencia(Fecha fecha_consulta,string motivo): DataConsulta(fecha_consulta){
	this->motivo = motivo;
}

DataEmergencia::~DataEmergencia(){}

string DataEmergencia::getMotivo(){
	return this->motivo;
}

void DataEmergencia::show(){
	if(this != NULL){
		cout << "\t\tConsulta de emergencia:" << endl;
		cout << "\t\tFecha de consulta: "; this->getFechaConsulta().show();
		cout << endl;
		cout << "\t\tMotivo: " << this->motivo << endl;
		set<DataDiagnostico*>::iterator pos;
		pos = this->getDiagnosticos().begin();
		int i=0;
		while(pos != this->getDiagnosticos().end()){
			cout << "\t\tDiagnostico" << i << ": " << endl;
			(*pos)->show();
			pos++;
			i++;
		}
	}
}

