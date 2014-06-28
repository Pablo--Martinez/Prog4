#include "MedicosDelPaciente.h"

MedicosDelPaciente::MedicosDelPaciente(int ci_socio) {
	this->ci_tratante = ci_socio;
}

MedicosDelPaciente::~MedicosDelPaciente() {
	// TODO Auto-generated destructor stub
}


set<DataMedico*> MedicosDelPaciente::algoritmoDeSeleccion(){
<<<<<<< HEAD
	int ci_socio = 123; // se saca de la mem del sist
=======
>>>>>>> b7e2b535a2597197a49bb25808d86baeed5210cf
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	Socio* s = ms->find(this->ci_tratante);
	set<DataMedico*> medicosDelPaciente = s->obtenerMedicosDelPaciente();
	return medicosDelPaciente;
}

