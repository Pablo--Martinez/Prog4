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

using namespace std;

class Usuario;

class DataUsuario {
	private:
		int ci;
		string pass, nombre,apellido;
		Sexo sexo;
		int edad;
		bool activo;
		set<Rol*> roles;
	public:
		DataUsuario();
		//DataUsuario(Usuario*);
		DataUsuario(int,string,string,string,Sexo,int,bool,set<Rol*>);
		virtual ~DataUsuario();
		int getCI();
		string getPass();
		string getNombre();
		string getApellido();		
		int getEdad();
		Sexo getSexo();
		bool getActivo();
		set<Rol*> getRoles();
};

//#include "Usuario.h"

#endif /* DATAUSUARIO_H_ */
