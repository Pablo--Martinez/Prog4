#ifndef CONSULTA
#define CONSULTA

#include <string>
#include <iostream>
#include <list>
#include "Fecha.h"

using namespace std;

class Diagnostico;

class Consulta{
	private:
		Fecha fecha_consulta;
	protected:
		list<Diagnostico*> diagnosticos;
	public:
		Consulta();
		Consulta(Fecha);
		Fecha getFechaConsulta();
		void agregarDiagnostico(Diagnostico*);
		list<Diagnostico*> getDiagnosticos();
		virtual void show()=0;
};

class Emergencia: public Consulta{
	private:
		string motivo;
	public:
		Emergencia();
		Emergencia(Fecha,string);
		string getMotivo();
		void show();
};

class ConReserva: public Consulta{
	private:
		Fecha fecha_reserva;
		bool asiste;
	public:
		ConReserva();
		ConReserva(Fecha,Fecha);
		Fecha getFechaReserva();
		bool getAsiste();
		void show();
};

#include "Diagnostico.h"

#endif