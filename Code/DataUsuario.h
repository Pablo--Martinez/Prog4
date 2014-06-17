#ifndef DATAUSUARIO_H_
#define DATAUSUARIO_H_

#include <string>
#include "Usuario.h"

using namespace std;

//class Usuario;

class DataUsuario {
	private:
		int ci;
		string nombre,apellido;
		Sexo sexo;
		int edad;
		bool activo;
	public:
		DataUsuario();
		//DataUsuario(Usuario*);
		DataUsuario(int,string,string,Sexo,int,bool);
		virtual ~DataUsuario();
		int getCI();
		string getNombre();
		string getApellido();
		int getEdad();
		bool getActivo();
};

//#include "Usuario.h"

#endif /* DATAUSUARIO_H_ */
