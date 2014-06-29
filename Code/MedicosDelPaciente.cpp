#include "MedicosDelPaciente.h"

MedicosDelPaciente::MedicosDelPaciente(int ci_socio) {
	this->ci_tratante = ci_socio;
}

MedicosDelPaciente::~MedicosDelPaciente() {
	// TODO Auto-generated destructor stub
}


set<DataMedico*> MedicosDelPaciente::algoritmoDeSeleccion(){
<<<<<<< HEAD
	//int ci_socio;  se saca de la mem del sist
=======
>>>>>>> bbc437e2af137594c3668cb75fdfba244b571d1c
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	Socio* s = ms->find(this->ci_tratante);
	set<DataMedico*> medicosDelPaciente = s->obtenerMedicosDelPaciente();
	return medicosDelPaciente;
}

