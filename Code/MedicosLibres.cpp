#include "MedicosLibres.h"

MedicosLibres::MedicosLibres(int cantConsultas){
	this->cantConsultas = cantConsultas;
}

MedicosLibres::~MedicosLibres() {
	// TODO Auto-generated destructor stub
}

set<DataMedico*> MedicosLibres::algoritmoDeSeleccion(){
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	set<DataMedico*> medicosSeleccionados;
	for (map<int,Medico*>::iterator it=mm->getMedicos().begin(); it!=mm->getMedicos().end(); ++it){
		bool sirve = it->second->libreHoraYConsultas(this->cantConsultas);
		if (sirve) {//sirve
			medicosSeleccionados.insert(it->second->getDataMedico());
		}
	}
	return medicosSeleccionados;
}
