#ifndef CONTROLADORUSUARIOS_H_
#define CONTROLADORUSUARIOS_H_

#include <set>
#include <string>
#include <stdexcept>
#include "Usuario.h"
#include "ConReserva.h"
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
		int maximo_inasistencias;
		Usuario* logueado;
		Usuario* a_tratar;
		int ci;
		string nombre, apellido, pass;
		Categorias categoria;
		Sexo sexo;
		Fecha nacimiento;

	public:
		static ControladorUsuarios* getInstance();
		void setMaximoInasistencias(int);
		int getMaximoInasistencias();
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
		DataUsuario* devolverDatosUsuario();
		set<DataAltaReactivacion*> obtenerDaDeAltaReactiva();
		void recalcularInasistencias(Fecha);
};

#endif /* CONTROLADORUSUARIOS_H_ */

