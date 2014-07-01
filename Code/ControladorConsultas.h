#ifndef CONTROLADORCONSULTAS_H_
#define CONTROLADORCONSULTAS_H_

#include <set>
#include <stdexcept>
#include "Fecha.h"
#include "Consulta.h"
#include "ConReserva.h"
#include "Emergencia.h"
#include "Rol.h"
#include "ManejadorMedicos.h"
#include "ManejadorSocios.h"
#include "ControladorUsuarios.h"
#include "ManejadorSocios.h"
#include "ManejadorMedicos.h"
#include "ManejadorAdministradores.h"
#include "DataConsulta.h"
#include "DataHistorial.h"
#include "DataUsuario.h"

using namespace std;

class ControladorConsultas{
	private:
		static ControladorConsultas* instancia;
		ControladorConsultas();
		set<Consulta*> consultas;
		//set<DataConsulta*> data_consultas;
		Strategy* estrategia;
		int cantidad_estrategia;
		Fecha fecha_consulta;
		Fecha fecha_reserva;
		int ci_tratante;

	public:
		static ControladorConsultas* getInstance();
		~ControladorConsultas();
		void ingresarCITratante(int);
		int getCITratante();
		void agregarConsulta(Consulta*);
		ConReserva* registroReserva(int,int,Fecha);
		void registroEmergencia(int,int,string,Fecha);
		set<DataConsulta*> consultasActivasXUsuario();
		void devolverConsulta(Fecha);
		set<DataConsulta*> consultasDelDia(Fecha);
		DataConsulta* seleccionarConsultaCI(int);
		DataHistorial* obtenerHistorial(int,Fecha);
		Consulta* getConsulta(int ci_soc,Fecha fecha);
		void seleccionarCriterio(int);
		void setCantidad(int);
		set<DataMedico*> ejecutarStrategy();
		set<DataUsuario*> obtenerMedicos();
		void ingresarFechaConsulta(Fecha);
		void ingresarFechaReserva(Fecha);
		void ingresarConsulta(int);		
};
#endif /* CONTROLADORCONSULTAS_H_ */
