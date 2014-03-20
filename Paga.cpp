#include "Paga.h"
#include "Cambio.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

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
		throw std::invalid_argument("");
	}
	
	if(moneda != us && moneda != usd){
		throw std::invalid_argument("");
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
	}
	return p;
};

Paga Paga::a_peso(){
	Paga p;
	if(this->moneda == usd){
		p.moneda = us;
		p.monto = Cambio::a_peso(this->monto);
	}
	return p;
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
		throw std::invalid_argument("");
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
		throw std::invalid_argument("");
	}
}

ostream& operator<<(ostream &o, Paga &p){
    if(p.getMonto() >= 1000){
		if(p.getMoneda() == us){
			o << (int)(p.getMonto() / 1000) << "." << setw(3) << setfill('0') << ((int)p.getMonto() % 1000) << " us";
		}
		else{
			o << (int)(p.getMonto() / 1000) << "." << setw(3) << setfill('0') << ((int)p.getMonto() % 1000) << " usd";
		}
	}
	else{
		if(p.getMoneda() == us){
			o << p.getMonto() << " us";
		}
		else{
			o << p.getMonto() << " usd";
		}
	}
	return o;
}
