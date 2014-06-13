#ifndef ROL
#define ROL

#include <set>
#include <iostream>
#include "Consulta.h"
//#include "HistorialNotificaciones.h"
//#include "Notificacion.h"
//#include "IObserver.h"

using namespace std;

class Usuario;
class Notificacion;
//class IObserver;

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

class IObserver: public Rol{
	public:
		IObserver(Usuario*);
		virtual void notify(int,Medico*,Fecha,bool)=0;
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

class Medico: public IObserver{
	private:
		set<Consulta*> atiende;
		//HistorialNotificaciones* notificaciones;
		map<int, set<Notificacion*> > notificaciones;
	public:
		Medico();
		Medico(Usuario*);
		~Medico();
		set<Consulta*> getConsultasAtiende();
		void agregarConsulta(Consulta*);
		void devolverConsulta(Consulta*);
		void seguir(Socio*);
		void notify(int,Medico*,Fecha,bool);
		void show();
		void showNotificaciones();
};

class Socio: public Rol{
	private:
		set<Consulta*> solicita;
		set<IObserver*> observadores;
	public:
		Socio();
		Socio(Usuario*);
		~Socio();
		void agregarConsulta(Consulta*);
		void devolverReserva(Fecha);
		set<Consulta*> getConsultasSolicitadas();
		// Operaciones de observador
		void attach(IObserver*);
		void unattach(IObserver*);
		void notifyall(Medico*,Fecha,bool);
		//Opeaciones de strategy
		//set<DataMedico> obtenerMedicosDelPaciente();
		void show();
};

#include "Usuario.h"
#include "Notificacion.h"
//#include "IObserver.h"

#endif
