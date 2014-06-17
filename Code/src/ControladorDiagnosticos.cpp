#include "ControladorDiagnosticos.h"

ControladorDiagnosticos* ControladorDiagnosticos::instancia = NULL;

ControladorDiagnosticos::ControladorDiagnosticos(){
	this->diag = NULL;
}

ControladorDiagnosticos* ControladorDiagnosticos::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorDiagnosticos();
	return instancia;
}

Diagnostico* ControladorDiagnosticos::getDiagnostico(){
	return this->diag;
}

set<string> ControladorDiagnosticos::obtenerCategorias(){}

//set<DataRep> ControladorDiagnosticos::obtenerRepresentaciones(string){}

void ControladorDiagnosticos::altaDiagnostico(string,string,string){}
