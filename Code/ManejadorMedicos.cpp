#include "ManejadorMedicos.h"

ManejadorMedicos* ManejadorMedicos::instancia = NULL;

ManejadorMedicos::ManejadorMedicos(){}

ManejadorMedicos* ManejadorMedicos::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorMedicos();
	return instancia;
}

//~ManejadorMedicamentos();

void ManejadorMedicos::agregarMedico(Medico* m){
	if (this->find(m->getUsuario()->getCI()) == NULL){
		this->medicos.insert(m);
	}
}
Medico* ManejadorMedicos::find(int ci){
	set<Medico*>::iterator it = this->medicos.begin();
	//it = this->medicamentos.find(m);
	while(it != this->medicos.end()){
		if((*it)->getUsuario()->getCI() == ci){
			return *it;
		}
		++it;
	}
	return NULL;
}
void ManejadorMedicos::show(){
	if(this != NULL){
		cout << "Medicos disponibles:" << endl;
		for (set<Medico*>::iterator it=this->medicos.begin(); it!=this->medicos.end(); ++it){
			(*it)->show();
			cout << "----------------" << endl;
		}
	}
}
