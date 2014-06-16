#ifndef EMERGENCIA_H_
#define EMERGENCIA_H_

#include "Consulta.h"

class Emergencia: public Consulta{
	private:
		string motivo;
	public:
		Emergencia();
		Emergencia(Fecha,string,Medico*,Socio*);
		~Emergencia();
		string getMotivo();
		virtual DataConsulta getDataConsulta();
		void show();
};

#endif /* EMERGENCIA_H_ */
