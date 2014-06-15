#include "Diagnostico.h"

Diagnostico::Diagnostico(){}

Diagnostico::Diagnostico(string codigo, string etiqueta, string descripcion){
	this->codigo = codigo;
	this->etiqueta = etiqueta;
	this->descripcion = descripcion;
}

Diagnostico::~Diagnostico(){}

string Diagnostico::getCodigo(){
	return this->codigo;
}

string Diagnostico::getEtiqueta(){
	return this->etiqueta;
}

string Diagnostico::getDescripcion(){
	return this->descripcion;
}

void Diagnostico::agregarTratamiento(Tratamiento* tratamiento){
	this->tratamientos.insert(tratamiento);
}

set<Tratamiento*> Diagnostico::getTratamientos(){
	return this->tratamientos;
}

DataDiagnostico Diagnostico::getDataDiagnostico(){
	DataRep* dr = new DataRep(this->codigo,this->etiqueta);
	DataDiagnostico dd = DataDiagnostico(dr,this->descripcion);
	for(set<Tratamiento*>::iterator it = this->tratamientos.begin();it!=this->tratamientos.end();++it){
		dd.agregarTratamiento(&(*it)->getDataTratamiento());
	}
	return dd;
}

void Diagnostico::show(){
	if(this != NULL){
		cout << "Representación: " << this->codigo << this->etiqueta << endl;
		cout << "Descripcion: " << this->descripcion << endl;
	
		set<Tratamiento*>::iterator pos;
		pos = this->tratamientos.begin();
		int i=0;
		while(pos != this->tratamientos.end()){
			cout << "Tratamiento" << i << ": " << endl;
			(*pos)->show();
			pos++;
			i++;
		}
	}
}

