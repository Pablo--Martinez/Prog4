#ifndef USUARIO
#define USUARIO

#include <string>
#include <iostream>
#include <set>
#include "Fecha.h"

using namespace std;

enum Sexo {F,M};
enum TSesion {PV, CM, APD};

class Rol;
class DataUsuario;

class Usuario{
	private:
		int ci;
		string nombre;
		string apellido;
		Fecha nacimiento;
		Sexo sexo;
		bool estado;
		string pass;
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
		void agregarRol(Rol*); //void agregarRol(DataCat) ?
		TSesion getTipoSesion();
		bool verificarPass(string);
		void activar(string);
		void reactivar();
		DataUsuario getDataUsuario(Fecha);
		void show();	
};

#include "Rol.h"
#include "DataUsuario.h"

#endif
