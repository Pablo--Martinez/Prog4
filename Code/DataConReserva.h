#ifndef DATACONRESERVA_H_
#define DATACONRESERVA_H_

#include "DataConsulta.h"

using namespace std;

class DataConReserva: public DataConsulta {
	private:
		Fecha fecha_reserva;
		bool asiste;
	public:
		DataConReserva();
		DataConReserva(Fecha,Fecha,bool);
		virtual ~DataConReserva();
		Fecha getFechaReserva();
		bool getAsiste();
};

#endif /* DATACONRESERVA_H_ */
