################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Application/User/Startup/startup_stm32h745xihx.s 

S_DEPS += \
./Application/User/Startup/startup_stm32h745xihx.d 

OBJS += \
./Application/User/Startup/startup_stm32h745xihx.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Startup/%.o: ../Application/User/Startup/%.s Application/User/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/CM7/Application/User/gui" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-User-2f-Startup

clean-Application-2f-User-2f-Startup:
	-$(RM) ./Application/User/Startup/startup_stm32h745xihx.d ./Application/User/Startup/startup_stm32h745xihx.o

.PHONY: clean-Application-2f-User-2f-Startup

