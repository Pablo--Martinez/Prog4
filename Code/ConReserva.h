#ifndef CONRESERVA_H_
#define CONRESERVA_H_

#include "Consulta.h"

class ConReserva: public Consulta{
	private:
		Fecha fecha_reserva;
		bool asiste;
	public:
		ConReserva();
		ConReserva(Fecha,Fecha,Medico*,Socio*);
		~ConReserva();
		Fecha getFechaReserva();
		void registrar();
		bool getAsiste();
		virtual DataConsulta getDataConsulta();
		void show();
};

#endif /* CONRESERVA_H_ */
