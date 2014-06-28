#ifndef MEDICO_H_
#define MEDICO_H_

#include "IObserver.h"
#include "DataHistorial.h"
#include "Consulta.h"
#include "ManejadorSocios.h"

using namespace std;

class Usuario;
class Notificacion;

class Medico: public IObserver{
	private:
		set<Consulta*> atiende;
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
		DataMedico* getDataMedico();
		DataMedico* obtenerHistorial(int);
		bool libreHoraYConsultas(int cantConsultas);
		bool libreParaFecha(Fecha);
		void show();
		void showNotificaciones(int);
		map<int,set<Notificacion*> > getNotificaciones();
		tipoRol getTipoRol();
		virtual set<DataAltaReactivacion*> obtenerUsuariosAltaReactivacion();
};

#include "Usuario.h"
#include "Notificacion.h"

#endif /* MEDICO_H_ */
