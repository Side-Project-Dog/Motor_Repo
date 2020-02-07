################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP.c \
../CLCD_program.c \
../DIO_programm.c \
../PORT_programm.c \
../Timer0.c 

OBJS += \
./APP.o \
./CLCD_program.o \
./DIO_programm.o \
./PORT_programm.o \
./Timer0.o 

C_DEPS += \
./APP.d \
./CLCD_program.d \
./DIO_programm.d \
./PORT_programm.d \
./Timer0.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


