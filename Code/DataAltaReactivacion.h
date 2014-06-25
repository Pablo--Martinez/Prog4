#ifndef DATAALTAREACTIVACION_H_
#define DATAALTAREACTIVACION_H_

#include <set>
#include <string>
#include "DataUsuario.h"
#include "Fecha.h"

//class DataUsuario;

using namespace std;

class DataAltaReactivacion{
	private:
		DataUsuario* usuario;
		Fecha fechaAltaReactivacion;
		bool tipoOperacion;
	public:
		DataAltaReactivacion();
		DataAltaReactivacion(DataUsuario*,Fecha,bool);
		virtual ~DataAltaReactivacion();
		DataUsuario* getUsuario();
		Fecha getFecha();
		bool getTipoOperacion();
};

#endif /* DATAALTAREACTIVACION_H_ */
