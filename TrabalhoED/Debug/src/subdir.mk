################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FachadaPilha.cpp \
../src/InformaDados.cpp \
../src/Lancamento.cpp \
../src/Main.cpp \
../src/Produto.cpp \
../src/RecebeDados.cpp 

OBJS += \
./src/FachadaPilha.o \
./src/InformaDados.o \
./src/Lancamento.o \
./src/Main.o \
./src/Produto.o \
./src/RecebeDados.o 

CPP_DEPS += \
./src/FachadaPilha.d \
./src/InformaDados.d \
./src/Lancamento.d \
./src/Main.d \
./src/Produto.d \
./src/RecebeDados.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


