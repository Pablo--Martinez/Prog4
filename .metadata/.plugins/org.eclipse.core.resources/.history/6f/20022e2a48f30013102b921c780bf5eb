#ifndef HISTORIALNOTIFICACIONES_H_
#define HISTORIALNOTIFICACIONES_H_

#include <set>
#include <map>
#include "Rol.h"
#include "Notificacion.h"

//USANDO CONJUNTO DE SINGLETON
/*
class HistorialNotificaciones{
	private:
		set<Notificacion*> notificaciones;
		Medico* medico;
		Socio* socio;
		HistorialNotificaciones();
		HistorialNotificaciones(Socio*, Medico*);
		static HistorialNotificaciones* instancia;
	public:
		static HistorialNotificaciones* getInstance(Socio*,Medico*);
		void add(Notificacion*);
};*/

//USANDO MAP Y UN UNICO SINGLETON
class HistorialNotificaciones{
	private:
		map<int,set<Notificacion*> > notificaciones;
		HistorialNotificaciones();
		static HistorialNotificaciones* instancia;
	public:
		~HistorialNotificaciones();
		static HistorialNotificaciones* getInstance();
		void add(int,Notificacion*);
};

#endif /* HISTORIALNOTIFICACIONES_H_ */
