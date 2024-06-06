################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/HAL_layer/hal_clock.c \
../Sources/HAL_layer/hal_gpio.c 

OBJS += \
./Sources/HAL_layer/hal_clock.o \
./Sources/HAL_layer/hal_gpio.o 

C_DEPS += \
./Sources/HAL_layer/hal_clock.d \
./Sources/HAL_layer/hal_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/HAL_layer/%.o: ../Sources/HAL_layer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


