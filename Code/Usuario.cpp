#include "Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(int ci, string nombre, string apellido, Sexo sexo, bool estado, Fecha nacimiento){
	this->ci = ci;
	this->nombre = nombre;
	this->apellido = apellido;
	this->sexo = sexo;
	this->estado = estado;
	this->pass = "";
	this->nacimiento = nacimiento;
	//this->roles = NULL;
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
}

void Usuario::reactivar(){ // setEstado(bool) ?
	this->estado = true;
}

DataUsuario Usuario::getDataUsuario(){
	return DataUsuario(this);
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
