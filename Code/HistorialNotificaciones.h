#ifndef HISTORIALNOTIFICACIONES_H_
#define HISTORIALNOTIFICACIONES_H_

#include <set>
#include <map>
#include "Notificacion.h"

using namespace std;

class HistorialNotificaciones{
	private:
		map<int,set<Notificacion*> > notificaciones;
		HistorialNotificaciones();
		static HistorialNotificaciones* instancia;
	public:
		~HistorialNotificaciones();
		static HistorialNotificaciones* getInstance();
		map<int,set<Notificacion*> > getNotificaciones();
		void add(int,Notificacion*);
};

#endif /* HISTORIALNOTIFICACIONES_H_ */
