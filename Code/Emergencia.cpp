#include "Emergencia.h"

Emergencia::Emergencia(){}

Emergencia::Emergencia(Fecha fecha_consulta,string motivo, Medico* medico, Socio* socio):Consulta(fecha_consulta,medico,socio){
	this->motivo = motivo;
}

Emergencia::~Emergencia(){}

string Emergencia::getMotivo(){
	return this->motivo;
}

DataConsulta* Emergencia::getDataConsulta(){
	if(this != NULL){
		DataEmergencia* res =  new DataEmergencia(this->getFechaConsulta(),this->motivo);
		set<Diagnostico*> diags = this->getDiagnosticos();
		for(set<Diagnostico*>::iterator it = diags.begin();it!=diags.end();++it){
			DataDiagnostico* dd = (*it)->getDataDiagnostico();
			res->agregarDiagnostico(dd);
		}
		return res;
	}
	return NULL;
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
