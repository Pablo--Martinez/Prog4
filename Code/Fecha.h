#ifndef FECHA
#define FECHA

#include <iostream>

using namespace std;

class Fecha{
	private:
		int dia;
		int mes;
		int anio;
		int hora;
		int minutos;
		
	public:
		Fecha();
		Fecha(int,int,int); //dia-mes-anio
		Fecha(int,int,int,int,int); //dia-mes-anio-hora
		Fecha(const Fecha&);
		void setDia(int);
		void setMes(int);
		void setAnio(int);
		void setHora(int);
		void setMinutos(int);
		int getDia();
		int getMes();
		int getAnio();
		int getHora();
		int getMinutos();
		bool operator==(const Fecha&);
		bool operator<(const Fecha&);
		bool operator>(const Fecha&);
		void show();
};

#endif
