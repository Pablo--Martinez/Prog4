#include "DataConReserva.h"

DataConReserva::DataConReserva(Fecha fecha_consulta,Fecha fecha_reserva, bool asiste, int ci_soc): DataConsulta(fecha_consulta) {
	this->fecha_reserva = fecha_reserva;
	this->asiste = asiste;
	//this->ci = ci_soc;
	this->setCI(ci_soc);
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
		set<DataDiagnostico*> diags = this->getDiagnosticos();
		int i=0;
		for(set<DataDiagnostico*>::iterator it = diags.begin();it!=diags.end();++it){
		        cout << "\t\tDiagnostico" << i << ": " << endl;
			(*it)->show();
			i++;
		}		  
	}
}

