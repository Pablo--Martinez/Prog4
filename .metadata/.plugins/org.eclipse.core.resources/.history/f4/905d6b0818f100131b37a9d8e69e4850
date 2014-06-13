#ifndef MANEJADORSOCIOS_H_
#define MANEJADORSOCIOS_H_

#include <set>
#include <iostream>
#include "Rol.h"

using namespace std;

class ManejadorSocios{
	private:
		ManejadorSocios();
        static ManejadorSocios* instancia;
        set<Socio*> socios;
	public:
		static ManejadorSocios* getInstance();
		//~ManejadorSocios();
		void agregarSocio(Socio*);
		Socio* find(int);
		void show();
};

#endif /* MANEJADORSOCIOS_H_ */
