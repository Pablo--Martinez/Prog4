#ifndef IOBSERVER_H_
#define IOBSERVER_H_

#include "Rol.h"
#include "Medico.h"

class Usuario;

class IObserver: public Rol{
	public:
		IObserver(Usuario*);
		virtual void notify(int,Medico*,Fecha,bool)=0;
		virtual void show()=0;
};

#include "Usuario.h"

#endif /* IOBSERVER_H_ */
