#ifndef MANEJADORMEDICAMENTOS_H_
#define MANEJADORMEDICAMENTOS_H_

#include <string>
#include <map>
#include <iostream>
#include <stdexcept>
#include "Medicamento.h"

using namespace std;

class ManejadorMedicamentos
{
	private:
       ManejadorMedicamentos();
       static ManejadorMedicamentos* instancia;
       map<string,Medicamento*> medicamentos;
       string nombre;
	public:
		static ManejadorMedicamentos* getInstance();
		~ManejadorMedicamentos();
		void ingresarMedicamento();
		Medicamento* find(string);
		bool existeMedicamento(string);
		void show();
};

#endif /* MANEJADORMEDICAMENTOS_H_ */
