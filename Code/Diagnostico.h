#ifndef DIAGNOSTICO
#define DIAGNOSTICO

#include <string>
#include <iostream>
#include <set>
#include "Consulta.h"
#include "DataDiagnostico.h"

using namespace std;

class Tratamiento;

class Diagnostico{
	private:
		string codigo;
		string etiqueta;
		string descripcion;
		Consulta* consulta;
		set<Tratamiento*> tratamientos;
	public:
		Diagnostico();
		Diagnostico(string,string,string,Consulta*);
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
