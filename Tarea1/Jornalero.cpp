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

Jornalero::~Jornalero(){
}

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

void Jornalero::imprimir() {
	cout << "Empleado jornalero: " << endl;
	cout << "\tNombre: " << this->get_nombre() << endl;
	cout << "\tCI: " << this->get_ci() << endl;
	cout << "\tEdad: " << this->get_edad() << endl;
	Paga p = this->get_valor_hora();
	cout << "\tPaga por hora: " << p << endl;
	cout << "\tHoras trabajadas: " << this->get_horas() << endl;
}
