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

Usuario* ControladorUsuarios::getUsuarioLogueado(){
	return this->logueado;
}

TSesion ControladorUsuarios::iniciarSesion(int ci){
	this->a_tratar = this->usuarios[ci];
	if(this->a_tratar != NULL){
		TSesion tipo = this->a_tratar->getTipoSesion();
		return tipo;
	}
}

bool ControladorUsuarios::ingresarContrasenia(string pass){
	return this->a_tratar->verificarPass(pass);
}

void ControladorUsuarios::asignarSesion(){
	this->logueado = this->a_tratar;
	this->a_tratar = NULL;
}

void ControladorUsuarios::reactivar(){
	this->a_tratar->reactivar();
}

void ControladorUsuarios::cerrarSesion(){
	this->logueado = NULL;
}

bool ControladorUsuarios::usuarioLogueado(){
	return this->logueado != NULL;
}

bool ControladorUsuarios::ingresoCI(int ci){
	if(this->usuarios.find(ci) == this->usuarios.end())
		return false;
	else{
		this->ci = ci;
		return true;
	}
}

void ControladorUsuarios::ingresarDatosUser(string nombre, string apellido, Sexo sexo, Fecha fecha){
	this->nombre = nombre;
	this->apellido = apellido;
	this->sexo = sexo;
	this->nacimiento = fecha;
}

//void ControladorUsuarios::ingresarCategoria(DataCategoria cat){} ?????

void ControladorUsuarios::confirmarInscripcion(){
	Usuario* u = new Usuario(this->ci,this->nombre,this->apellido,this->sexo,false,this->nacimiento);
	if(this->categoria == Soc){
		Socio* s = new Socio(u);
		u->agregarRol(s);
		ManejadorSocios* ms = ManejadorSocios::getInstance();
		ms->agregarSocio(s);
	}
	else if(this->categoria == Med){
		Medico* m = new Medico(u);
		u->agregarRol(m);
		ManejadorMedicos* mm = ManejadorMedicos::getInstance();
		mm->agregarMedico(m);
	}
	else if(this->categoria == Admin){
		Administrador* a = new Administrador(u);
		u->agregarRol(a);
		ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
		ma->agregarAdministrador(a);
	}
	else if(this->categoria == MedSoc){
		Medico* m = new Medico(u);
		u->agregarRol(m);
		ManejadorMedicos* mm = ManejadorMedicos::getInstance();
		mm->agregarMedico(m);
		Socio* s = new Socio(u);
		u->agregarRol(s);
		ManejadorSocios* ms = ManejadorSocios::getInstance();
		ms->agregarSocio(s);
	}
	else if(this->categoria == AdminSoc){
		Administrador* a = new Administrador(u);
		u->agregarRol(a);
		ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
		ma->agregarAdministrador(a);
		Socio* s = new Socio(u);
		u->agregarRol(s);
		ManejadorSocios* ms = ManejadorSocios::getInstance();
		ms->agregarSocio(s);
	}

	this->usuarios[this->ci] = u;
}

void ControladorUsuarios::cancelarInscripcion(){
	this->ci = 0;
	this->nombre = "";
	this->apellido = "";
	this->pass = "";
	this->sexo = M;
}

DataUsuario* ControladorUsuarios::devolverDatosUsuario(){
	this->a_tratar = this->usuarios[this->ci];
	return this->a_tratar->getDataUsuario();
}
