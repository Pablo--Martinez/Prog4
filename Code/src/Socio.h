#ifndef SOCIO_H_
#define SOCIO_H_

#include "Rol.h"
#include "Consulta.h"

using namespace std;

class Usuario;

class Socio: public Rol{
	private:
		set<Consulta*> solicita;
		set<IObserver*> observadores;
	public:
		Socio();
		Socio(Usuario*);
		~Socio();
		void agregarConsulta(Consulta*);
		Consulta* devolverReserva(Fecha);
		set<Consulta*> getConsultasSolicitadas();
		// Operaciones de observador
		void attach(IObserver*);
		void unattach(IObserver*);
		void notifyall(Medico*,Fecha,bool);
		//Opeaciones de strategy
		//set<DataMedico> obtenerMedicosDelPaciente();
		void show();
};

#include "Usuario.h"

#endif /* SOCIO_H_ */
