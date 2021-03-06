#ifndef TRATAMIENTO
#define TRATAMIENTO

#include <string>
#include <map>
#include "Fecha.h"
#include "Medicamento.h"
#include "DataTratamiento.h"

using namespace std;

class Tratamiento{
	private:
		string descripcion;
	public:
		Tratamiento();
		Tratamiento(string);
		virtual ~Tratamiento()=0;
		string getDescripcion();
		DataTratamiento* getDataTratamiento();
		virtual void show()=0;
};

#endif
