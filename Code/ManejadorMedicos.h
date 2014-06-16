#ifndef MANEJADORMEDICOS_H_
#define MANEJADORMEDICOS_H_

#include <map>
#include <iostream>
#include "Medico.h"

using namespace std;

class ManejadorMedicos{
	private:
       ManejadorMedicos();
       static ManejadorMedicos* instancia;
       map<int,Medico*> medicos;
	public:
		static ManejadorMedicos* getInstance();
		//~ManejadorMedicamentos();
		void agregarMedico(Medico*);
		Medico* find(int);
		map<int,Medico*> getMedicos();
		void show();
};

#endif /* MANEJADORMEDICOS_H_ */
