#include "MedicosDelPaciente.h"

MedicosDelPaciente::MedicosDelPaciente() {
	// TODO Auto-generated constructor stub

}

MedicosDelPaciente::~MedicosDelPaciente() {
	// TODO Auto-generated destructor stub
}

set<DataMedico*> MedicosDelPaciente::algoritmoDeSeleccion(){
	int ci_socio; // se saca de la mem del sist
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	Socio* s = ms->find(ci_socio);
	set<DataMedico*> medicosDelPaciente = s->obtenerMedicosDelPaciente();
	return medicosDelPaciente;
}
