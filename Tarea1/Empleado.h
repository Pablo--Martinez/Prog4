#ifndef EMPLEADO
#define EMPLEADO

#include "Paga.h"
#include <string>
#include <iostream>

using namespace std;

class Empresa;

class Empleado{
	private:
	    char* nombre;
	    char* ci;
	    int edad;
	    Paga valor_hora;
	    Empresa* empresa;
	public:
		Empleado();
	    Empleado(char* nombre, char* ci, int edad, Paga valor_hora, Empresa* e);
	    virtual ~Empleado();
	    char* get_nombre();
	    char* get_ci();
	    int get_edad();
	    Paga get_valor_hora();
	    Empresa* get_empresa();
	    virtual void imprimir()=0;
	    virtual Paga get_sueldo_peso()=0;
	    virtual Paga get_sueldo_dolar()=0;
};

#include "Empresa.h"

#endif
