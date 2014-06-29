#include "Socio.h"
#include "Rol.h"


Socio::Socio(){}

Socio::Socio(Usuario* u): Rol(u){}

Socio::~Socio(){
	//FALTA HACER
}

tipoRol Socio::getTipoRol() {
	return socio;
}


void Socio::agregarConsulta(Consulta* c){
	this->solicita.insert(c);
}

Consulta* Socio::devolverReserva(Fecha fecha_consulta){
	set<Consulta*>::iterator it = this->solicita.begin();
	while(it != this->solicita.end()){
		if((*it)->getFechaConsulta() == fecha_consulta){
			this->solicita.erase(it);
			return *it;
		}
		it++;
	}
	return NULL;
}

set<Consulta*> Socio::getConsultasSolicitadas(){
	return this->solicita;
}

set<DataAltaReactivacion*> Socio::obtenerUsuariosAltaReactivacion() {
	set<DataAltaReactivacion*> setVacio;
	return setVacio;
}

void Socio::attach(IObserver* o){
	this->observadores.insert(o);
}

void Socio::unattach(IObserver* o){
	set<IObserver*>::iterator it = this->observadores.begin();
	while(it != this->observadores.end()){
		if((*it)->getUsuario()->getCI() == o->getUsuario()->getCI()){
			this->observadores.erase(it);
			return;
		}
		++it;
	}
}

void Socio::notifyall(Medico* medico,Fecha fecha,bool nuevoDiag){
	set<IObserver*>::iterator it = this->observadores.begin();
	while(it != this->observadores.end()){
		if(*it != medico)
			(*it)->notify(this->getUsuario()->getCI(),medico,fecha,nuevoDiag);
		it++;
	}
}

set<DataMedico*> Socio::obtenerMedicosDelPaciente(){
	Fecha fecha_sist;//
	set<DataMedico*> medicosDelPaciente;
	set<Consulta*> consultas = this->getConsultasSolicitadas();
	for(set<Consulta*>::iterator consulta = consultas.begin();consulta != consultas.end();++consulta) {
		Medico* m = (*consulta)->getMedico();
		DataMedico* dm = m->getDataMedico();
		medicosDelPaciente.insert(dm);
	}
	return medicosDelPaciente;
}

void Socio::show(){
	if(this != NULL){
		cout << "Usuario: "<< endl;
		this->getUsuario()->show();;
		cout << "Consultas solicitadas:" << endl;
		for (set<Consulta*>::iterator it=this->solicita.begin(); it!=this->solicita.end(); ++it){
			(*it)->show();
			cout << "----------------" << endl;
		}
	}
}

DataEstado* Socio::obtenerEstadoReservas(){

	set<Consulta*> consultas = this->getConsultasSolicitadas();
	if (!consultas.empty()){
		int sinasistencia = 0;
		DataEstado* estado = new DataEstado(sinasistencia);
		for(set<Consulta*>::iterator consulta = consultas.begin();consulta != consultas.end();++consulta) {
				DataConsulta* dc = (*consulta)->getDataConsulta();
				DataConReserva* cr = dynamic_cast<DataConReserva*>(dc);
				if(cr){
					estado->agregarConReserva(cr);
				    if(!cr->getAsiste()){
				    	sinasistencia++;
				    }
				}
		}
		estado->setCantConsultasSinAsistencias(sinasistencia);

		return estado;
	}else{
		throw::invalid_argument("No hay consultas solicitadas para el socio");
	}

}
