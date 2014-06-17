/*
 * StrategyMedicosLibres.h
 *
 *  Created on: 16/06/2014
 *      Author: usuario
 */

#ifndef STRATEGYMEDICOSLIBRES_H_
#define STRATEGYMEDICOSLIBRES_H_

#include "DataMedico.h"
#include "Medico.h"

class MedicosLibres: public Strategy{
	public:
		MedicosLibres();
		~MedicosLibres();
		virtual set<DataMedico*> algoritmoDeSeleccion(int,Fecha)=0;
};

#endif /* STRATEGYMEDICOSLIBRES_H_ */
