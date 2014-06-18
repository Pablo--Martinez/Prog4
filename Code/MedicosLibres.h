#ifndef MEDICOSLIBRES_H_
#define MEDICOSLIBRES_H_

#include "Strategy.h"
#include "ManejadorMedicos.h"

using namespace std;

class MedicosLibres: public Strategy {
	private:
		int cantConsultas;
	public:
		MedicosLibres(int);
		virtual ~MedicosLibres();
		set<DataMedico*> algoritmoDeSeleccion();
};

#endif /* MEDICOSLIBRES_H_ */
