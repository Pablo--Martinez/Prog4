#include "Consulta.h"
#include "Fecha.h"
#include "Tratamiento.h"
#include <iostream>
#include <list>

using namespace std;
/*
int main(){
	Fecha f;
	Diagnostico d;
	Farmacologico t1,t2;
	f = Fecha(15,15,1915);
	Emergencia e;
	ConReserva r;
	e = Emergencia(f,"Fiebre alta");
	r = ConReserva(f,f);

	d = Diagnostico("A","01","Dolor de espalda");
	t1 = Farmacologico("Prueba de motivo1");
	t2 = Farmacologico("Prueba de motivo2");

	t1.agregarMedicamento("Perifar");
	t1.agregarMedicamento("Redoxon");
	d.agregarTratamiento(&t1);

	t2.agregarMedicamento("Diazepan");
	t2.agregarMedicamento("Aspirina");
	d.agregarTratamiento(&t2);

	e.agregarDiagnostico(&d);
	e.agregarDiagnostico(&d);

	e.show();
	cout << "-------------------" << endl;
	r.show();
	return 0;
}
*/