#ifndef MANEJADORMEDICOS_H_
#define MANEJADORMEDICOS_H_

#include <set>
#include <iostream>
#include "Rol.h"

using namespace std;

class ManejadorMedicos{
	private:
       ManejadorMedicos();
       static ManejadorMedicos* instancia;
       set<Medico*> medicos;
	public:
		static ManejadorMedicos* getInstance();
		//~ManejadorMedicamentos();
		void agregarMedico(Medico*);
		Medico* find(int);
		void show();
};

#endif /* MANEJADORMEDICOS_H_ */
