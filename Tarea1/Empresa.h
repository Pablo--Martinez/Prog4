#ifndef EMPRESA
#define EMPRESA

#include "Paga.h"
#include <iostream>
#include <iostream>
#include <stdexcept>
#include <string.h>

using namespace std;

class Empleado;
class Jornalero;
class Fijo;

const int MAX_EMPLEADO = 50;

class Empresa {
  private:
    int rut;
    char* nombre;
    char* nombre_legal;
    Empleado** empleados;
  public:
	Empresa();
    Empresa(char* nombre, char* nombre_legal, int rut);
    ~Empresa();
    char* get_nombre();
    char* get_nombre_legal();
    int get_rut();
    void agregar_empleado(Empleado*);
    void imprimir_empleados();
    Paga total_sueldo_peso();
    Paga total_sueldo_dolar();
};

ostream& operator<<(ostream &o, Empresa &e);

#include "Empleado.h"
#include "Jornalero.h"
#include "Fijo.h"

#endif
