#ifndef MEDICOSDELPACIENTE_H_
#define MEDICOSDELPACIENTE_H_

#include "Strategy.h"
#include "ManejadorSocios.h"

using namespace std;

class MedicosDelPaciente: public Strategy {
	private:
		int ci_tratante;
	public:
		MedicosDelPaciente(int);
		virtual ~MedicosDelPaciente();
		set<DataMedico*> algoritmoDeSeleccion();
};

#endif /* MEDICOSDELPACIENTE_H_ */
