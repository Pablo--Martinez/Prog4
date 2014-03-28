#include "Fijo.h"
#define MontoXHora 40

Fijo::Fijo():Empleado(){}

Fijo::Fijo(char* nombre, char* ci, int edad, Paga valor_hora, Empresa* e)
    : Empleado(nombre, ci, edad, valor_hora, e){}
    
//Fijo::Fijo(const Fijo f&):Empleado(&f){}

Fijo::~Fijo(){}

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

ostream& operator<<(ostream &o, Fijo &f){
	o << "Fijo: " << endl;
	o << "\tNombre: " << f.get_nombre() << endl;
	o << "\tCI: " << f.get_ci() << endl;
	o << "\tEdad: " << f.get_edad() << endl;
	Paga p = f.get_valor_hora();
	o << "\tPaga por hora: " << p << endl;
	return o;
}

