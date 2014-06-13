#ifndef CONTROLADORUSUARIOS_H_
#define CONTROLADORUSUARIOS_H_

#include <set>
#include <string>
#include "Usuario.h"

using namespace std;

//enum TSesion {PV, CM, APD};

class ControladorUsuarios{
	private:
		ControladorUsuarios();
		static ControladorUsuarios* instancia;
		set<Usuario*> usuarios;
		Usuario* logueado;
		Usuario* a_tratar;//????????
		int ci;
		string nombre, apellido, pass;
		Sexo sexo;
		Fecha nacimiento;

	public:
		ControladorUsuarios* getInstance();
		TSesion iniciarSesion(int);
		bool ingresarContrasenia(string);
		void asignarSesion();
		void activarUsuario(string);
		void reactivar(string);
		void cerrarSesion();
		bool usuarioLogueado();
		bool ingresoCI(int);
		void ingresarDatosUser(string,string,Sexo,Fecha);
		//void ingresarCategoria(DataCategoria); ?????
		void confirmarInscripcion();
		void cancelarInscripcion();
		//DataUsuario devolverDatosUsuario();
};

#endif /* CONTROLADORUSUARIOS_H_ */

