#ifndef MANEJADORADMINISTRADORES_H_
#define MANEJADORADMINISTRADORES_H_

#include <map>
#include <stdexcept>
#include "Administrador.h"

using namespace std;

class ManejadorAdministradores {
	private:
		ManejadorAdministradores();
		static ManejadorAdministradores* instancia;
		map<int,Administrador*> administradores;
	public:
		static ManejadorAdministradores* getInstance();
		void agregarAdministrador(Administrador*);
		Administrador* find(int);
};
#endif /* MANEJADORADMINISTRADORES_H_ */

