################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aplicacao.cpp \
../src/Cidade.cpp \
../src/Hora.cpp \
../src/Horario.cpp \
../src/InformaDados.cpp \
../src/Linha.cpp \
../src/Main.cpp \
../src/Minuto.cpp \
../src/Parada.cpp \
../src/RecebeDados.cpp \
../src/Segundo.cpp \
../src/Tempo.cpp 

OBJS += \
./src/Aplicacao.o \
./src/Cidade.o \
./src/Hora.o \
./src/Horario.o \
./src/InformaDados.o \
./src/Linha.o \
./src/Main.o \
./src/Minuto.o \
./src/Parada.o \
./src/RecebeDados.o \
./src/Segundo.o \
./src/Tempo.o 

CPP_DEPS += \
./src/Aplicacao.d \
./src/Cidade.d \
./src/Hora.d \
./src/Horario.d \
./src/InformaDados.d \
./src/Linha.d \
./src/Main.d \
./src/Minuto.d \
./src/Parada.d \
./src/RecebeDados.d \
./src/Segundo.d \
./src/Tempo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


