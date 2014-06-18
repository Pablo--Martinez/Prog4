#ifndef MEDICOSDELPACIENTE_H_
#define MEDICOSDELPACIENTE_H_

#include "Strategy.h"
#include "ManejadorSocios.h"

using namespace std;

class MedicosDelPaciente: public Strategy {
	public:
		MedicosDelPaciente();
		virtual ~MedicosDelPaciente();
		set<DataMedico*> algoritmoDeSeleccion();
};

#endif /* MEDICOSDELPACIENTE_H_ */
