#include "Fijo.h"
#define MontoXHora 40

Fijo::Fijo():Empleado(){}

Fijo::Fijo(char* nombre, char* ci, int edad, Paga valor_hora, Empresa* e)
    : Empleado(nombre, ci, edad, valor_hora, e){}

Fijo::~Fijo(){
}

Paga Fijo::calculoPaga()
{
    float monto = this->get_valor_hora().getMonto() * MontoXHora;
    Paga tmp(monto, this->get_valor_hora().getMoneda());
    return tmp;
}

Paga Fijo::get_sueldo_peso()
{
    return calculoPaga().a_peso();
}

Paga Fijo::get_sueldo_dolar()
{
    return calculoPaga().a_dolar();
}
void Fijo::imprimir() {
	cout << "Fijo: " << endl;
	cout << "\tNombre: " << this->get_nombre() << endl;
	cout << "\tCI: " << this->get_ci() << endl;
	cout << "\tEdad: " << this->get_edad() << endl;
	Paga p = this->get_valor_hora();
	cout << "\tPaga por hora: " << p << endl;
}

