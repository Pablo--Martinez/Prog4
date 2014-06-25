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
	if(this->socios.find(s->getUsuario()->getCI()) == this->socios.end()){
		this->socios[s->getUsuario()->getCI()] = s;
	}
}
Socio* ManejadorSocios::find(int ci){
	/*set<Socio*>::iterator it = this->socios.begin();
	while(it != this->socios.end()){
		if((*it)->getUsuario()->getCI() == ci){
			return *it;
		}
		++it;
	}
	Socio* s = this->socios[ci];
	return s;*/
	if(this->socios[ci] != NULL)
		return this->socios[ci];
	return NULL;
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
