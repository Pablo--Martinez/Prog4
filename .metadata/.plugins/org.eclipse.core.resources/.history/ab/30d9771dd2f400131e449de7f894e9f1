#ifndef ROL
#define ROL

#include <set>
#include <map>
#include <iostream>
#include "Consulta.h"

using namespace std;

class Usuario;
class Notificacion;
class IObserver;

class Rol{
	private:
		Usuario* usuario;
	public:
		Rol();
		Rol(Usuario*);
		virtual ~Rol()=0;
		Usuario* getUsuario();
		virtual void show()=0;
};

#include "Usuario.h"
#include "Notificacion.h"
#include "IObserver.h"

#endif
