#ifndef ROL
#define ROL

enum tipoRol {administrador,socio,medico};

#include <set>
#include "DataAltaReactivacion.h"

using namespace std;

class Usuario;

class Rol{
	private:
		Usuario* usuario;
	public:
		Rol();
		Rol(Usuario*);
		virtual ~Rol()=0;
		Usuario* getUsuario();
		//bool esAdministrador();
		//bool esMedico();
		//bool esSocio();
		virtual void show()=0;
		virtual tipoRol getTipoRol()=0;
		//virtual set<DataAltaReactivacion*> obtenerUsuariosAltaReactivacion()=0;
};

#include "Usuario.h"

#endif
