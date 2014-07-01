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
	set<int> ci;
	for (map<int,Medico*>::iterator it=medicos.begin(); it!=medicos.end();++it){
		bool sirve = it->second->libreHoraYConsultas(this->cantConsultas);
		if (sirve) {
			if(ci.count(it->first) == 0){
				ci.insert(it->first);
				DataMedico* dm = it->second->getDataMedico();
				medicosSeleccionados.insert(dm);
			}
		}
	}
	return medicosSeleccionados;
}
