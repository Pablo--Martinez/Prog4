#ifndef DIAGNOSTICO
#define DIAGNOSTICO

#include <string>
#include <iostream>
#include <set>
#include "DataDiagnostico.h"

using namespace std;

class Tratamiento;

class Diagnostico{
	private:
		string codigo;
		string etiqueta;
		string descripcion;
		set<Tratamiento*> tratamientos;
	public:
		Diagnostico();
		Diagnostico(string,string,string);
		~Diagnostico();
		string getCodigo();
		string getEtiqueta();
		string getDescripcion();
		void agregarTratamiento(Tratamiento*);
		set<Tratamiento*> getTratamientos();
		DataDiagnostico getDataDiagnostico();
		void show();
};

#include "Tratamiento.h"

#endif
