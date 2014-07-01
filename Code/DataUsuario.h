#ifndef DATAUSUARIO_H_
#define DATAUSUARIO_H_

#include <string>
#include "Usuario.h"

#include <iostream>
#include <typeinfo>

#include <string>
#include <set>
#include "Usuario.h"
#include "Rol.h"
#include "DataRol.h"

using namespace std;

class Usuario;
class DataRol;

class DataUsuario {
	private:
		int ci;
		string pass;
		string nombre;
		string apellido;
		Sexo sexo;
		int edad;
		bool activo;
		bool esadmin;
		bool esmedico;
		bool essocio;
		//set<DataRol*> roles;
	public:
		DataUsuario();
		//DataUsuario(Usuario*);
		DataUsuario(int,string,string,string,Sexo,int,bool,bool,bool,bool);//set<DataRol*>
		virtual ~DataUsuario();
		int getCI();
		string getPass();
		string getNombre();
		string getApellido();		
		int getEdad();
		Sexo getSexo();
		bool getActivo();
		bool esAdmin();
		bool esMedico();
		bool esSocio();
		//set<DataRol*> getRoles();
		void show();
};

#endif /* DATAUSUARIO_H_ */
