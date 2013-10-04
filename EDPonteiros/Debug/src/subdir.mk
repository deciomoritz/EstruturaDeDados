################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cidade.cpp \
../src/InformaDados.cpp \
../src/Linha.cpp \
../src/Main.cpp \
../src/Parada.cpp \
../src/RecebeDados.cpp 

OBJS += \
./src/Cidade.o \
./src/InformaDados.o \
./src/Linha.o \
./src/Main.o \
./src/Parada.o \
./src/RecebeDados.o 

CPP_DEPS += \
./src/Cidade.d \
./src/InformaDados.d \
./src/Linha.d \
./src/Main.d \
./src/Parada.d \
./src/RecebeDados.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


