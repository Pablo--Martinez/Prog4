//============================================================================
// Name        : Prog4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "ManejadorMedicamentos.h"

int main() {

	ManejadorMedicamentos* mm = ManejadorMedicamentos::getInstance();

	mm->show();
	mm->agregarMedicamento("Diazepan");
	mm->agregarMedicamento("Aspirina");
	mm->agregarMedicamento("Domper");
	mm->show();

	Medicamento* m = mm->find("Diazepan");
	m->show();
	delete mm;

	//mm->show();
	if(mm == NULL){
		cout << "Se borro el manejador" << endl;
	}
	else{
		cout << "No se borro el manejador" << endl;
	}

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
