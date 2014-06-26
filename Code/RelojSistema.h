#ifndef RELOJSISTEMA_H_
#define RELOJSISTEMA_H_

#include "Fecha.h"

class RelojSistema {
	private:
		Fecha fecha_sistema;
		static RelojSistema* instancia;
		RelojSistema();
		//RelojSistema(int,int,int,int,int);
	public:
		static RelojSistema* getInstance();
		Fecha getFechaSistema();
		void modificarFechaSistema(int,int,int,int,int);
		virtual ~RelojSistema();
};

#endif /* RELOJSISTEMA_H_ */
