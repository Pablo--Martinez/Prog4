#ifndef CONTROLADORTRATAMIENTOS_H_
#define CONTROLADORTRATAMIENTOS_H_

#include <set>
#include "Tratamiento.h"
#include "Farmacologico.h"
#include "Quirurjico.h"
#include "ManejadorSocios.h"
#include "ManejadorAdministradores.h"
#include "ManejadorMedicos.h"
#include "ControladorDiagnosticos.h"
#include "ManejadorMedicamentos.h"
#include "Fecha.h"

class ControladorTratamientos{
	private:
		static ControladorTratamientos* instancia;
		ControladorTratamientos();
		set<Tratamiento*> tratamientos;
		set<Medicamento*> medicamentos;
	public:
		static ControladorTratamientos* getInstance();
		void agregarTratamientoQuirurjico(int,string,Fecha);
		void agregarTratamientoFarmacologico(string);
		void agregarMedicamento(string);
		//set<Medicamento*> getMedicamentosAUsar();
};




#endif /* CONTROLADORTRATAMIENTOS_H_ */
