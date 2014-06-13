#include "Consulta.h"

Consulta::Consulta(){}

Consulta::Consulta(Fecha fecha_consulta, Medico* medico, Socio* socio){
	this->fecha_consulta = fecha_consulta;
	this->atiende = medico;
	this->solicitante = socio;
}

Consulta::~Consulta(){}

Fecha Consulta::getFechaConsulta(){
	return this->fecha_consulta;
}

Medico* Consulta::getMedico(){
	return this->atiende;
}

Socio* Consulta::getSocioSolicitante(){
	return this->solicitante;
}

void Consulta::agregarDiagnostico(Diagnostico* diagnostico){
	this->diagnosticos.insert(diagnostico);
}

set<Diagnostico*> Consulta::getDiagnosticos(){
	return this->diagnosticos;
}

Emergencia::Emergencia(){}

Emergencia::Emergencia(Fecha fecha_consulta,string motivo, Medico* medico, Socio* socio):Consulta(fecha_consulta,medico,socio){
	this->motivo = motivo;
}

Emergencia::~Emergencia(){}

string Emergencia::getMotivo(){
	return this->motivo;
}

void Emergencia::show(){
	cout << "Consulta de emergecia: " << endl;
	cout << "Fecha de consulta: "; this->getFechaConsulta().show();
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

ConReserva::ConReserva(){}

ConReserva::ConReserva(Fecha fecha_consulta,Fecha fecha_reserva, Medico* medico, Socio* socio):Consulta(fecha_consulta, medico,socio){
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
