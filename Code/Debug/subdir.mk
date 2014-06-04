################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Consulta.cpp \
../Diagnostico.cpp \
../Fecha.cpp \
../ManejadorMedicamentos.cpp \
../Medicamento.cpp \
../Rol.cpp \
../Tratamiento.cpp \
../Usuario.cpp \
../testConsulta.cpp \
../testDiagnostico.cpp \
../testMMedicamentos.cpp \
../testTratamiento.cpp 

OBJS += \
./Consulta.o \
./Diagnostico.o \
./Fecha.o \
./ManejadorMedicamentos.o \
./Medicamento.o \
./Rol.o \
./Tratamiento.o \
./Usuario.o \
./testConsulta.o \
./testDiagnostico.o \
./testMMedicamentos.o \
./testTratamiento.o 

CPP_DEPS += \
./Consulta.d \
./Diagnostico.d \
./Fecha.d \
./ManejadorMedicamentos.d \
./Medicamento.d \
./Rol.d \
./Tratamiento.d \
./Usuario.d \
./testConsulta.d \
./testDiagnostico.d \
./testMMedicamentos.d \
./testTratamiento.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


