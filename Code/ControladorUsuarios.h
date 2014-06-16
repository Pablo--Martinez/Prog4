#ifndef CONTROLADORUSUARIOS_H_
#define CONTROLADORUSUARIOS_H_

#include <set>
#include <string>
#include "Usuario.h"
#include "ManejadorSocios.h"
#include "ManejadorMedicos.h"
#include "ManejadorAdministradores.h"

using namespace std;

enum Categorias {Med,Soc,Admin,MedSoc,AdminSoc};

class ControladorUsuarios{
	private:
		ControladorUsuarios();
		static ControladorUsuarios* instancia;
		map<int,Usuario*> usuarios;
		Usuario* logueado;
		Usuario* a_tratar;
		int ci;
		string nombre, apellido, pass;
		Categorias categoria;
		Sexo sexo;
		Fecha nacimiento;

	public:
		static ControladorUsuarios* getInstance();
		Usuario* getUsuarioLogueado();
		TSesion iniciarSesion(int);
		bool ingresarContrasenia(string);
		void asignarSesion();
		void activarUsuario(string);
		void reactivar();
		void cerrarSesion();
		bool usuarioLogueado();
		bool ingresoCI(int);
		void ingresarDatosUser(string,string,Sexo,Fecha);
		//void ingresarCategoria(DataCategoria); ?????
		void confirmarInscripcion();
		void cancelarInscripcion();
		DataUsuario devolverDatosUsuario(Fecha);
};

#endif /* CONTROLADORUSUARIOS_H_ */
