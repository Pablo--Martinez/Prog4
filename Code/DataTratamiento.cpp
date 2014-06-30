#include "DataTratamiento.h"

DataTratamiento::DataTratamiento() {}

DataTratamiento::~DataTratamiento() {}

DataTratamiento::DataTratamiento(string desc){
	this->descripcion = desc;
}

string DataTratamiento::getDescripcion(){
	return this->descripcion;
}

void DataTratamiento::show(){
	if(this != NULL)
		cout << "\t\t\t\tDescripcion: " <<this->descripcion << endl;
}
