#ifndef EMERGENCIA_H_
#define EMERGENCIA_H_

#include "Consulta.h"
#include "DataEmergencia.h"

using namespace std;

class Emergencia: public Consulta{
	private:
		string motivo;
	public:
		Emergencia();
		Emergencia(Fecha,string,Medico*,Socio*);
		~Emergencia();
		string getMotivo();
		DataConsulta* getDataConsulta();
		void show();
};

#endif /* EMERGENCIA_H_ */
