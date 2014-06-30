#ifndef MANEJADORREPRESENTACIONES_H_
#define MANEJADORREPRESENTACIONES_H_

#include <string>
#include <map>
#include <set>
#include <iostream>
#include "DataRep.h"

using namespace std;

class ManejadorRepresentaciones
{
	private:
		ManejadorRepresentaciones();
		static ManejadorRepresentaciones* instancia;
		map<string, set<DataRep*> > representaciones;
		map<string,DataRep*> categorias;
	public:
		static ManejadorRepresentaciones* getInstance();
		~ManejadorRepresentaciones();
		void agregarRepresentacion(string,string,string);
		void agregarCategoria(string,string);
		void ingresarRepresentaciones(string,set<DataRep*>);
		set<DataRep*> obtenerRepresentacionesCat(string);
		bool existeRepresentacion(string,string);
		DataRep* obtenerRepresentacion(string,string);
		bool existeRepresentacion(string,string,string);
		bool existeCategoria(string);
		map<string,DataRep*> obtenerCategorias();
};

#endif /* MANEJADORREPRESENTACIONES_H_ */
