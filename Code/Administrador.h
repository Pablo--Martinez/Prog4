#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

#include <set>
#include "Rol.h"
#include "Strategy.h"
#include "MedicosDelPaciente.h"
#include "MedicosLibres.h"
#include "DataAltaReactivacion.h"

using namespace std;

class Usuario;

class Administrador: public Rol{
	private:
		set<DataAltaReactivacion*> deAltaReactivados;
	public:
		Administrador();
		Administrador(Usuario*);
		~Administrador();
		tipoRol getTipoRol();
		void agregarUsuarioAltaReactivacion(DataUsuario*, Fecha, bool);
		set<DataAltaReactivacion*> obtenerUsuariosAltaReactivacion();
		void show();
};

#include "Usuario.h"

#endif /* ADMINISTRADOR_H_ */
