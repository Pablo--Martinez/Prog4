#ifndef TRATAMIENTO
#define TRATAMIENTO

#include <string>
#include <set>
#include "Fecha.h"
#include "Rol.h"
#include "Medicamento.h"

using namespace std;

class Tratamiento{
	private:
		string descripcion;
	public:
		Tratamiento();
		Tratamiento(string);
		string getDescripcion();
		virtual void show()=0;
};

class Quirurjico: public Tratamiento{
	private:
		Fecha fecha;
		Medico* cirujano;
	public:
		Quirurjico();
		Quirurjico(string,Fecha,Medico*);
		Fecha getFechaOperacion();
		Medico* getCirujano();
		void show();
};

class Farmacologico: public Tratamiento{
	private:
		set<Medicamento*> medicamentos;
	public:
		Farmacologico();
		Farmacologico(string);
		void agregarMedicamento(Medicamento*);
		set<Medicamento*> getMedicamentos();
		void show();
};

#endif
