#ifndef MEDICAMENTO
#define MEDICAMENTO

#include <string>
#include <iostream>

using namespace std;

class Medicamento{
	private:
		string nombre;
		
	public:
		Medicamento();
		Medicamento(string);
		string getNombre();
		void show();
};

#endif
