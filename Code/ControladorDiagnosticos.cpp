#include "ControladorDiagnosticos.h"

ControladorDiagnosticos* ControladorDiagnosticos::instancia = NULL;

ControladorDiagnosticos::ControladorDiagnosticos(){
	this->diag = NULL;
}

ControladorDiagnosticos::~ControladorDiagnosticos(){
	delete this->diag;
	delete this->categoriaSeleccionada;
	this->letrasCat.clear();
	for(set<Diagnostico*>::iterator it = this->diagnosticos.begin();it != this->diagnosticos.end();++it){
		delete (*it);
	}
	this->diagnosticos.clear();
	for(set<Diagnostico*>::iterator it = this->diagnosticosTemp.begin();it != this->diagnosticosTemp.end();++it){
		delete (*it);
	}
	this->diagnosticosTemp.clear();
	for(map<string, set<DataRep*> >::iterator cat = this->representaciones.begin(); cat != this->representaciones.end();++cat){
		for(set<DataRep*>::iterator dr = cat->second.begin();dr != cat->second.end();++dr) {
			delete (*dr);
		}
		cat->second.clear();
	}
	this->representaciones.clear();
	for(map<string,DataRep*>::iterator it = this->categorias.begin();it != this->categorias.end();++it){
		delete (it->second);
	}
	this->categorias.clear();
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
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	if (!mr->existeCategoria(letraCat)) {
		throw std::invalid_argument("La categoria seleccionada no existe");
	} else {
		this->catSeleccionada = letraCat;
	}
}

void ControladorDiagnosticos::ingresarCategoria(string letraCat,string etiqueta) {
	this->catSeleccionada = letraCat;
	this->etiquetaSeleccionada = etiqueta;
	DataRep* dataCat = new DataRep(letraCat,etiqueta);
	if (this->categorias.find(letraCat) == this->categorias.end()){
		this->categorias[letraCat] = dataCat;
	}
}

bool ControladorDiagnosticos::existeRepDiag(string codigo,string etiqueta) {
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	return mr->existeRepresentacion(this->catSeleccionada,codigo,etiqueta);
}

void ControladorDiagnosticos::ingresarRepDiag(string codigo,string etiqueta) {
	if (this->categorias.find(this->catSeleccionada) == this->categorias.end()) {
		this->ingresarCategoria(this->catSeleccionada,this->etiquetaSeleccionada);
	}
	DataRep* dataRep = new DataRep(this->catSeleccionada+codigo,etiqueta);
	this->representaciones[this->catSeleccionada].insert(dataRep);
}

void ControladorDiagnosticos::confirmarRepEst() {
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	for(map<string,DataRep*>::iterator cat = this->categorias.begin(); cat != this->categorias.end();++cat){
		if (!mr->existeCategoria(cat->second->getCodigo())) {
			mr->agregarCategoria(cat->second->getCodigo(),cat->second->getEtiqueta());
		}
		mr->ingresarRepresentaciones(cat->second->getCodigo(),this->representaciones[cat->second->getCodigo()]);
	}
	// aca hay que destruir todo el registro temporal de representaciones
	this->clearRepEst();
}

void ControladorDiagnosticos::clearRepEst() {
	for(map<string,DataRep*>::iterator cat = this->categorias.begin(); cat != this->categorias.end();++cat){
		delete cat->second;
	}
	this->categorias.clear();
	for(map<string, set<DataRep*> >::iterator cat = this->representaciones.begin(); cat != this->representaciones.end();++cat){
		for(set<DataRep*>::iterator dr = cat->second.begin();dr != cat->second.end();++dr) {
			delete (*dr);
		}
		cat->second.clear();
	}
	this->representaciones.clear();
}

set<string> ControladorDiagnosticos::obtenerCategorias(){
	set<string> categorias;
	for(set<Diagnostico*>::iterator d = this->diagnosticos.begin();d != this->diagnosticos.end();++d) {
		string catDiag = (*d)->obtenerCatDiag();
		categorias.insert(catDiag);
	}
	return categorias;
}

string ControladorDiagnosticos::obtenerCategoriaSeleccionada() {
	return this->catSeleccionada;
}

set<DataRep*> ControladorDiagnosticos::obtenerRepresentaciones(string letraCat){
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	return mr->obtenerRepresentacionesCat(letraCat);
}

void ControladorDiagnosticos::altaDiagnostico(string,string,string){}
