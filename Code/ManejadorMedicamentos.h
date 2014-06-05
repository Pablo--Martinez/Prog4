#ifndef MANEJADORMEDICAMENTOS_H_
#define MANEJADORMEDICAMENTOS_H_

#include <string>
#include <set>
#include <iostream>
#include "Medicamento.h"

using namespace std;

class ManejadorMedicamentos
{
	private:
       ManejadorMedicamentos();
       static ManejadorMedicamentos* instancia;
       set<Medicamento*> medicamentos;
	public:
		static ManejadorMedicamentos* getInstance();
		//~ManejadorMedicamentos();
		void agregarMedicamento(string);
		Medicamento* find(string);
		void show();
};

#endif /* MANEJADORMEDICAMENTOS_H_ */
