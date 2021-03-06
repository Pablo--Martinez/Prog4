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
		DataConReserva(Fecha,Fecha,bool,int);
		virtual ~DataConReserva();
		Fecha getFechaReserva();
		bool getAsiste();
		void show();
};

#endif /* DATACONRESERVA_H_ */
