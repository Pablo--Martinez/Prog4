#include "Cambio.h"

float Cambio::cotizacion = 22.6;

float Cambio::a_peso(float importe){
	return (importe * Cambio::cotizacion);
}

float Cambio::a_dolar(float importe){
	return (importe / Cambio::cotizacion);
}
