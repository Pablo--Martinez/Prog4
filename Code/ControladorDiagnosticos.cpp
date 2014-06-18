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

set<string> ControladorDiagnosticos::obtenerCategorias(){
	set<string> categorias;
	for(set<Diagnostico*>::iterator d = this->diagnosticos.begin();d != this->diagnosticos.end();++d) {
		string catDiag = (*d)->obtenerCatDiag();
		categorias.insert(catDiag);
	}
	return categorias;
}

set<DataRep*> ControladorDiagnosticos::obtenerRepresentaciones(string letraCat){
	set<DataRep*> representaciones;
	for(set<Diagnostico*>::iterator d = this->diagnosticos.begin();d != this->diagnosticos.end();++d) {
		bool perteneceACat = (*d)->perteneceACat(letraCat);
		if (perteneceACat) {
			DataRep* repDiag = (*d)->getDataRepDiagnostico();
			representaciones.insert(repDiag);
		}
	}
	return representaciones;
}

void ControladorDiagnosticos::altaDiagnostico(string,string,string){}
