#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

#include <set>
#include "Rol.h"

using namespace std;

class Usuario;

class Administrador: public Rol{
	private:
		set<Usuario*> daDeAlta;
		set<Usuario*> reactiva;
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