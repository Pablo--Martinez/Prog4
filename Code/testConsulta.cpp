#include "Consulta.h"
#include "Fecha.h"
#include "Tratamiento.h"
#include <iostream>
#include <list>

using namespace std;

int main(){
	Fecha f;
	Diagnostico d;
	Medicamento* m;
	Farmacologico t1,t2;
	f = Fecha(15,15,1915);
	Emergencia e;
	ConReserva r;
	e = Emergencia(f,"Fiebre alta");
	r = ConReserva(f,f);

	d = Diagnostico("A","01","Dolor de espalda");
	t1 = Farmacologico("Prueba de motivo1");
	t2 = Farmacologico("Prueba de motivo2");

	m = new Medicamento("Perifar");
	t1.agregarMedicamento(m);

	m = new Medicamento("Redoxon");
	t1.agregarMedicamento(m);

	m = new Medicamento("Novemina");
	t1.agregarMedicamento(m);

	m = new Medicamento("Domper");
	t1.agregarMedicamento(m);

	d.agregarTratamiento(&t1);

	m = new Medicamento("Diazepan");
	t2.agregarMedicamento(m);

	m = new Medicamento("Aspirina");
	t2.agregarMedicamento(m);
	d.agregarTratamiento(&t2);

	e.agregarDiagnostico(&d);
	//e.agregarDiagnostico(&d);

	r.agregarDiagnostico(&d);

	e.show();
	cout << "-------------------" << endl;
	r.show();
	return 0;
}
