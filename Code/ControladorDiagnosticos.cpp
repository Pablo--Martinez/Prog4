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
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	if (!mr->existeCategoria(letraCat)) {
		throw std::invalid_argument("La categor�a seleccionada no existe");
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
	//cout << "Entra en ConfirmarRepEst.. \n";
	for(map<string,DataRep*>::iterator cat = this->categorias.begin(); cat != this->categorias.end();++cat){
		//cout << "Prueba una categoria.. \n";
		if (!mr->existeCategoria(cat->second->getCodigo())) {
			cout << "AgregarCategoria: " << cat->second->getCodigo() << " " << cat->second->getEtiqueta() << "\n";
			mr->agregarCategoria(cat->second->getCodigo(),cat->second->getEtiqueta());
		}
		mr->ingresarRepresentaciones(cat->second->getCodigo(),this->representaciones[cat->second->getCodigo()]);
	}
	// ac� hay que destruir todo el registro temporal de representaciones
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
