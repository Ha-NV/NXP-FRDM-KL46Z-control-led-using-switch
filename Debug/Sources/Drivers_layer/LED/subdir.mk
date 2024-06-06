################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Drivers_layer/LED/led.c 

OBJS += \
./Sources/Drivers_layer/LED/led.o 

C_DEPS += \
./Sources/Drivers_layer/LED/led.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Drivers_layer/LED/%.o: ../Sources/Drivers_layer/LED/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


