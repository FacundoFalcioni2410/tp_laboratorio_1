################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Trabajo\ Practico\ 2.c 

OBJS += \
./src/Trabajo\ Practico\ 2.o 

C_DEPS += \
./src/Trabajo\ Practico\ 2.d 


# Each subdirectory must supply rules for building sources it contributes
src/Trabajo\ Practico\ 2.o: ../src/Trabajo\ Practico\ 2.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Trabajo Practico 2.d" -MT"src/Trabajo\ Practico\ 2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


