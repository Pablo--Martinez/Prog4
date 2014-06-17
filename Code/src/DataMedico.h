#ifndef DATAMEDICO_H_
#define DATAMEDICO_H_

#include <set>
#include "DataUsuario.h"
#include "DataConsulta.h"

using namespace std;

class DataMedico {
	private:
		DataUsuario* usuario;
		set<DataConsulta*> consultas;
	public:
		DataMedico();
		DataMedico(DataUsuario*);
		virtual ~DataMedico();
		void agregarConsulta(DataConsulta*);
		DataUsuario* getUsuario();
		set<DataConsulta*> getConsultas();
};

#endif /* DATAMEDICO_H_ */
