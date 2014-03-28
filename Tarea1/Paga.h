#ifndef PAGA
#define PAGA

#include "Moneda.h"
#include "Cambio.h"
#include <iostream>
using namespace std;

class Paga{
	private:
		float monto;
		Moneda moneda;
		
	public:
		Paga();
		Paga(float,Moneda);
		float getMonto();
		Moneda getMoneda();
		Paga a_dolar();
		Paga a_peso();
		Paga operator =(const Paga &);
		Paga operator *(float cant);
		Paga operator +(const Paga &);
};

ostream& operator <<(ostream &, Paga &);	
#endif
