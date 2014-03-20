#include "Cambio.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Prueba de clase estatica Cambio\n";
	float importe;
	
	cout << "Ingrese su monto: ";
	cin >> importe;
	cout << "Monto inicial: " << importe << "\n";
	cout << "Monto en dolares: " << Cambio::a_dolar(importe) << "\n";
	cout << "Monto en pesos: " << Cambio::a_pesos(Cambio::a_dolar(importe))<< "\n";
	return 0;
}
