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
	if (this->find(s->getUsuario()->getCI()) == NULL){
		this->socios.insert(s);
	}
}
Socio* ManejadorSocios::find(int ci){
	set<Socio*>::iterator it = this->socios.begin();
	while(it != this->socios.end()){
		if((*it)->getUsuario()->getCI() == ci){
			return *it;
		}
		++it;
	}
	return NULL;
}
void ManejadorSocios::show(){
	if(this != NULL){
		cout << "Socios disponibles:" << endl;
		for (set<Socio*>::iterator it=this->socios.begin(); it!=this->socios.end(); ++it){
			(*it)->show();
			cout << "----------------" << endl;
		}
	}
}
