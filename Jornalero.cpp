#include "Jornalero.h"

Jornalero::Jornalero():Empleado()
{
	this->horas = 0;
}

Jornalero::Jornalero(char* nombre, char* ci, int edad, Paga valor_hora, int horas, Empresa* e)
    : Empleado(nombre, ci, edad, valor_hora, e)
{
	if(horas >= 0){
		this->horas = horas;
	}
	else{
		throw std::invalid_argument("La cantidad de horas debe ser un numero positivo");
	}
}

/*Jornalero::Jornalero(Jornalero &j):Empleado(&j){
	this->horas = j.horas;
}*/

Jornalero::~Jornalero(){}

int Jornalero::get_horas()
{
    return this->horas;
}

Paga Jornalero::calculoPaga()
{
    float monto = this->get_valor_hora().getMonto() * horas;
    Paga tmp(monto, this->get_valor_hora().getMoneda());
    return tmp;
}

Paga Jornalero::get_sueldo_peso()
{
    return calculoPaga().a_peso();
}

Paga Jornalero::get_sueldo_dolar()
{
    return calculoPaga().a_dolar();
}

ostream& operator<<(ostream &o, Jornalero &j){
	o << "Empleado jornalero: " << endl;
	o << "\tNombre: " << j.get_nombre() << endl;
	o << "\tCI: " << j.get_ci() << endl;
	o << "\tEdad: " << j.get_edad() << endl;
	Paga p = j.get_valor_hora();
	o << "\tPaga por hora: " << p << endl;
	o << "\tHoras trabajadas: " << j.get_horas();
	return o;
}
