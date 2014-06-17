#ifndef CONTROLADORCONSULTAS_H_
#define CONTROLADORCONSULTAS_H_

#include <set>
#include "Fecha.h"
#include "Consulta.h"
#include "ConReserva.h"
#include "Rol.h"
#include "ManejadorMedicos.h"
#include "ManejadorSocios.h"
#include "ControladorUsuarios.h"
#include "ManejadorSocios.h"
#include "ManejadorMedicos.h"
#include "ManejadorAdministradores.h"
#include "DataConsulta.h"
#include "DataHistorial.h"

using namespace std;

class ControladorConsultas{
	private:
		static ControladorConsultas* instancia;
		ControladorConsultas();
		set<Consulta*> consultas;
		set<DataConsulta*> data_consultas;

	public:
		static ControladorConsultas* getInstance();
		void agregarConsulta(Consulta*);
		void registroReserva(int,int,Fecha,Fecha);
		void registroEmergencia(int,int,string,Fecha);
		set<DataConsulta*> consultasActivas(Fecha);
		void devolverConsulta(Fecha);
		set<DataConsulta*> consultasDelDia(Fecha);
		void seleccionarConsultaCI(int);
		DataHistorial obtenerHistorial(int,Fecha);
};




#endif /* CONTROLADORCONSULTAS_H_ */
