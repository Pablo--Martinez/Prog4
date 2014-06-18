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
		string obtenerCatDiag();
		bool perteneceACat(string);
		void agregarTratamiento(Tratamiento*);
		set<Tratamiento*> getTratamientos();
		DataDiagnostico* getDataDiagnostico();
		DataRep* getDataRepDiagnostico();
		void show();
};

#include "Tratamiento.h"

#endif
