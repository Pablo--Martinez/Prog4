#include "Emergencia.h"

Emergencia::Emergencia(){}

Emergencia::Emergencia(Fecha fecha_consulta,string motivo, Medico* medico, Socio* socio):Consulta(fecha_consulta,medico,socio){
	this->motivo = motivo;
}

Emergencia::~Emergencia(){}

string Emergencia::getMotivo(){
	return this->motivo;
}

DataConsulta ConReserva::getDataConsulta(){
	DataConReserva res = DataConReserva(this->getFechaConsulta(),this->fecha_reserva,this->asiste);
	for(set<Diagnostico*>::iterator it = this->getDiagnosticos().begin();it!=this->getDiagnosticos().end();++it){
		res.agregarDiagnostico((&(*it)->getDataDiagnostico()));
	}
	return res

}
void Emergencia::show(){
	cout << "Consulta de emergecia: " << endl;
	cout << "Fecha de consulta: "; this->getFechaConsulta().show();
	cout << "Medico tratante: "; this->getMedico()->show();
	set<Diagnostico*>::iterator pos;
	pos = this->getDiagnosticos().begin();
	int i=0;

	while(pos != this->getDiagnosticos().end()){
		cout << "Diagnostico" << i << ": " << endl;
		(*pos)->show();
		pos++;
		i++;
	}
}
