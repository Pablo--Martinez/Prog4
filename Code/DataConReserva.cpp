#include "DataConReserva.h"

DataConReserva::DataConReserva(Fecha fecha_consulta,Fecha fecha_reserva, bool asiste): DataConsulta(fecha_consulta) {
	this->fecha_reserva = fecha_reserva;
	this->asiste = asiste;
}

DataConReserva::~DataConReserva() {}

Fecha DataConReserva::getFechaReserva(){
	return this->fecha_reserva;
}

bool DataConReserva::getAsiste(){
	return this->asiste;
}

void DataConReserva::show(){
	if(this != NULL){
		cout << "\t\tConsulta con reserva:" << endl;
		cout << "\t\tFecha de consulta: "; this->getFechaConsulta().show();
		cout << endl;
		cout << "\t\tFecha de reserva: "; this->getFechaReserva().show();
		cout << endl;
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

