#include "Medico.h"
#include "Socio.h"
/*
int main(){

	Fecha* nacimiento = new Fecha(1,2,3);
	Usuario* observador = new Usuario(1234,"nombre","apellido",M,false,*nacimiento);
	Socio* s = new Socio(observador);
	observador->agregarRol(s);

	nacimiento = new Fecha(4,5,6);
	Usuario* medico_observando = new Usuario(9876,"nombre","apellido",F, true,*nacimiento);
	Medico* m_observando = new Medico(medico_observando);
	medico_observando->agregarRol(m_observando);

	nacimiento = new Fecha(4,5,6);
	Usuario* medico_nuevo = new Usuario(5698,"nombre","apellido",M, true,*nacimiento);
	Medico* m_nuevo = new Medico(medico_nuevo);
	medico_nuevo->agregarRol(m_nuevo);

	m_observando->seguir(s);

	Fecha* f = new Fecha(99,88,77);
	s->notifyall(m_nuevo,*f,true);
	s->notifyall(m_observando,*f,true);//No lo tendria que mostrar

	m_observando->showNotificaciones();

	return 0;
}*/
