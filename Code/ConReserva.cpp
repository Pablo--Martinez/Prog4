#include "ConReserva.h"

//ConReserva::ConReserva(){}

ConReserva::ConReserva(Fecha fecha_consulta,Fecha fecha_reserva, Medico* medico, Socio* socio):Consulta(fecha_consulta, medico,socio){
	this->fecha_reserva = fecha_reserva;
	this->asiste = false;
}

ConReserva::~ConReserva(){}

Fecha ConReserva::getFechaReserva(){
	return this->fecha_reserva;
}

void ConReserva::registrar(){
	this->asiste = true;
}

bool ConReserva::getAsiste(){
	return this->asiste;
}

DataConsulta* ConReserva::getDataConsulta(){
	if(this != NULL){
		DataConReserva* res = new DataConReserva(this->getFechaConsulta(),this->fecha_reserva,this->asiste);
			for(set<Diagnostico*>::iterator it = this->getDiagnosticos().begin();it!=this->getDiagnosticos().end();++it){
				DataDiagnostico* dd = (*it)->getDataDiagnostico();
				res->agregarDiagnostico(dd);
			}
			return res;
	}
	return NULL;
}

void ConReserva::show(){
	if(this != NULL){
		cout << "Conuslta con reserva:" << endl;
		cout << "Fecha de consulta: "; this->getFechaConsulta().show();
		cout << "Fecha de reserva: "; this->getFechaReserva().show();
		cout << "Medico tratante: "; this->getMedico()->show();
		set<Diagnostico*>::iterator pos;
		pos = this->getDiagnosticos().begin();
		int i=0;

		while(pos != this->getDiagnosticos().end()){
			cout << "Diagnostico" << i << ": " << endl;
			(*pos)->show();
			pos++;
			i++;
		}
	}
}
