################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Administrador.cpp \
../ConReserva.cpp \
../Consulta.cpp \
../ControladorConsultas.cpp \
../ControladorDiagnosticos.cpp \
../ControladorTratamientos.cpp \
../ControladorUsuarios.cpp \
../DataConReserva.cpp \
../DataConsulta.cpp \
../DataDiagnostico.cpp \
../DataEmergencia.cpp \
../DataHistorial.cpp \
../DataMedico.cpp \
../DataRep.cpp \
../DataTratamiento.cpp \
../DataUsuario.cpp \
../Diagnostico.cpp \
../Emergencia.cpp \
../Farmacologico.cpp \
../Fecha.cpp \
../HistorialNotificaciones.cpp \
../IObserver.cpp \
../ManejadorAdministradores.cpp \
../ManejadorMedicamentos.cpp \
../ManejadorMedicos.cpp \
../ManejadorSocios.cpp \
../Medicamento.cpp \
../Medico.cpp \
../Notificacion.cpp \
../Quirurjico.cpp \
../Rol.cpp \
../Socio.cpp \
../Tratamiento.cpp \
../Usuario.cpp \
../testConsulta.cpp \
../testDiagnostico.cpp \
../testMMedicamentos.cpp \
../testMMedicos.cpp \
../testMSocios.cpp \
../testObservadores.cpp \
../testTratamiento.cpp 

OBJS += \
./Administrador.o \
./ConReserva.o \
./Consulta.o \
./ControladorConsultas.o \
./ControladorDiagnosticos.o \
./ControladorTratamientos.o \
./ControladorUsuarios.o \
./DataConReserva.o \
./DataConsulta.o \
./DataDiagnostico.o \
./DataEmergencia.o \
./DataHistorial.o \
./DataMedico.o \
./DataRep.o \
./DataTratamiento.o \
./DataUsuario.o \
./Diagnostico.o \
./Emergencia.o \
./Farmacologico.o \
./Fecha.o \
./HistorialNotificaciones.o \
./IObserver.o \
./ManejadorAdministradores.o \
./ManejadorMedicamentos.o \
./ManejadorMedicos.o \
./ManejadorSocios.o \
./Medicamento.o \
./Medico.o \
./Notificacion.o \
./Quirurjico.o \
./Rol.o \
./Socio.o \
./Tratamiento.o \
./Usuario.o \
./testConsulta.o \
./testDiagnostico.o \
./testMMedicamentos.o \
./testMMedicos.o \
./testMSocios.o \
./testObservadores.o \
./testTratamiento.o 

CPP_DEPS += \
./Administrador.d \
./ConReserva.d \
./Consulta.d \
./ControladorConsultas.d \
./ControladorDiagnosticos.d \
./ControladorTratamientos.d \
./ControladorUsuarios.d \
./DataConReserva.d \
./DataConsulta.d \
./DataDiagnostico.d \
./DataEmergencia.d \
./DataHistorial.d \
./DataMedico.d \
./DataRep.d \
./DataTratamiento.d \
./DataUsuario.d \
./Diagnostico.d \
./Emergencia.d \
./Farmacologico.d \
./Fecha.d \
./HistorialNotificaciones.d \
./IObserver.d \
./ManejadorAdministradores.d \
./ManejadorMedicamentos.d \
./ManejadorMedicos.d \
./ManejadorSocios.d \
./Medicamento.d \
./Medico.d \
./Notificacion.d \
./Quirurjico.d \
./Rol.d \
./Socio.d \
./Tratamiento.d \
./Usuario.d \
./testConsulta.d \
./testDiagnostico.d \
./testMMedicamentos.d \
./testMMedicos.d \
./testMSocios.d \
./testObservadores.d \
./testTratamiento.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


