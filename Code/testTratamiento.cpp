#include "Farmacologico.h"
#include "Quirurjico.h"
#include "Fecha.h"
#include "Medicamento.h"
#include "Usuario.h"
#include "ControladorTratamientos.h"
/*
int main(){
	ControladorTratamientos* CT = ControladorTratamientos::getInstance();
	Farmacologico t;
	Quirurjico q;
	Medicamento* m;
	Fecha f;
	f = Fecha(15,7,1992);
	Usuario* u = new Usuario(1234,"Pablo","Martinez",M,true,f);
	Medico* r = new Medico(u);
	u->agregarRol(r);
	
	t = Farmacologico("Tratamiento farmacológico");

	m = new Medicamento("Perifar");
	t.agregarMedicamento(m);

	m = new Medicamento("Redoxon");
	t.agregarMedicamento(m);

	m = new Medicamento("Diazepan");
	t.agregarMedicamento(m);

	m = new Medicamento("Aspirina");
	t.agregarMedicamento(m);
	t.show();
	
	DataTratamiento dt = t.getDataTratamiento();
	cout << "Descripcion del DataTratamiento: " << dt.getDescripcion() << endl;

	Fecha f2;
	f2 = Fecha(12,8,2014);
	q = Quirurjico("Tratamiento quirurjico",f2,r);
	q.show();

	//cout <<  endl << "TESTEANDO EL CONTROLADOR DE TRATAMIENTOS" << endl;
	//CT->agregarTratamientoFarmacologico()


	return 0;
}
*/
