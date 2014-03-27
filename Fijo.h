#ifndef FIJO
#define FIJO

#include "Empleado.h"
#include "Paga.h"
#include <iostream>

using namespace std;

//class Empleado;
class Empresa;

class Fijo: public Empleado {
    private:
        Paga calculoPaga();
	public:
		Fijo();
	    Fijo(char* nombre, char*ci, int edad, Paga valor_hora, Empresa* e);
	    //Fijo(const Fijo&);
	    ~Fijo();
	    virtual Paga get_sueldo_peso();
	    virtual Paga get_sueldo_dolar();
};

ostream& operator<<(ostream &o, Fijo &f);

#include "Empresa.h"
#endif

