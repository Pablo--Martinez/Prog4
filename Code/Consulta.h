#ifndef CONSULTA
#define CONSULTA

#include <string>
#include <iostream>
#include <set>
#include "Fecha.h"

using namespace std;

class Diagnostico;
//class Rol;
class Medico;
class Socio;

class Consulta{
	private:
		Fecha fecha_consulta;
		Medico* atiende;
		Socio* solicitante;
		set<Diagnostico*> diagnosticos;
	public:
		Consulta();
		Consulta(Fecha,Medico*,Socio*);
		virtual ~Consulta()=0;
		Fecha getFechaConsulta();
		Medico* getMedico();
		Socio* getSocioSolicitante();
		void agregarDiagnostico(Diagnostico*);
		set<Diagnostico*> getDiagnosticos();
		virtual void show()=0;
};

class Emergencia: public Consulta{
	private:
		string motivo;
	public:
		Emergencia();
		Emergencia(Fecha,string,Medico*,Socio*);
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
		ConReserva(Fecha,Fecha,Medico*,Socio*);
		~ConReserva();
		Fecha getFechaReserva();
		bool getAsiste();
		void show();
};

#include "Diagnostico.h"
#include "Rol.h"

#endif
