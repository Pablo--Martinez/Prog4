#ifndef MANEJADORSOCIOS_H_
#define MANEJADORSOCIOS_H_

#include <map>
#include <iostream>
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
		void show();
};

#endif /* MANEJADORSOCIOS_H_ */