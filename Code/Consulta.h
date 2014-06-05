#ifndef CONSULTA
#define CONSULTA

#include <string>
#include <iostream>
#include <set>
#include "Fecha.h"

using namespace std;

class Diagnostico;

class Consulta{
	private:
		Fecha fecha_consulta;
		set<Diagnostico*> diagnosticos;
	public:
		Consulta();
		Consulta(Fecha);
		virtual ~Consulta()=0;
		Fecha getFechaConsulta();
		void agregarDiagnostico(Diagnostico*);
		set<Diagnostico*> getDiagnosticos();
		virtual void show()=0;
};

class Emergencia: public Consulta{
	private:
		string motivo;
	public:
		Emergencia();
		Emergencia(Fecha,string);
		~Emergencia();
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
		~ConReserva();
		Fecha getFechaReserva();
		bool getAsiste();
		void show();
};

#include "Diagnostico.h"

#endif
