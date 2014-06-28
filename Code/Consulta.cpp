#include "Consulta.h"

Consulta::Consulta(){}

Consulta::Consulta(Fecha fecha_consulta, Medico* medico, Socio* socio){
	this->fecha_consulta = fecha_consulta;
	this->atiende = medico;
	this->solicitante = socio;
}

Consulta::~Consulta(){
	delete this->atiende;
	delete this->solicitante;
	for(set<Diagnostico*>::iterator d = this->diagnosticos.begin();d != this->diagnosticos.end();++d){
		delete (*d);
	}
}

Fecha Consulta::getFechaConsulta(){
	return this->fecha_consulta;
}

Medico* Consulta::getMedico(){
	return this->atiende;
}

Socio* Consulta::getSocioSolicitante(){
	return this->solicitante;
}

bool Consulta::perteneceAMedico(int ci){
	return this->getMedico()->getUsuario()->getCI() == ci;
}

bool Consulta::perteneceASocio(int ci){
	return this->getSocioSolicitante()->getUsuario()->getCI() == ci;
}

void Consulta::agregarDiagnostico(Diagnostico* diagnostico){
	this->diagnosticos.insert(diagnostico);
}

bool Consulta::esDeHoy(){
    RelojSistema* rj = RelojSistema::getInstance();
	return (this->getFechaConsulta() == rj->getFechaSistema());
}

set<Diagnostico*> Consulta::getDiagnosticos(){
	return this->diagnosticos;
}
