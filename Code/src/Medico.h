#ifndef MEDICO_H_
#define MEDICO_H_

#include "IObserver.h"
//#include "Rol.h"
#include "DataHistorial.h"
#include "Consulta.h"
#include "ManejadorSocios.h"
//#include "HistorialNotificaciones.h"

using namespace std;

class Usuario;
class Notificacion;
//class HistorialNotificaciones;

class Medico: public IObserver{
	private:
		set<Consulta*> atiende;
		//HistorialNotificaciones* notificaciones;
		map<int,set<Notificacion*> > notificaciones;
	public:
		Medico();
		Medico(Usuario*);
		~Medico();
		set<Consulta*> getConsultasAtiende();
		void agregarConsulta(Consulta*);
		void devolverConsulta(Consulta*);
		void seguir(Socio*);
		void notify(int,Medico*,Fecha,bool);
		DataMedico getDataMedico(Fecha);
		DataMedico obtenerHistorial(int,Fecha);
		void show();
		void showNotificaciones();
		bool libreHoraYConsultas(int cantConsultas);
};

#include "Usuario.h"
#include "Notificacion.h"
//#include "HistorialNotificaciones.h"

#endif /* MEDICO_H_ */
