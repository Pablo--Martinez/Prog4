#include "DataRep.h"

DataRep::DataRep() {}

DataRep::DataRep(string codigo,string etiqueta){
	//this->letra = letra;
	this->codigo = codigo;
	this->etiqueta = etiqueta;
}

DataRep::~DataRep() {}
/*
string DataRep::getLetra(){
	return this->letra;
}*/

string DataRep::getCodigo(){
	return this->codigo;
}

string DataRep::getEtiqueta(){
	return this->etiqueta;
}

void DataRep::show(){
	if(this != NULL){
		cout << "\t\t\tCodigo: " << this->codigo << endl;
		cout << "\t\t\tEtiqueta: " << this->etiqueta << endl;
	}
}
