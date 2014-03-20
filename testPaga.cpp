#include "Paga.cpp"
#include "Moneda.h"


int main(){
	Paga p1(15400,us);
	Paga p2(10000,us);
	Paga p3 = p1 + p2;
	Paga p4 = p1*2;
	cout <<  "p1(15400,us): " << p1 << endl;
	cout << "p2(10000,us): " << p2 << endl;
	
	cout << "Pruebo suma y produto" << endl;
	cout << "p3 = p1 + p2: " << p3 << endl;
	cout << "p4 = p1*2: " << p4 << endl;
	
	cout << endl << "Luego de realizar las operaciones con p1 y p2" << endl;
	cout <<  "p1(15400,us): " << p1 << endl;
	cout << "p2(10000,us): " << p2 << endl;
	
	cout << "Pruebo asignacion" << endl;
	p2 = p1;
	cout << "p2 = p1: "<< p2 << endl;
	
	cout << endl << "Pruebo el cambio a dolar" << endl;
	Paga p5 = p1.a_dolar();
	cout << "p5 = Paga(15400,us).a_dolar(): " << p5 << endl;
	
	cout << endl << "Pruebo el cambio a pesos" << endl;
	p5 = p5.a_peso();
	cout << "p5 = Paga(15400,us).a_dolar().a_peso(): " << p5 << endl;
	
	
	
	return 0;
}
