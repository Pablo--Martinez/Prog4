#include "DataDiagnostico.h"

DataDiagnostico::DataDiagnostico() {}

DataDiagnostico::~DataDiagnostico() {
	delete this->representacion;
	for(set<DataTratamiento*>::iterator it = this->tratamientos.begin();it != this->tratamientos.end();++it){
		delete (*it);
	}
	this->tratamientos.clear();
}

DataDiagnostico::DataDiagnostico(DataRep* dr,string desc){
	if(this != NULL){
		this->descripicon = desc;
		this->representacion = dr;
	}
}

void DataDiagnostico::agregarTratamiento(DataTratamiento* dt){
	this->tratamientos.insert(dt);
}

DataRep* DataDiagnostico::getDataRep(){
	return this->representacion;
}

string DataDiagnostico::getDescripcion(){
	return this->descripicon;
}

set<DataTratamiento*> DataDiagnostico::getTratamientos(){
	return this->tratamientos;
}

void DataDiagnostico::show(){
	if(this != NULL){
		cout << "\t\t\tDescripcion: " << this->descripicon << endl;
		this->representacion->show();
		int i = 0;
		for(set<DataTratamiento*>::iterator it = this->tratamientos.begin(); it!=this->tratamientos.end();++it){
			cout << "\t\t\tTratamiento" << i << ":" << endl;
			(*it)->show();
			i++;
		}
	}
}
