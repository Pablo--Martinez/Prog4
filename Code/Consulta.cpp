#include "Consulta.h"

Consulta::Consulta(){}

Consulta::Consulta(Fecha fecha_consulta){
	this->fecha_consulta = fecha_consulta;
}

Consulta::~Consulta(){}

Fecha Consulta::getFechaConsulta(){
	return this->fecha_consulta;
}
void Consulta::agregarDiagnostico(Diagnostico* diagnostico){
	this->diagnosticos.insert(diagnostico);
}

set<Diagnostico*> Consulta::getDiagnosticos(){
	return this->diagnosticos;
}

Emergencia::Emergencia(){}

Emergencia::Emergencia(Fecha fecha_consulta,string motivo):Consulta(fecha_consulta){
	this->motivo = motivo;
}

Emergencia::~Emergencia(){}

string Emergencia::getMotivo(){
	return this->motivo;
}

void Emergencia::show(){
	cout << "Consulta de emergecia: " << endl;
	cout << "Fecha de consulta: "; this->getFechaConsulta().show();
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

ConReserva::ConReserva(){}

ConReserva::ConReserva(Fecha fecha_consulta,Fecha fecha_reserva):Consulta(fecha_consulta){
	this->fecha_reserva = fecha_reserva;
	this->asiste = false;
}

ConReserva::~ConReserva(){}

Fecha ConReserva::getFechaReserva(){
	return this->fecha_reserva;
}

bool ConReserva::getAsiste(){
	return this->asiste;
}

void ConReserva::show(){
	if(this != NULL){
		cout << "Conuslta con reserva:" << endl;
		cout << "Fecha de consulta: "; this->getFechaConsulta().show();
		cout << "Fecha de reserva: "; this->getFechaReserva().show();
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
