#ifndef DATAROL_H_
#define DATAROL_H_

#include <string>
#include "Rol.h"

using namespace std;

class DataRol {
	private:
		tipoRol tipo;
	public:
		DataRol();
		DataRol(tipoRol);
		virtual ~DataRol();
		tipoRol getTipoRol();
};

#endif /* DATAREP_H_ */
