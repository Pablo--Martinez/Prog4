#ifndef USUARIO
#define USUARIO

#include <string>
#include <iostream>
#include <set>
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
		set<Rol*> roles;
	
	public:
		Usuario();
		Usuario(int,string,string,Sexo,bool,Fecha);
		int getCI();
		string getNombre();
		string getApellido();
		Fecha getNacimiento();
		Sexo getSexo();
		bool getEstado();
		int getEdad(Fecha);
		void agregarRol(Rol*);
		void show();	
};

#include "Rol.h"
#endif
