#ifndef USUARIO
#define USUARIO

#include <string>
#include <iostream>
#include <list>
#include "Fecha.h"

using namespace std;

enum Sexo {F,M};

class Rol;

class Usuario{
	private:
		int ci;
		string nombre;
		string apellido;
		Fecha nacimiento;
		Sexo sexo;
		bool estado;
		list<Rol*> roles;
	
	public:
		Usuario();
		Usuario(int,string,string,Sexo,bool,Fecha,list<Rol*>);
		int getCI();
		string getNombre();
		string getApellido();
		Fecha getNacimiento();
		Sexo getSexo();
		bool getEstado();
		int getEdad(Fecha);
		void show();	
};

#include "Rol.h"
#endif
