#ifndef TRATAMIENTO
#define TRATAMIENTO

#include <string>
#include <map>
#include "Fecha.h"
//#include "Rol.h"
#include "Medicamento.h"

using namespace std;

//class Rol;
class Administrador;
class Socio;
class Medico;

class Tratamiento{
	private:
		string descripcion;
	public:
		Tratamiento();
		Tratamiento(string);
		virtual ~Tratamiento()=0;
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
		~Quirurjico();
		Fecha getFechaOperacion();
		Medico* getCirujano();
		void show();
};

class Farmacologico: public Tratamiento{
	private:
		map<string,Medicamento*> medicamentos;
	public:
		Farmacologico();
		Farmacologico(string);
		~Farmacologico();
		void agregarMedicamento(Medicamento*);
		map<string,Medicamento*> getMedicamentos();
		void show();
};

#include "Rol.h"
#endif
