#include "ManejadorSocios.h"

ManejadorSocios* ManejadorSocios::instancia = NULL;

ManejadorSocios::ManejadorSocios(){}

ManejadorSocios* ManejadorSocios::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorSocios();
	return instancia;
}

//~ManejadorSocios();

void ManejadorSocios::agregarSocio(Socio* s){
	if(this->socios.find(s->getUsuario()->getCI()) != this->socios.end())
		throw std::invalid_argument("Socio ya existente");

	this->socios[s->getUsuario()->getCI()] = s;

}
Socio* ManejadorSocios::find(int ci){
	if(this->socios[ci] != NULL)
		return this->socios[ci];
	return NULL;
}

map<int,Socio*> ManejadorSocios::getSocios(){
	return this->socios;
}

void ManejadorSocios::show(){
	if(this != NULL){
		cout << "Socios disponibles:" << endl;
		for (map<int,Socio*>::iterator it=this->socios.begin(); it!=this->socios.end(); ++it){
			it->second->show();
			cout << "----------------" << endl;
		}
	}
}
