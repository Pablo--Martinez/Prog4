#ifndef JORNALERO
#define JORNALERO

#include "Paga.h"
#include "Empleado.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class Empresa;

class Jornalero: public Empleado {
	private:
        int horas;
        Paga calculoPaga();
	public:
		Jornalero();
	    Jornalero(char* nombre, char* ci, int edad, Paga valor_hora, int horas, Empresa* e);
	    ~Jornalero();
	    int get_horas();
	    virtual void imprimir();
	    virtual Paga get_sueldo_peso();
	    virtual Paga get_sueldo_dolar();
};

#include "Empresa.h"

#endif
