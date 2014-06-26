#ifndef DATAEMERGENCIA_H_
#define DATAEMERGENCIA_H_

#include "DataConsulta.h"
#include <string>

using namespace std;

class DataEmergencia: public DataConsulta{
	private:
		string motivo;
	public:
		DataEmergencia();
		DataEmergencia(Fecha,string);
		virtual ~DataEmergencia();
		string getMotivo();
};



#endif /* DATAEMERGENCIA_H_ */
