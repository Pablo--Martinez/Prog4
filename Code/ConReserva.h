#ifndef CONRESERVA_H_
#define CONRESERVA_H_

#include "Consulta.h"
#include "DataConReserva.h"

using namespace std;

class ConReserva: public Consulta{
	private:
		Fecha fecha_reserva;
		bool asiste;
		//bool seAgregaronDiagnosticos;
	public:
		ConReserva();
		ConReserva(Fecha,Fecha,Medico*,Socio*);
		~ConReserva();
		Fecha getFechaReserva();
		//bool getSeAgregaronDiagnosticos();
		//void setSeAgregaronDiagnosticos(bool);
		void registrar();
		bool getAsiste();
		DataConsulta* getDataConsulta();
		void show();
};

#endif /* CONRESERVA_H_ */
