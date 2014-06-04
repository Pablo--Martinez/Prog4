#ifndef DIAGNOSTICO
#define DIAGNOSTICO

#include <string>
#include <iostream>
#include <list>

using namespace std;

class Tratamiento;

class Diagnostico{
	private:
		string codigo;
		string etiqueta;
		string descripcion;
		list<Tratamiento*> tratamientos;
	public:
		Diagnostico();
		Diagnostico(string,string,string);
		string getCodigo();
		string getEtiqueta();
		string getDescripcion();
		void agregarTratamiento(Tratamiento*);
		list<Tratamiento*> getTratamientos();
		void show();
};

#include "Tratamiento.h"

#endif
