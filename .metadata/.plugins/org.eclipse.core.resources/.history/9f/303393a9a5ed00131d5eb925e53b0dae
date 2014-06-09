#include "Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(int ci, string nombre, string apellido, Sexo sexo, bool estado, Fecha nacimiento){
	this->ci = ci;
	this->nombre = nombre;
	this->apellido = apellido;
	this->sexo = sexo;
	this->estado = estado;
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
