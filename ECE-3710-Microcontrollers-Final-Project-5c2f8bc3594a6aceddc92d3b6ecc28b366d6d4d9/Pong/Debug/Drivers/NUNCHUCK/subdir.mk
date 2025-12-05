################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/NUNCHUCK/nunchuck.c 

OBJS += \
./Drivers/NUNCHUCK/nunchuck.o 

C_DEPS += \
./Drivers/NUNCHUCK/nunchuck.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/NUNCHUCK/%.o Drivers/NUNCHUCK/%.su Drivers/NUNCHUCK/%.cyclo: ../Drivers/NUNCHUCK/%.c Drivers/NUNCHUCK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/austi/Documents/USU/junor year/microcontrollers/FInal Project/Pong/Drivers/OLED" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/austi/Documents/USU/junor year/microcontrollers/FInal Project/Pong/Drivers/NUNCHUCK" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-NUNCHUCK

clean-Drivers-2f-NUNCHUCK:
	-$(RM) ./Drivers/NUNCHUCK/nunchuck.cyclo ./Drivers/NUNCHUCK/nunchuck.d ./Drivers/NUNCHUCK/nunchuck.o ./Drivers/NUNCHUCK/nunchuck.su

.PHONY: clean-Drivers-2f-NUNCHUCK

