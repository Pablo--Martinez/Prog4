#include "ControladorTratamientos.h"

ControladorTratamientos* ControladorTratamientos::instancia = NULL;
ControladorTratamientos::ControladorTratamientos(){}

ControladorTratamientos* ControladorTratamientos::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorTratamientos();
	return instancia;
}

void ControladorTratamientos::agregarTratamientoQuirurjico(int,string,Fecha){}

void ControladorTratamientos::agregarTratamientoFarmacologico(string){}

void ControladorTratamientos::agregarMedicamento(string){}
