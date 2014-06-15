#ifndef MEDICO_H_
#define MEDICO_H_

#include "IObserver.h"
#include "Rol.h"
#include "HistorialNotificaciones.h"
#include "DataHistorial.h"

class Usuario;

class Medico: public IObserver{
	private:
		map<Fecha,Consulta*> atiende;
		HistorialNotificaciones* notificaciones;
	public:
		Medico();
		Medico(Usuario*);
		~Medico();
		map<Fecha,Consulta*> getConsultasAtiende();
		void agregarConsulta(Consulta*);
		void devolverConsulta(Consulta*);
		void seguir(Socio*);
		void notify(int,Medico*,Fecha,bool);
		DataMedico getDataMedico();
		DataMedico obtenerHistorial(int);
		void show();
		void showNotificaciones();
};

#include "Usuario.h"

#endif /* MEDICO_H_ */
