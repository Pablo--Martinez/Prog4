#ifndef ROL
#define ROL

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
		bool esAdministrador();
		bool esMedico();
		bool esSocio();
		virtual void show()=0;
};

#include "Usuario.h"

#endif
