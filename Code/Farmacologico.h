#ifndef FARMACOLOGICO_H_
#define FARMACOLOGICO_H_

#include "Tratamiento.h"

using namespace std;

class Farmacologico: public Tratamiento{
	private:
		map<string,Medicamento*> medicamentos;
	public:
		Farmacologico();
		Farmacologico(string);
		~Farmacologico();
		void agregarMedicamento(Medicamento*);
		map<string,Medicamento*> getMedicamentos();
		void show();
};

#endif /* FARMACOLOGICO_H_ */
