#include "Tratamiento.h"

Tratamiento::Tratamiento(){}

Tratamiento::Tratamiento(string descripcion){
	this->descripcion = descripcion;
}

string Tratamiento::getDescripcion(){
	return this->descripcion;
}

Quirurjico::Quirurjico(){}

Quirurjico::Quirurjico(string descripcion,Fecha operacion,Medico* medico):Tratamiento(descripcion){
	this->fecha = operacion;
	this->cirujano = medico;
}

Fecha Quirurjico::getFechaOperacion(){
	return this->fecha;
}

Medico* Quirurjico::getCirujano(){
	return this->cirujano;
}

void Quirurjico::show(){
	cout << "Descripcion: " << this->getDescripcion() << endl;
	cout << "Fecha intervencion: "; this->fecha.show();
	cout << "Cirujano: "; this->cirujano->show();
}

Farmacologico::Farmacologico(){}

Farmacologico::Farmacologico(string descripcion):Tratamiento(descripcion){}

void Farmacologico::agregarMedicamento(Medicamento* m){
	this->medicamentos.insert(m);
}

set<Medicamento*> Farmacologico::getMedicamentos(){
	return this->medicamentos;
}

void Farmacologico::show(){
	cout << "Descripcion: " << this->getDescripcion() << endl;

	int i=0;
	for (set<Medicamento*>::iterator it=this->medicamentos.begin(); it!=this->medicamentos.end(); ++it){
		cout << "Medicamento" << i << ": " << endl;
		(*it)->show();
		i++;
	}
}
