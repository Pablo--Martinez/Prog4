#include "ManejadorRepresentaciones.h"

ManejadorRepresentaciones* ManejadorRepresentaciones::instancia = NULL;

ManejadorRepresentaciones::ManejadorRepresentaciones(){}

ManejadorRepresentaciones::~ManejadorRepresentaciones(){
	for(map<string,DataRep*>::iterator it = this->categorias.begin();it != this->categorias.end();++it){
		delete (it->second);
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

ManejadorRepresentaciones* ManejadorRepresentaciones::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorRepresentaciones();
	return instancia;
}

void ManejadorRepresentaciones::agregarRepresentacion(string letra,string codigo,string etiqueta) {
	DataRep* dataRep = new DataRep(codigo,etiqueta);
	//set<DataRep*> representaciones = this->representaciones[letra];
	//representaciones.insert(dataRep);
	this->representaciones[letra].insert(dataRep);
}
void ManejadorRepresentaciones::agregarCategoria(string letra,string etiqueta) {
	DataRep* dataCat = new DataRep(letra,etiqueta);
	//DataRep* thisCat = this->categorias[letra];
	if (this->categorias.find(letra) == this->categorias.end()){
		this->categorias[letra] = dataCat;
	}
}
bool ManejadorRepresentaciones::existeRepresentacion(string letra,string codigo,string etiqueta) {
	set<DataRep*> representaciones = this->representaciones[letra];
	if (representaciones.empty()) {
		return false;
	}
	for(set<DataRep*>::iterator dr = representaciones.begin();dr != representaciones.end();++dr) {
		string thiscodigo = (*dr)->getCodigo();
		string thisetiqueta = (*dr)->getEtiqueta();
		if (thiscodigo == codigo || thisetiqueta == etiqueta) {
			return true;
		}
	}
	return false;
}
bool ManejadorRepresentaciones::existeRepresentacion(string letra,string codigo) {
	set<DataRep*> representaciones = this->representaciones[letra];
	if (representaciones.empty()) {
		return false;
	}
	for(set<DataRep*>::iterator dr = representaciones.begin();dr != representaciones.end();++dr) {
		string thiscodigo = (*dr)->getCodigo();
		string thisetiqueta = (*dr)->getEtiqueta();
		if (thiscodigo == codigo) {
			return true;
		}
	}
	return false;
}
DataRep* ManejadorRepresentaciones::obtenerRepresentacion(string letra,string codigo) {
	set<DataRep*> representaciones = this->representaciones[letra];
	if (representaciones.empty()) {
		return NULL;
	}
	for(set<DataRep*>::iterator dr = representaciones.begin();dr != representaciones.end();++dr) {
		string thiscodigo = (*dr)->getCodigo();
		string thisetiqueta = (*dr)->getEtiqueta();
		if (thiscodigo == codigo) {
			return (*dr);
		}
	}
	return NULL;
}
bool ManejadorRepresentaciones::existeCategoria(string letra) {
	if (this->categorias.find(letra) == this->categorias.end()){
		return false;
	} else {
		return true;
	}
}
void ManejadorRepresentaciones::ingresarRepresentaciones(string letraCat,set<DataRep*> reps) {
	for(set<DataRep*>::iterator dr = reps.begin();dr != reps.end();++dr) {
		if (!this->existeRepresentacion(letraCat,(*dr)->getCodigo(),(*dr)->getEtiqueta())) {
			this->agregarRepresentacion(letraCat,(*dr)->getCodigo(),(*dr)->getEtiqueta());
		}
	}
}
map<string,DataRep*> ManejadorRepresentaciones::obtenerCategorias() {
	return this->categorias;
}
set<DataRep*> ManejadorRepresentaciones::obtenerRepresentacionesCat(string letraCat) {
	return this->representaciones[letraCat];
}
