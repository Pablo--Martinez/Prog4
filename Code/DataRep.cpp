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
