#ifndef ROL
#define ROL

#include <set>
#include <iostream>
#include "Consulta.h"

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
		virtual void show()=0;
};

class Administrador: public Rol{
	private:
		set<Usuario*> daDeAlta;
	public:
		Administrador();
		Administrador(Usuario*);
		~Administrador();
		set<Usuario*> getUsuariosAlta();
		void show();
};

class Medico: public Rol{
	private:
		set<Consulta*> atiende;
	public:
		Medico();
		Medico(Usuario*);
		~Medico();
		set<Consulta*> getConsultasAtiende();
		void show();
};

class Socio: public Rol{
	private:
		set<Consulta*> solicita;
	public:
		Socio();
		Socio(Usuario*);
		~Socio();
		void agregarConsulta(Consulta*);
		void devolverReserva(Fecha);
		set<Consulta*> getConsultasSolicitadas();
		void show();
};

#include "Usuario.h"

#endif
