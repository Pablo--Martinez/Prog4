/*
 * StrategyMedicosPaciente.h
 *
 *  Created on: 16/06/2014
 *      Author: usuario
 */

#ifndef STRATEGYMEDICOSPACIENTE_H_
#define STRATEGYMEDICOSPACIENTE_H_

class MedicosdelPaciente: public Strategy{
	public:
		MedicosdelPaciente();
		~MedicosdelPaciente();
		virtual set<DataMedico*> algoritmoDeSeleccion()=0;
};

#endif /* STRATEGYMEDICOSPACIENTE_H_ */
