#include "Paga.h"
#include "Cambio.h"
#include <iostream>
#include <stdexcept>
//#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;

float Paga::getMonto(){
	return this->monto;
}

Moneda Paga::getMoneda(){
	return this->moneda;
}

Paga::Paga(){
	this->monto = 0.0;
	this->moneda = us;
};

Paga::Paga(float monto, Moneda moneda){
	if(monto >= 0){
		this->monto = monto;
	}
	else{
		throw std::invalid_argument("Monto incorrecto");
	}
	
	if(moneda != us && moneda != usd){
		throw std::invalid_argument("Moneda incorrecta");
	}
	else{
		this->moneda = moneda;
	}
}

Paga Paga::a_dolar(){
	Paga p;
	if(this->moneda == us){
		p.moneda = usd;
		p.monto = Cambio::a_dolar(this->monto);
		return p;
	}
	else{
		return *this;
	}
};

Paga Paga::a_peso(){
	Paga p;
	if(this->moneda == usd){
		p.moneda = us;
		p.monto = Cambio::a_peso(this->monto);
		return p;
	}
	else{
		return *this;
	}
}

Paga Paga::operator =(const Paga &p1){
	this->moneda = p1.moneda;
	this->monto = p1.monto;
	return *this;
}

Paga Paga::operator *(float cant){
	if(cant > 0){
		Paga p;
		p.moneda = this->moneda;
		p.monto = cant * (this->monto);
		return p;
	}
	else{
		throw std::invalid_argument("Producto negativo");
	}
}

Paga Paga::operator +(const Paga &p1){
	Paga p;
	if(p1.moneda == this->moneda){
		p.moneda = p1.moneda;
		p.monto = p1.monto + this->monto;
		return p;
	}
	else{
		throw std::invalid_argument("Tipos de monedas incompatibles");
	}
}

ostream& operator<<(ostream &o, Paga &p){
	char* valor = new char;
	sprintf(valor,"%.2f",p.getMonto());
    int largo = strlen(valor);
    int i = 0;
    int sobran = largo%3;
    bool flag=false;
    
    if (sobran == 0) flag=true;
    
    while(i < largo) {
		if(valor[i] == '.'){
			o << ",";
			flag = true;
		}
        else if ((i%3) == sobran && !flag) {
            o << "." << valor[i];
        }
        else {
            flag=false;
            o << valor[i];
        }
        i++;    
    }
    if(p.getMoneda() == us){
		o << " us";
	}
	else{
		o << " usd";
	}
	return o;
}
