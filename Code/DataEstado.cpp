#include "DataEstado.h"

DataEstado::DataEstado(int cantSinAsistencias){
	this->cantConsultasSinAsistencias = cantSinAsistencias;
}

DataEstado::~DataEstado(){
	for(set<DataConReserva*>::iterator it = this->conReserva.begin();it != this->conReserva.end();++it){
		delete (*it);
	}
	this->conReserva.clear();
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
					cout << "\t" << i+1 << ")" << "Fecha de consulta:";
					cout << "\t"; (*it)->getFechaConsulta().show(); cout << endl;
					cout << "\t"; cout << "Fecha de reserva;";
					cout << "\t"; (*it)->getFechaReserva().show(); cout << endl;
					i++;
			}
		}
}
