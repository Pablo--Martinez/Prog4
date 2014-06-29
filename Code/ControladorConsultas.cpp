#include "ControladorConsultas.h"

ControladorConsultas* ControladorConsultas::instancia = NULL;

ControladorConsultas::ControladorConsultas(){
	this->estrategia = NULL;
}

ControladorConsultas::~ControladorConsultas(){
	delete this->estrategia;
}

ControladorConsultas* ControladorConsultas::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorConsultas();
	return instancia;
}

void ControladorConsultas::ingresarCITratante(int ci_soc){
	this->ci_tratante = ci_soc;
}

int ControladorConsultas::getCITratante(){
	return this->ci_tratante;
}

void ControladorConsultas::agregarConsulta(Consulta* c){
	this->consultas.insert(c);
}

void ControladorConsultas::registroReserva(int ci_user,int ci_doc,Fecha fecha_reserva,Fecha fecha_consulta){
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();

	if(mm->find(ci_doc) == NULL)
		throw std::invalid_argument("No existe el medico");
	if(ms->find(ci_user) == NULL)
		throw std::invalid_argument("No existe el socio");

	set<Consulta*>::iterator it = this->consultas.begin();
	while(it != this->consultas.end()){
		if(typeid(*it) == typeid(ConReserva)){
			ConReserva* r = dynamic_cast<ConReserva*>(*it);
			if(r->perteneceASocio(ci_user) && r->perteneceAMedico(ci_doc) &&
			   r->getFechaReserva() == fecha_reserva && r->getFechaConsulta() == fecha_consulta){
				r->registrar();
				break;
			}
		}
		it++;
	}
	if(it == this->consultas.end())
		throw std::invalid_argument("No existe la reserva");
}

void ControladorConsultas::registroEmergencia(int ci_user,int ci_doc,string motivo,Fecha fecha_consulta){
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	Socio* s = ms->find(ci_user);
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	Medico* m = mm->find(ci_doc);
	Emergencia* e = new Emergencia(fecha_consulta, motivo, m, s);
	s->agregarConsulta(e);
	m->agregarConsulta(e);
}

set<DataConsulta*> ControladorConsultas::consultasActivasXUsuario(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	RelojSistema* rs = RelojSistema::getInstance();
	ManejadorSocios* cs = ManejadorSocios::getInstance();
	Socio* s = cs->find(cu->getUsuarioLogueado()->getCI());
	set<DataConsulta*> dc;
	Fecha fecha_sistema;
	fecha_sistema =Fecha(rs->getFechaSistema().getDia(),rs->getFechaSistema().getMes(),rs->getFechaSistema().getAnio(),rs->getFechaSistema().getHora(),rs->getFechaSistema().getHora());
	for(set<Consulta*>::iterator it = s->getConsultasSolicitadas().begin();it != s->getConsultasSolicitadas().end();++it){
		if(((*it)->getFechaConsulta() > fecha_sistema/*rs->getFechaSistema()*/) && (*it)->perteneceASocio(cu->getUsuarioLogueado()->getCI())){
			DataConsulta* aux = (*it)->getDataConsulta();
			dc.insert(aux);
		}
	}
	return dc;
}

void ControladorConsultas::devolverConsulta(Fecha fecha_consulta){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	Socio* s = ms->find(cu->getUsuarioLogueado()->getCI());
	Consulta* r = s->devolverReserva(fecha_consulta);
	Medico* m = r->getMedico();
	m->devolverConsulta(r);
	this->consultas.erase(r);
	delete r;
}

set<DataConsulta*> ControladorConsultas::consultasDelDia(Fecha fecha_sistema){
	set<DataConsulta*> res;
	for(set<Consulta*>::iterator it = this->consultas.begin();it != this->consultas.end();++it){
		if(typeid(*it) == typeid(ConReserva)){
			ConReserva* r = dynamic_cast<ConReserva*>(*it);
			if(r->getFechaConsulta() > fecha_sistema){
				DataConsulta* aux = r->getDataConsulta();
				res.insert(aux);
			}
		}
	}
	return res;
}

DataConsulta* ControladorConsultas::seleccionarConsultaCI(int ci_user){
	set<DataConsulta*> res;
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	int ci_doc = cu->getUsuarioLogueado()->getCI();
	for(set<Consulta*>::iterator it = this->consultas.begin();it != this->consultas.end();++it){
		if( (*it)->esDeHoy() and
			(*it)->perteneceAMedico(ci_doc) and
			(*it)->perteneceASocio(ci_user)){
				return (*it)->getDataConsulta();
		}
	}
	return NULL;
}

DataHistorial* ControladorConsultas::obtenerHistorial(int ci_user,Fecha fecha_sistema){
	DataHistorial* dh = new DataHistorial();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	for(map<int,Medico*>::iterator m = mm->getMedicos().begin(); m != mm->getMedicos().end();++m){
		DataMedico* dm = m->second->obtenerHistorial(ci_user);
		//if(&dm != NULL)
			dh->agregarMedico(dm);
	}
	return dh;
}

void ControladorConsultas::seleccionarCriterio(int criterio){
	if(criterio == 1)
		this->estrategia = new MedicosDelPaciente(this->ci_tratante);
	else
		this->estrategia = new MedicosLibres(this->cantidad_estrategia);
}

void ControladorConsultas::setCantidad(int cant){
	this->cantidad_estrategia = cant;
}

set<DataMedico*> ControladorConsultas::ejecutarStrategy(){
	return this->estrategia->algoritmoDeSeleccion();
}

set<DataUsuario*> ControladorConsultas::obtenerMedicos(){
	set<DataUsuario*> medicos_disponibles;
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	map<int, Medico*> medicos = mm->getMedicos();
	if(!mm->getMedicos().empty()){
		for(map<int, Medico*>::iterator it = medicos.begin(); it != medicos.end();++it){
			if(it->second->libreParaFecha(this->fecha_consulta)){
				DataUsuario* du = it->second->getUsuario()->getDataUsuario();
				medicos_disponibles.insert(du);
			}
		}
	}else{
		throw::invalid_argument("No hay medicos en el sistema");
	}
	return medicos_disponibles;
}

void ControladorConsultas::ingresarFechaConsulta(Fecha fecha_consulta){
	this->fecha_consulta = fecha_consulta;
}

void ControladorConsultas::ingresarConsulta(int ci_doc){
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	RelojSistema* rs = RelojSistema::getInstance();
	Medico* m = mm->find(ci_doc);
	Socio* s = ms->find(cu->getUsuarioLogueado()->getCI());
	ConReserva* r = new ConReserva(this->fecha_consulta,rs->getFechaSistema(),m,s);
	m->agregarConsulta(r);
	s->agregarConsulta(r);
	this->consultas.insert(r);
}
