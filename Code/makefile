all: Medicamento.o Diagnostico.o Tratamiento.o Farmacologico.o Quirurjico.o Rol.o \
     IObserver.o Medico.o Socio.o Administrador.o Consulta.o Emergencia.o ConReserva.o \
     ManejadorMedicamentos.o ManejadorAdministradores.o ManejadorMedicos.o ManejadorSocios.o \
     ControladorConsultas.o ControladorDiagnosticos.o Fecha.o DataAltaReactivacion.o DataConReserva.o \
     DataConsulta.o DataDiagnostico.o DataEmergencia.o DataHistorial.o DataMedico.o DataRep.o \
     DataTratamiento.o DataUsuario.o ManejadorRepresentaciones.o ControladorUsuarios.o Notificacion.o \
     RelojSistema.o ControladorTratamientos.o MedicosDelPaciente.o MedicosLibres.o Strategy.o Usuario.o
     
	g++ -o Sistema Sistema.cpp Medicamento.o Diagnostico.o Tratamiento.o Farmacologico.o Quirurjico.o Rol.o \
     IObserver.o Medico.o Socio.o Administrador.o Consulta.o Emergencia.o ConReserva.o \
     ManejadorMedicamentos.o ManejadorAdministradores.o ManejadorMedicos.o ManejadorSocios.o \
     ControladorConsultas.o ControladorDiagnosticos.o Fecha.o DataAltaReactivacion.o DataConReserva.o \
     DataConsulta.o DataDiagnostico.o DataEmergencia.o DataHistorial.o DataMedico.o DataRep.o \
     DataTratamiento.o DataUsuario.o ManejadorRepresentaciones.o ControladorUsuarios.o Notificacion.o \
     RelojSistema.o ControladorTratamientos.o MedicosDelPaciente.o MedicosLibres.o Strategy.o Usuario.o

#Clases 
Usuario.o:
	g++ -Wall -Werror -c Usuario.h Usuario.cpp
	
Strategy.o:
	g++ -Wall -Werror -c Strategy.h Strategy.cpp
	
MedicosDelPaciente.o:
	g++ -Wall -Werror -c MedicosDelPaciente.h MedicosDelPaciente.cpp
	
MedicosLibres.o:
	g++ -Wall -Werror -c MedicosLibres.h MedicosLibres.cpp
	
RelojSistema.o:
	g++ -Wall -Werror -c RelojSistema.h RelojSistema.cpp
	
Notificacion.o:
	g++ -Wall -Werror -c Notificacion.h Notificacion.cpp
	
Medicamento.o:
	g++ -Wall -Werror -c Medicamento.h Medicamento.cpp
	
Tratamiento.o:
	g++ -Wall -Werror -c Tratamiento.h Tratamiento.cpp
	
Farmacologico.o:
	g++ -Wall -Werror -c Farmacologico.h Farmacologico.cpp
	
Quirurjico.o:
	g++ -Wall -Werror -c Quirurjico.h Quirurjico.cpp
	
Rol.o:
	g++ -Wall -Werror -c Rol.h Rol.cpp
	
IObserver.o:
	g++ -Wall -Werror -c IObserver.h IObserver.cpp
	
Medico.o:
	g++ -Wall -Werror -c Medico.h Medico.cpp
	
Socio.o:
	g++ -Wall -Werror -c Socio.h Socio.cpp
	
Diagnostico.o:
	g++ -Wall -Werror -c Diagnostico.h Diagnostico.cpp
	
Administrador.o:
	g++ -Wall -Werror -c Administrador.h Administrador.cpp
	
Consulta.o:
	g++ -Wall -Werror -c Consulta.h Consulta.cpp
	
ConReserva.o:
	g++ -Wall -Werror -c ConReserva.h ConReserva.cpp
	
Emergencia.o:
	g++ -Wall -Werror -c Emergencia.h Emergencia.cpp
	
#Controladores/Manejadores

ManejadorRepresentaciones.o:
	g++ -Wall -Werror -c ManejadorRepresentaciones.h ManejadorRepresentaciones.cpp
	
ControladorTratamientos.o:
	g++ -Wall -Werror -c ControladorTratamientos.h ControladorTratamientos.cpp

ControladorConsultas.o:
	g++ -Wall -Werror -c ControladorConsultas.h ControladorConsultas.cpp
	
ManejadorMedicamentos.o:
	g++ -Wall -Werror -c ManejadorMedicamentos.h ManejadorMedicamentos.cpp
	
ControladorDiagnosticos.o:
	g++ -Wall -Werror -c ControladorDiagnosticos.h ControladorDiagnosticos.cpp
	
ManejadorMedicos.o:
	g++ -Wall -Werror -c ManejadorMedicos.h ManejadorMedicos.cpp
		
ManejadorSocios.o:
	g++ -Wall -Werror -c ManejadorSocios.h ManejadorSocios.cpp
	
ManejadorAdministradores.o:
	g++ -Wall -Werror -c ManejadorAdministradores.h ManejadorAdministradores.cpp
	
ControladorUsuarios.o:
	g++ -Wall -Werror -c ControladorUsuarios.h ControladorUsuarios.cpp
	
#Datatypes
Fecha.o:
	g++ -Wall -Werror -c Fecha.h Fecha.cpp
	
DataUsuario.o:
	g++ -Wall -Werror -c DataUsuario.h DataUsuario.cpp
	
DataAltaReactivacion.o:
	g++ -Wall -Werror -c DataAltaReactivacion.h DataAltaReactivacion.cpp
	
DataConsulta.o:
	g++ -Wall -Werror -c DataConsulta.h DataConsulta.cpp
	
DataConReserva.o:
	g++ -Wall -Werror -c DataConReserva.h DataConReserva.cpp

DataEmergencia.o:
	g++ -Wall -Werror -c DataEmergencia.h DataEmergencia.cpp
	
DataDiagnostico.o:
	g++ -Wall -Werror -c DataDiagnostico.h DataDiagnostico.cpp
	
DataHistorial.o:
	g++ -Wall -Werror -c DataHistorial.h DataHistorial.cpp
	
DataMedico.o:
	g++ -Wall -Werror -c DataMedico.h DataMedico.cpp
	
DataRep.o:
	g++ -Wall -Werror -c DataRep.h DataRep.cpp
	
DataTratamiento.o:
	g++ -Wall -Werror -c DataTratamiento.h DataTratamiento.cpp

clear:
	rm *.o 
	rm *.h.gch

