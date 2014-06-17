#include "ManejadorAdministradores.h"

ManejadorAdministradores* ManejadorAdministradores::instancia = NULL;

ManejadorAdministradores::ManejadorAdministradores(){}

ManejadorAdministradores*  ManejadorAdministradores::getInstance(){
	if(instancia == NULL)
		instancia = new ManejadorAdministradores();
	return instancia;
}

void  ManejadorAdministradores::agregarAdministrador(Administrador* a){
	if(this->administradores.find(a->getUsuario()->getCI()) == this->administradores.end()){
		this->administradores[a->getUsuario()->getCI()] = a;
	}
}
Administrador*  ManejadorAdministradores::find(int ci){
	return this->administradores[ci];
}



