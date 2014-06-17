#include "StrategyMedicosLibres.h"

MedicosLibres::MedicosLibres(){}

MedicosLibres::~MedicosLibres(){}//FALTA HACER

set<DataMedico*> MedicosLibres::algoritmoDeSeleccion(int cantConsultas,Fecha fecha_sistema){

	ManejadorMedicos* mm = ManejadorMedicos::getInstance();

	set<DataMedico*> medicosSeleccionados;

	for (map<int,Medico*>::iterator it=mm->medicos.begin(); it!=mm->medicos.end(); ++it){

		bool sirve = it->second->libreHoraYConsultas(cantConsultas);

		if (sirve) {

			DataMedico* dm = it->second->getDataMedico(fecha_sistema);

			medicosSeleccionados.insert(dm);

		}

	}

	return 0;
}


