#include "Diagnostico.h"

Diagnostico::Diagnostico(){}

Diagnostico::Diagnostico(string codigo, string etiqueta, string descripcion, Consulta* consulta){
	this->codigo = codigo;
	this->etiqueta = etiqueta;
	this->descripcion = descripcion;
	this->consulta = consulta;
	consulta->agregarDiagnostico(this);
}

Diagnostico::~Diagnostico(){
	/*for(set<Tratamiento*>::iterator it = this->tratamientos.begin();it != this->tratamientos.end();++it){
		delete (*it);
	}*/
	this->tratamientos.clear();
}

string Diagnostico::getCodigo(){
	return this->codigo;
}

string Diagnostico::getEtiqueta(){
	return this->etiqueta;
}

string Diagnostico::getDescripcion(){
	return this->descripcion;
}

string Diagnostico::obtenerCatDiag(){
	return this->etiqueta.substr(0,1);
}

bool Diagnostico::perteneceACat(string letraCat){
	if (letraCat[0] == this->etiqueta[0])
	{
	  return true;
	}
	return false;
}

void Diagnostico::agregarTratamiento(Tratamiento* tratamiento){
	this->tratamientos.insert(tratamiento);
}

set<Tratamiento*> Diagnostico::getTratamientos(){
	return this->tratamientos;
}

DataDiagnostico* Diagnostico::getDataDiagnostico(){
	if(this != NULL){
		DataRep* dr = new DataRep(this->codigo,this->etiqueta); // ACA ESTA EL BUG
		DataDiagnostico* dd = new DataDiagnostico(dr,this->descripcion);
		for(set<Tratamiento*>::iterator it = this->tratamientos.begin();it!=this->tratamientos.end();++it){
			DataTratamiento* dt = (*it)->getDataTratamiento();
			dd->agregarTratamiento(dt);
		}
		return dd;
	}
	return NULL;
}

DataRep* Diagnostico::getDataRepDiagnostico(){

	DataRep* dr = new DataRep(this->codigo, this->etiqueta);

	return dr;
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

