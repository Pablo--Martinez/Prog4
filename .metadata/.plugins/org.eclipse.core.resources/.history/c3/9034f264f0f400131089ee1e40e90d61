#ifndef DATAHISTORIAL_H_
#define DATAHISTORIAL_H_

#include "DataUsuario.h"
#include "DataMedico.h"

using namespace std;

class DataHistorial {
	private:
		DataUsuario* usuario;
		set<DataMedico*> medico;
	public:
		DataHistorial();
		DataHistorial(DataUsuario*);
		virtual ~DataHistorial();
		void agregarMedico(DataMedico*);
		DataUsuario* getUsuario();
		DataMedico* getMedico();
};

#endif /* DATAHISTORIAL_H_ */
