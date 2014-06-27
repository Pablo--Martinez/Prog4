#include "ManejadorAdministradores.h"

ManejadorAdministradores* ManejadorAdministradores::instancia = NULL;

ManejadorAdministradores::ManejadorAdministradores(){}

ManejadorAdministradores*  ManejadorAdministradores::getInstance(){
	if(instancia == NULL)
		instancia = new ManejadorAdministradores();
	return instancia;
}

void  ManejadorAdministradores::agregarAdministrador(Administrador* a){
	if(this->administradores.find(a->getUsuario()->getCI()) != this->administradores.end())
		throw std::invalid_argument("Administrador ya existente");

	this->administradores[a->getUsuario()->getCI()] = a;
}
Administrador*  ManejadorAdministradores::find(int ci){
	if(this->administradores.find(ci) != this->administradores.end())
		return this->administradores[ci];
	return NULL;
}



