#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

#include <set>
#include "Rol.h"
#include "Strategy.h"
#include "MedicosDelPaciente.h"
#include "MedicosLibres.h"

using namespace std;

class Usuario;

class Administrador: public Rol{
	private:
		set<Usuario*> daDeAlta;
		set<Usuario*> reactiva;
		//Strategy* criterio;
	public:
		Administrador();
		Administrador(Usuario*);
		~Administrador();
		set<Usuario*> getUsuariosAlta();
		set<Usuario*> getUsuariosReactivados();
		void show();
};

#include "Usuario.h"

#endif /* ADMINISTRADOR_H_ */
