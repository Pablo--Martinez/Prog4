#include "DataConReserva.h"

DataConReserva::DataConReserva(Fecha fecha_consulta,Fecha fecha_reserva, bool asiste): DataConsulta(fecha_consulta) {
	this->fecha_reserva = fecha_reserva;
	this->asiste = asiste;
}

DataConReserva::~DataConReserva() {}

Fecha DataConReserva::getFechaReserva(){
	return this->fecha_reserva;
}

bool DataConReserva::getAsiste(){
	return this->asiste;
}


