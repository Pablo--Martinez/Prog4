#include "ControladorUsuarios.h"

ControladorUsuarios* ControladorUsuarios::instancia = NULL;

ControladorUsuarios::ControladorUsuarios(){
	this->logueado = NULL;
	this->a_tratar = NULL;
}

ControladorUsuarios* ControladorUsuarios::getInstance(){
	if (instancia == NULL)
		instancia = new ControladorUsuarios();
	return instancia;
}

TSesion ControladorUsuarios::iniciarSesion(int){}

bool ControladorUsuarios::esCorrecta(string ci){}

void ControladorUsuarios::asignarSesion(){}

void ControladorUsuarios::reactivarUsuario(string ci){}

void ControladorUsuarios::cerrarSesion(){}

bool ControladorUsuarios::usuarioLogueado(){}

bool ControladorUsuarios::ingresoCI(int ci){}

void ControladorUsuarios::ingresarDatosUser(string nombre, string apellido, Sexo sexo, Fecha fecha){}

//void ControladorUsuarios::ingresarCategoria(DataCategoria cat){} ?????

void ControladorUsuarios::confirmarInscripcion(){}

void ControladorUsuarios::cancelarInscripcion(){}

//DataUsuario ControladorUsuarios::devolverDatosUsuario(){}
