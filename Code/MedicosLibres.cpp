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
	map<int,Medico*> medicos = mm->getMedicos();
	for (map<int,Medico*>::iterator it=medicos.begin(); it!=medicos.end();++it){
		bool sirve = it->second->libreHoraYConsultas(this->cantConsultas);
		if (sirve) {
			DataMedico* dm = it->second->getDataMedico();
			medicosSeleccionados.insert(dm);
		}
	}
	return medicosSeleccionados;
}
