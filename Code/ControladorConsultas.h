#ifndef CONTROLADORCONSULTAS_H_
#define CONTROLADORCONSULTAS_H_

#include <set>
#include "Fecha.h"
#include "Consulta.h"
#include "Rol.h"
#include "ManejadorMedicos.h"
#include "ManejadorSocios.h"

class ControladorConsultas{
	private:
		static ControladorConsultas* instancia;
		ControladorConsultas();
		set<Consulta*> consultas;
		//set<DataConsultas> data_consultas;

	public:
		static ControladorConsultas* getInstance();
		void registroReserva(int,int,Fecha,Fecha);
		void registroEmergencia(int,int,string,Fecha);
		//set<DataConsulta> consultasActivas();
		void devolverConsulta(Fecha);
		//set<DataConsulta> consultasDelDia();
		void seleccionarConsultaCI(int);
		//DataHistorial obtenerHistorial(int);
};




#endif /* CONTROLADORCONSULTAS_H_ */
