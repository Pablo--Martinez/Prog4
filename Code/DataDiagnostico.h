#ifndef DATADIAGNOSTICO_H_
#define DATADIAGNOSTICO_H_

#include "DataRep.h"
#include "DataTratamiento.h"

class DataDiagnostico {
	private:
		DataRep* representacion;
		string descripicon;
		set<DataTratamiento*> tratamientos;
	public:
		DataDiagnostico();
		DataDiagnostico(DataRep*,string);
		virtual ~DataDiagnostico();
		void agregarTratamiento(DataTratamiento*);
		DataRep* getDataRep();
		string getDescripcion();
		set<DataTratamiento*> getTratamientos();
};

#endif /* DATADIAGNOSTICO_H_ */
