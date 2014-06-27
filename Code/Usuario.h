#ifndef USUARIO
#define USUARIO

#include <string>
#include <iostream>
#include <set>
#include "Fecha.h"
#include "RelojSistema.h"
//#include "DataUsuario.h"

using namespace std;

enum Sexo {F,M};
enum TSesion {PV, CM, APD};

class Rol;
class DataUsuario;
class DataAltaReactivacion;

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
		void agregarRol(Rol*);
		TSesion getTipoSesion();
		bool verificarPass(string);
		set<DataAltaReactivacion*> obtenerUsuariosAltaReactivacion();
		void activar(string);
		void desactivar();
		void reactivar();
		DataUsuario* getDataUsuario();
		void show();	
};

#include "Rol.h"
#include "DataUsuario.h"
#include "DataAltaReactivacion.h"

#endif
