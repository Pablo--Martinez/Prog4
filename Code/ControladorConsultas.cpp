#include "ControladorConsultas.h"

ControladorConsultas* ControladorConsultas::instancia = NULL;

ControladorConsultas::ControladorConsultas(){}

ControladorConsultas* ControladorConsultas::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorConsultas();
	return instancia;
}

void ControladorConsultas::registroReserva(int ci_user,int ci_doc,Fecha fecha_reserva,Fecha fecha_consulta){}

void ControladorConsultas::registroEmergencia(int ci_user,int ci_doc,string motivo,Fecha fecha_consulta){}

//set<DataConsulta> ControladorConsultas::consultasActivas(){}

void ControladorConsultas::devolverConsulta(Fecha fecha_consulta){}

//set<DataConsulta> ControladorConsultas::consultasDelDia(){}

void ControladorConsultas::seleccionarConsultaCI(int ci_user){}

//DataHistorial ControladorConsutlas::obtenerHistorial(int){}





