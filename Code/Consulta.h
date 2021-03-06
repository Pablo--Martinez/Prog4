#ifndef CONSULTA
#define CONSULTA

#include <iostream>
#include <set>
#include "Fecha.h"
#include "DataConsulta.h"

using namespace std;

class Diagnostico;
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
		bool perteneceAMedico(int);
		bool perteneceASocio(int);
		void agregarDiagnostico(Diagnostico*);
		bool esDeHoy();
		set<Diagnostico*> getDiagnosticos();
		virtual DataConsulta* getDataConsulta()=0;
		virtual void show()=0;
};

#include "Diagnostico.h"
#include "Rol.h"
#include "Medico.h"
#include "Socio.h"

#endif
