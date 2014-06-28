#include "MedicosDelPaciente.h"

MedicosDelPaciente::MedicosDelPaciente(int ci_socio) {
	this->ci_tratante = ci_socio;
}

MedicosDelPaciente::~MedicosDelPaciente() {
	// TODO Auto-generated destructor stub
}

set<DataMedico*> MedicosDelPaciente::algoritmoDeSeleccion(){
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	Socio* s = ms->find(this->ci_tratante);
	set<DataMedico*> medicosDelPaciente = s->obtenerMedicosDelPaciente();
	return medicosDelPaciente;
}

