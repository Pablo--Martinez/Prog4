#include "ConReserva.h"
#include "Emergencia.h"
#include "Fecha.h"
#include "Farmacologico.h"
#include <iostream>
#include <list>

using namespace std;
/*
int main(){
	Fecha f;
	Diagnostico* d;
	Medicamento* m;
	Farmacologico* t1;
	Farmacologico* t2;
	f = Fecha(15,15,1915);
	Emergencia* e;
	ConReserva* r;
	Fecha* nacimiento = new Fecha(22,5,1958);
	Usuario * u = new Usuario(1234,"Medico","Medico",F,true,*nacimiento);
	Medico* med = new Medico(u);
	u->agregarRol(med);

	Usuario* u2 = new Usuario(12345,"Socio","Socio",M,true,*nacimiento);
	Socio* soc = new Socio(u);
	u2->agregarRol(soc);

	e = new Emergencia(f,"Fiebre alta",med,soc);
	r = new ConReserva(f,f,med,soc);

	d = new Diagnostico("A","01","Dolor de espalda");
	t1 = new Farmacologico("Prueba de motivo1");
	t2 = new Farmacologico("Prueba de motivo2");

	m = new Medicamento("Perifar");
	t1->agregarMedicamento(m);

	m = new Medicamento("Redoxon");
	t1->agregarMedicamento(m);

	m = new Medicamento("Novemina");
	t1->agregarMedicamento(m);

	m = new Medicamento("Domper");
	t1->agregarMedicamento(m);

	d->agregarTratamiento(t1);

	m = new Medicamento("Diazepan");
	t2->agregarMedicamento(m);

	m = new Medicamento("Aspirina");
	t2->agregarMedicamento(m);
	d->agregarTratamiento(t2);

	e->agregarDiagnostico(d);

	r->agregarDiagnostico(d);

	e->show();
	cout << "-------------------" << endl;
	r->show();
	return 0;
}*/
