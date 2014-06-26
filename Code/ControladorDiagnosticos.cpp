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

void ControladorDiagnosticos::seleccionarCategoria(string letraCat) {
	this->catSeleccionada = letraCat;
}

void ControladorDiagnosticos::ingresarCategoria(string letraCat,string etiqueta) {
	this->catSeleccionada = letraCat;
	this->etiquetaSeleccionada = etiqueta;
	DataRep* dataCat = new DataRep(letraCat,etiqueta);
	DataRep* thisCat = this->categorias[letraCat];
	//if (this->categorias[letraCat] == this->categorias.end()){
	if (thisCat == NULL){
		this->categorias[letraCat] = dataCat;
	}
}

bool ControladorDiagnosticos::existeRepDiag(string codigo,string etiqueta) {
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	return mr->existeRepresentacion(this->catSeleccionada,codigo,etiqueta);
}

void ControladorDiagnosticos::ingresarRepDiag(string codigo,string etiqueta) {
	DataRep* dataRep = new DataRep(this->catSeleccionada+codigo,etiqueta);
	set<DataRep*> representaciones = this->representaciones[this->catSeleccionada];
	representaciones.insert(dataRep);
}

void ControladorDiagnosticos::confirmarRepEst() {
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	for(map<string,DataRep*>::iterator cat = this->categorias.begin(); cat != this->categorias.end();++cat){
		if (!mr->existeCategoria(cat->second->getCodigo(),cat->second->getEtiqueta())) {
			mr->agregarCategoria(cat->second->getCodigo(),cat->second->getEtiqueta());
		}
		mr->ingresarRepresentaciones(cat->second->getCodigo(),this->representaciones[cat->second->getCodigo()]);
	}
	// acá hay que destruir todo el registro temporal de representaciones
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
	/*set<DataRep*> representaciones;
	for(set<Diagnostico*>::iterator d = this->diagnosticos.begin();d != this->diagnosticos.end();++d) {
		bool perteneceACat = (*d)->perteneceACat(letraCat);
		if (perteneceACat) {
			DataRep* repDiag = (*d)->getDataRepDiagnostico();
			representaciones.insert(repDiag);
		}
	}
	return representaciones;*/
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	return mr->obtenerRepresentacionesCat(letraCat);
}

void ControladorDiagnosticos::altaDiagnostico(string,string,string){}
