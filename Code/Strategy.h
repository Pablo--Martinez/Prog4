#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <set>
#include "DataMedico.h"

using namespace std;

class Strategy{
	public:
		Strategy();
		virtual ~Strategy()=0;
		virtual set<DataMedico*> algoritmoDeSeleccion()=0;
};

#endif /* STRATEGY_H_ */
