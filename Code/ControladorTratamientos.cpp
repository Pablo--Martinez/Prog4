#include "ControladorTratamientos.h"

ControladorTratamientos* ControladorTratamientos::instancia = NULL;
ControladorTratamientos::ControladorTratamientos(){}

ControladorTratamientos::~ControladorTratamientos(){
	for(set<Tratamiento*>::iterator it = this->tratamientos.begin();it != this->tratamientos.end();++it){
		delete (*it);
	}
	this->tratamientos.clear();
	for(set<Medicamento*>::iterator it = this->medicamentos.begin();it != this->medicamentos.end();++it){
		delete (*it);
	}
	this->medicamentos.clear();
}

ControladorTratamientos* ControladorTratamientos::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorTratamientos();
	return instancia;
}

void ControladorTratamientos::agregarTratamientoQuirurjico(int ci_medico,string desc,Fecha fecha){
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ControladorDiagnosticos* cd = ControladorDiagnosticos::getInstance();
	Medico* m = mm->find(ci_medico);
	Quirurjico* q = new Quirurjico(desc,fecha,m);
	cd->getDiagnostico()->agregarTratamiento(q);
}

void ControladorTratamientos::agregarTratamientoFarmacologico(string desc){
	Farmacologico* f = new Farmacologico(desc);
	ControladorDiagnosticos* cd = ControladorDiagnosticos::getInstance();
	for(set<Medicamento*>::iterator it = this->medicamentos.begin();it != this->medicamentos.end();++it){
		f->agregarMedicamento(*it);
	}
	cd->getDiagnostico()->agregarTratamiento(f);
}

void ControladorTratamientos::agregarMedicamento(string nombre_med){
	ManejadorMedicamentos* mm = ManejadorMedicamentos::getInstance();
	this->medicamentos.insert(mm->find(nombre_med));
}
