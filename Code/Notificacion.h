#ifndef NOTIFICACION_H_
#define NOTIFICACION_H_

#include <iostream>
#include "Fecha.h"
#include "Medico.h"

using namespace std;

class Notificacion{
	private:
		Fecha fecha;
		bool seAgregoDiag;
		Medico* diagnostico;
	public:
		Notificacion();
		Notificacion(Medico*,Fecha,bool);
		~Notificacion();
		Fecha getFecha();
		bool getSeAgregoDiag();
		Medico* getQuienDiagnostico();
		void show();
};

#endif /* NOTIFICACION_H_ */
