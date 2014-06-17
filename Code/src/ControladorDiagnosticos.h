#ifndef CONTROLADORDIAGNOSTICOS_H_
#define CONTROLADORDIAGNOSTICOS_H_

#include <set>
#include <string>
#include "Diagnostico.h"

using namespace std;

class ControladorDiagnosticos{
	private:
		static ControladorDiagnosticos* instancia;
		ControladorDiagnosticos();
		set<Diagnostico*> diagnosticos;
		Diagnostico* diag;
		set<string> letrasCat;
		//set<DataRep> reps;
	public:
		static ControladorDiagnosticos* getInstance();
		Diagnostico* getDiagnostico();
		set<string> obtenerCategorias();
		//set<DataRep> obtenerRepresentaciones(string);
		void altaDiagnostico(string,string,string);
};

#endif /* CONTROLADORDIAGNOSTICOS_H_ */
