#ifndef CONTROLADORDIAGNOSTICOS_H_
#define CONTROLADORDIAGNOSTICOS_H_

#include <stdexcept>
#include <map>
#include <set>
#include <string>
#include "Diagnostico.h"
#include "ManejadorRepresentaciones.h"

using namespace std;

class ControladorDiagnosticos{
	private:
		static ControladorDiagnosticos* instancia;
		ControladorDiagnosticos();
		set<Diagnostico*> diagnosticos;
		set<Diagnostico*> diagnosticosTemp;
		Diagnostico* diag;
		set<string> letrasCat;
		string catSeleccionada;
		string etiquetaSeleccionada;
		map<string, set<DataRep*> > representaciones;
		map<string,DataRep*> categorias;
		DataRep* categoriaSeleccionada;
	public:
		static ControladorDiagnosticos* getInstance();
		Diagnostico* getDiagnostico();
		set<string> obtenerCategorias();
		set<DataRep*> obtenerRepresentaciones(string);
		string obtenerCategoriaSeleccionada();
		void altaDiagnostico(string,string,string);
		void seleccionarCategoria(string);
		void ingresarCategoria(string,string);
		bool existeRepDiag(string,string);
		void ingresarRepDiag(string,string);
		void confirmarRepEst();
};

#endif /* CONTROLADORDIAGNOSTICOS_H_ */
