#ifndef IOBSERVER_H_
#define IOBSERVER_H_

#include "Fecha.h"
#include "Rol.h"

class Usuario;
class Medico;

using namespace std;

class IObserver: public Rol{
	public:
		IObserver(Usuario*);
		virtual void notify(int,Medico*,Fecha,bool)=0;
		virtual void show()=0;
};

#include "Usuario.h"
#include "Medico.h"

#endif /* IOBSERVER_H_ */
