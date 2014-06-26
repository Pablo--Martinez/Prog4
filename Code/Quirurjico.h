#ifndef QUIRURJICO_H_
#define QUIRURJICO_H_

#include "Tratamiento.h"
#include "Medico.h"

using namespace std;

class Quirurjico: public Tratamiento{
	private:
		Fecha fecha;
		Medico* cirujano;
	public:
		Quirurjico();
		Quirurjico(string,Fecha,Medico*);
		~Quirurjico();
		Fecha getFechaOperacion();
		Medico* getCirujano();
		void show();
};

#endif /* QUIRURJICO_H_ */
