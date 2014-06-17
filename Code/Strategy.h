/*
 * Strategy.h
 *
 *  Created on: 16/06/2014
 *      Author: usuario
 */

#ifndef STRATEGY_H_
#define STRATEGY_H_

using namespace std;

class Strategy{
	private:
	public:
		virtual Strategy();
		virtual ~Strategy()=0;
		virtual void algoritmoDeSeleccion()=0;
};

#endif /* STRATEGY_H_ */
