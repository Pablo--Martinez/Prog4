#ifndef MANEJADORSOCIOS_H_
#define MANEJADORSOCIOS_H_

#include <map>
#include <iostream>
#include <stdexcept>
#include "Socio.h"

using namespace std;

class ManejadorSocios{
	private:
		ManejadorSocios();
        static ManejadorSocios* instancia;
        map<int,Socio*> socios;
	public:
		static ManejadorSocios* getInstance();
		//~ManejadorSocios();
		void agregarSocio(Socio*);
		Socio* find(int);
		map<int,Socio*> getSocios();
		void show();
};

#endif /* MANEJADORSOCIOS_H_ */
