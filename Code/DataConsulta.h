
#ifndef DATACONSULTA_H_
#define DATACONSULTA_H_

#include <set>
#include "Fecha.h"
#include "DataDiagnostico.h"

using namespace std;

class DataConsulta{
	private:
		Fecha fecha_consulta;
		int ci;
		set<DataDiagnostico*> diagnosticos;
	public:
		DataConsulta();
		DataConsulta(Fecha);
		virtual ~DataConsulta();
		Fecha getFechaConsulta();
		int getCI();
		void agregarDiagnostico(DataDiagnostico*);
		set<DataDiagnostico*> getDiagnosticos();
		virtual void show()=0;
};

#endif /* DATACONSULTA_H_ */
