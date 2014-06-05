################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Consulta.cpp \
../ControladorConsultas.cpp \
../ControladorDiagnosticos.cpp \
../ControladorTratamientos.cpp \
../ControladorUsuarios.cpp \
../Diagnostico.cpp \
../Fecha.cpp \
../ManejadorMedicamentos.cpp \
../ManejadorMedicos.cpp \
../ManejadorSocios.cpp \
../Medicamento.cpp \
../Rol.cpp \
../Tratamiento.cpp \
../Usuario.cpp \
../testConsulta.cpp \
../testDiagnostico.cpp \
../testMMedicamentos.cpp \
../testMMedicos.cpp \
../testMSocios.cpp \
../testTratamiento.cpp 

OBJS += \
./Consulta.o \
./ControladorConsultas.o \
./ControladorDiagnosticos.o \
./ControladorTratamientos.o \
./ControladorUsuarios.o \
./Diagnostico.o \
./Fecha.o \
./ManejadorMedicamentos.o \
./ManejadorMedicos.o \
./ManejadorSocios.o \
./Medicamento.o \
./Rol.o \
./Tratamiento.o \
./Usuario.o \
./testConsulta.o \
./testDiagnostico.o \
./testMMedicamentos.o \
./testMMedicos.o \
./testMSocios.o \
./testTratamiento.o 

CPP_DEPS += \
./Consulta.d \
./ControladorConsultas.d \
./ControladorDiagnosticos.d \
./ControladorTratamientos.d \
./ControladorUsuarios.d \
./Diagnostico.d \
./Fecha.d \
./ManejadorMedicamentos.d \
./ManejadorMedicos.d \
./ManejadorSocios.d \
./Medicamento.d \
./Rol.d \
./Tratamiento.d \
./Usuario.d \
./testConsulta.d \
./testDiagnostico.d \
./testMMedicamentos.d \
./testMMedicos.d \
./testMSocios.d \
./testTratamiento.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


