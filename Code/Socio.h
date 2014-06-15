#ifndef SOCIO_H_
#define SOCIO_H_

#include "Rol.h"
class Usuario;
//class Rol;

class Socio: public Rol{
	private:
		map<Fecha,Consulta*> solicita;
		set<IObserver*> observadores;
	public:
		Socio();
		Socio(Usuario*);
		~Socio();
		void agregarConsulta(Consulta*);
		Consulta* devolverReserva(Fecha);
		map<Fecha,Consulta*> getConsultasSolicitadas();
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
