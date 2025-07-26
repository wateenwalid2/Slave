################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries_Eclipse/EXT_INT/EXTINT_Program.c 

OBJS += \
./Libraries_Eclipse/EXT_INT/EXTINT_Program.o 

C_DEPS += \
./Libraries_Eclipse/EXT_INT/EXTINT_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries_Eclipse/EXT_INT/%.o: ../Libraries_Eclipse/EXT_INT/%.c Libraries_Eclipse/EXT_INT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\soft zone\eclipse-workspace\Libraries_Eclipse\LIB" -I"C:\Users\soft zone\eclipse-workspace\Libraries_Eclipse" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


