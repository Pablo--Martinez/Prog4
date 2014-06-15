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

bool Consulta::perteneceAMedico(int ci){
	return this->getMedico()->getUsuario()->getCI() == ci;
}

bool Consulta::perteneceASocio(int ci){
	return this->getSocioSolicitante()->getUsuario()->getCI() == ci;
}

void Consulta::agregarDiagnostico(Diagnostico* diagnostico){
	this->diagnosticos.insert(diagnostico);
}

set<Diagnostico*> Consulta::getDiagnosticos(){
	return this->diagnosticos;
}
