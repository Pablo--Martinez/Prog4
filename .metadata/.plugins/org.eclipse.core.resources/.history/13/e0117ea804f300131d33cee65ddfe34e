#include "ControladorConsultas.h"

ControladorConsultas* ControladorConsultas::instancia = NULL;

ControladorConsultas::ControladorConsultas(){}

ControladorConsultas* ControladorConsultas::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorConsultas();
	return instancia;
}

void ControladorConsultas::registroReserva(int ci_user,int ci_doc,Fecha fecha_reserva,Fecha fecha_consulta){
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	Socio* s = ms->find(ci_user);
	Medico* m = mm->find(ci_doc);
	ConReserva* r = new ConReserva(fecha_consulta,fecha_reserva,m,s);
	s->agregarConsulta(r);
	m->agregarConsulta(r);
	instancia->consultas.insert(r);
}

void ControladorConsultas::registroEmergencia(int ci_user,int ci_doc,string motivo,Fecha fecha_consulta){}

//set<DataConsulta> ControladorConsultas::consultasActivas(){}

void ControladorConsultas::devolverConsulta(Fecha fecha_consulta){
	/*set<Consulta*>::iterator it = this->consultas.begin();
	while(it != this->consultas.end()){
		if((*it)->getFechaConsulta() == fecha_consulta){
			Consulta* c = *it;
			c->getMedico()->devolverConsulta(c);
			c->getSocioSolicitante()->devolverReserva(fecha_consulta);
			this->consultas.erase(it);
			delete c;
			break;
		}
		it++;
	}*/
	//destroy c;
}

//set<DataConsulta> ControladorConsultas::consultasDelDia(){}

void ControladorConsultas::seleccionarConsultaCI(int ci_user){}

//DataHistorial ControladorConsutlas::obtenerHistorial(int){}





