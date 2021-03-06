#include "Usuario.h"

Usuario::Usuario(){}

Usuario::~Usuario(){
	this->roles.clear();
}

Usuario::Usuario(int ci, string nombre, string apellido, Sexo sexo, bool estado, Fecha nacimiento){
	this->ci = ci;
	this->nombre = nombre;
	this->apellido = apellido;
	this->sexo = sexo;
	this->estado = estado;
	this->pass = "";
	this->nacimiento = nacimiento;
}

int Usuario::getCI(){
	return this->ci;
}

string Usuario::getNombre(){
	return this->nombre;
}

string Usuario::getApellido(){
	return this->apellido;
}

Sexo Usuario::getSexo(){
	return this->sexo;
}

Fecha Usuario::getNacimiento(){
	return this->nacimiento;
}

int Usuario::getEdad(Fecha actual){
	int edad = actual.getAnio() - this->nacimiento.getAnio() ;
	if((this->nacimiento.getMes() < actual.getMes()) || (this->nacimiento.getMes() >= actual.getMes() && this->nacimiento.getDia() < actual.getDia())){
		edad -= 1;
	}
	return edad;
}

bool Usuario::getEstado(){
	return this->estado;
}

void Usuario::agregarRol(Rol* r){
	this->roles.insert(r);
}

TSesion Usuario::getTipoSesion(){
	if(this->ci == 123456789){ //La cedula del admin x defecto es 123456789
		return APD;
	}
	else if(this->pass == ""){
		return PV;
	}
	else{
		return CM;
	}

}

bool Usuario::verificarPass(string pass){
	if(this->pass == pass){
		return true;
	}
	return false;
}

void Usuario::activar(string pass){
	this->pass = pass; //Se asume que el formato de pass es correcto
	this->estado = true;
}

void Usuario::desactivar(){
	this->estado = false;
}

void Usuario::reactivar(){
	this->estado = true;
}

DataUsuario* Usuario::getDataUsuario(){
	RelojSistema* rs = RelojSistema::getInstance();
	set<DataRol*> dataRoles;
	bool esadmin = false;
	bool esmedico = false;
	bool essocio = false;
	for(set<Rol*>::iterator it = this->roles.begin();it != this->roles.end();++it){
		if ((*it)->getTipoRol() == administrador) {
			esadmin = true;
		}
		if ((*it)->getTipoRol() == medico) {
			esmedico = true;
		}
		if ((*it)->getTipoRol() == socio) {
			essocio = true;
		}
	}
	return new DataUsuario(this->ci,this->pass,this->nombre,this->apellido,this->sexo,this->getEdad(rs->getFechaSistema()),this->estado,esadmin,esmedico,essocio);
}

 void Usuario::show(){
	 if(this !=  NULL){
		 cout << "CI: " << this->ci << endl;
		 cout << "Nombre: " << this->nombre << endl;
		 cout << "Apellido: " << this->apellido << endl;
		 if(this->sexo == F){
			 cout << "Sexo: Femenino" << endl;
		 }
		 else{
			 cout << "Sexo: Masculino" << endl;
		 }
		 cout << "Nacimiento: " << this->nacimiento.getDia() << "-" << this->nacimiento.getMes() << "-" << this->nacimiento.getAnio() << endl;
	 }
}
