################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aplicacao.cpp \
../src/Cidade.cpp \
../src/InformaDados.cpp \
../src/Linha.cpp \
../src/Parada.cpp \
../src/RecebeDados.cpp \
../src/main.cpp 

OBJS += \
./src/Aplicacao.o \
./src/Cidade.o \
./src/InformaDados.o \
./src/Linha.o \
./src/Parada.o \
./src/RecebeDados.o \
./src/main.o 

CPP_DEPS += \
./src/Aplicacao.d \
./src/Cidade.d \
./src/InformaDados.d \
./src/Linha.d \
./src/Parada.d \
./src/RecebeDados.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


