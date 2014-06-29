#include "DataEstado.h"

DataEstado::DataEstado(int cantSinAsistencias){
	this->cantConsultasSinAsistencias = cantSinAsistencias;
}

void DataEstado::agregarConReserva(DataConReserva* cr){
	this->conReserva.insert(cr);
}

void DataEstado::setCantConsultasSinAsistencias(int sinasistencia){
	this->cantConsultasSinAsistencias = sinasistencia;
}

int DataEstado::getCantConsultasSinAsistencias(){
	return this->cantConsultasSinAsistencias;
}

set<DataConReserva*> DataEstado::getConReservas(){
	return this->conReserva;
}

void DataEstado::show(){
		if(this != NULL){
			cout << "Cantidad de consultas sin asistencias: " << this->cantConsultasSinAsistencias << endl;

			int i=0;
			for(set<DataConReserva*>::iterator it = conReserva.begin();it!=conReserva.end();++it){
					cout << "\t" << i+1 << ")" << "Fecha de consulta:" << endl;
					(*it)->getFechaConsulta().show();
					cout << "Fecha de reserva;" << endl;
					(*it)->getFechaReserva().show();
					i++;
			}
		}
}