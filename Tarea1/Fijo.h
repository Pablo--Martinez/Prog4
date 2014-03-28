#ifndef FIJO
#define FIJO

#include "Empleado.h"
#include "Paga.h"
#include <iostream>

using namespace std;

class Empresa;

class Fijo: public Empleado {
    private:
        Paga calculoPaga();
	public:
		Fijo();
	    Fijo(char* nombre, char*ci, int edad, Paga valor_hora, Empresa* e);
	    ~Fijo();
	    virtual void imprimir();
	    virtual Paga get_sueldo_peso();
	    virtual Paga get_sueldo_dolar();
};

#include "Empresa.h"
#endif

