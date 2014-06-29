#ifndef DATAESTADO_H_
#define DATAESTADO_H_

#include "DataConReserva.h"

using namespace std;

class DataEstado{
	private:
		int cantConsultasSinAsistencias;
		set<DataConReserva*> conReserva;
	public:
		DataEstado();
		DataEstado(int);
		void agregarConReserva(DataConReserva*);
		void setCantConsultasSinAsistencias(int);
		int getCantConsultasSinAsistencias();
		set<DataConReserva*> getConReservas();
		void show();

};

#endif /* DATAESTADO_H_ */
