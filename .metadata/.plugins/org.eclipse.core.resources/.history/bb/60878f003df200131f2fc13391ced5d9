#ifndef CONTROLADORTRATAMIENTOS_H_
#define CONTROLADORTRATAMIENTOS_H_

#include <set>
#include "Tratamiento.h"
#include "Fecha.h"

class ControladorTratamientos{
	private:
		static ControladorTratamientos* instancia;
		ControladorTratamientos();
		set<Tratamiento*> tratamientos;
	public:
		ControladorTratamientos* getInstance();
		void agregarTratamientoQuirurjico(int,string,Fecha);
		void agregarTratamientoFarmacologico(string);
		void agregarMedicamento(string);
};




#endif /* CONTROLADORTRATAMIENTOS_H_ */
