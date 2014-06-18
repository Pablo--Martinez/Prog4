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
		bool sirve = it->second->libreHoraYConsultas(cantConsultas);
		if (sirve) {
			DataMedico* dm = it->second->getDataMedico();
			medicosSeleccionados.insert(dm);
		}
	}
	return medicosSeleccionados;
}
