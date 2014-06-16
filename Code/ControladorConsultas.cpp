#include "ControladorConsultas.h"

ControladorConsultas* ControladorConsultas::instancia = NULL;

ControladorConsultas::ControladorConsultas(){}

ControladorConsultas* ControladorConsultas::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorConsultas();
	return instancia;
}

void ControladorConsultas::registroReserva(int ci_user,int ci_doc,Fecha fecha_reserva,Fecha fecha_consulta){
	set<Consulta*>::iterator it = this->consultas.begin();
	while(it != this->consultas.end()){
		ConReserva* r = dynamic_cast<ConReserva*>(*it);
		if( r != 0){
			if(r->perteneceASocio(ci_user) && r->perteneceAMedico(ci_doc) &&
			   r->getFechaReserva() == fecha_reserva && r->getFechaConsulta() == fecha_consulta){
				r->registrar();
				break;
			}
		}
		it++;
	}
}

void ControladorConsultas::registroEmergencia(int ci_user,int ci_doc,string motivo,Fecha fecha_consulta){}
/*

set<DataConsulta> ControladorConsultas::consultasActivas(Fecha fecha_sistema){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorSocios* cs = ManejadorSocios::getInstance();
	Socio* s = cs->find(cu->getUsuarioLogueado()->getCI());
	set<DataConsulta> dc;
	for(set<Consulta*>::iterator it = s->getConsultasSolicitadas().begin();it!=s->getConsultasSolicitadas().end();++it){
		if((*it)->getFechaConsulta() > fecha_sistema)
			dc.insert((*it)->getDataConsulta());
	}
	return dc;
}
*/
void ControladorConsultas::devolverConsulta(Fecha fecha_consulta){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	Socio* s = ms->find(cu->getUsuarioLogueado()->getCI());
	Consulta* r = s->devolverReserva(fecha_consulta);
	Medico* m = r->getMedico();
	m->devolverConsulta(r);
	this->consultas.erase(r);
	delete r;
}/*

set<DataConsulta> ControladorConsultas::consultasDelDia(Fecha fecha_sistema){
	set<DataConsulta> res;
	for(set<Consulta*>::iterator it = this->consultas.begin();it != this->consultas.end();++it){
		ConReserva* r = dynamic_cast<ConReserva*>(*it);
		if(r != 0 && r->getFechaConsulta() > fecha_sistema){
			res.insert(r->getDataConsulta());
		}
	}
	return res;
}*/

void ControladorConsultas::seleccionarConsultaCI(int ci_user){}

DataHistorial ControladorConsultas::obtenerHistorial(int ci_user,Fecha fecha_sistema){
	DataHistorial dh;
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	for(map<int,Medico*>::iterator m = mm->getMedicos().begin(); m != mm->getMedicos().end();++m){
		DataMedico dm = m->second->obtenerHistorial(ci_user,fecha_sistema);
		if(&dm != NULL)
			dh.agregarMedico(&dm);
	}
	return dh;
}