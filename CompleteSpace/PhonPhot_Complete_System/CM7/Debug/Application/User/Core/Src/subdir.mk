################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/Core/Src/freertos.c \
../Application/User/Core/Src/ipc_interface.c \
../Application/User/Core/Src/main.c \
../Application/User/Core/Src/main_user.c \
../Application/User/Core/Src/stm32h7xx_hal_msp.c \
../Application/User/Core/Src/stm32h7xx_hal_timebase_tim.c \
../Application/User/Core/Src/stm32h7xx_it.c \
../Application/User/Core/Src/syscalls.c \
../Application/User/Core/Src/sysmem.c 

C_DEPS += \
./Application/User/Core/Src/freertos.d \
./Application/User/Core/Src/ipc_interface.d \
./Application/User/Core/Src/main.d \
./Application/User/Core/Src/main_user.d \
./Application/User/Core/Src/stm32h7xx_hal_msp.d \
./Application/User/Core/Src/stm32h7xx_hal_timebase_tim.d \
./Application/User/Core/Src/stm32h7xx_it.d \
./Application/User/Core/Src/syscalls.d \
./Application/User/Core/Src/sysmem.d 

OBJS += \
./Application/User/Core/Src/freertos.o \
./Application/User/Core/Src/ipc_interface.o \
./Application/User/Core/Src/main.o \
./Application/User/Core/Src/main_user.o \
./Application/User/Core/Src/stm32h7xx_hal_msp.o \
./Application/User/Core/Src/stm32h7xx_hal_timebase_tim.o \
./Application/User/Core/Src/stm32h7xx_it.o \
./Application/User/Core/Src/syscalls.o \
./Application/User/Core/Src/sysmem.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/Src/%.o Application/User/Core/Src/%.su Application/User/Core/Src/%.cyclo: ../Application/User/Core/Src/%.c Application/User/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/CompleteSpace/PhonPhot_Complete_System/CM7/Application/User/gui" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Core-2f-Src

clean-Application-2f-User-2f-Core-2f-Src:
	-$(RM) ./Application/User/Core/Src/freertos.cyclo ./Application/User/Core/Src/freertos.d ./Application/User/Core/Src/freertos.o ./Application/User/Core/Src/freertos.su ./Application/User/Core/Src/ipc_interface.cyclo ./Application/User/Core/Src/ipc_interface.d ./Application/User/Core/Src/ipc_interface.o ./Application/User/Core/Src/ipc_interface.su ./Application/User/Core/Src/main.cyclo ./Application/User/Core/Src/main.d ./Application/User/Core/Src/main.o ./Application/User/Core/Src/main.su ./Application/User/Core/Src/main_user.cyclo ./Application/User/Core/Src/main_user.d ./Application/User/Core/Src/main_user.o ./Application/User/Core/Src/main_user.su ./Application/User/Core/Src/stm32h7xx_hal_msp.cyclo ./Application/User/Core/Src/stm32h7xx_hal_msp.d ./Application/User/Core/Src/stm32h7xx_hal_msp.o ./Application/User/Core/Src/stm32h7xx_hal_msp.su ./Application/User/Core/Src/stm32h7xx_hal_timebase_tim.cyclo ./Application/User/Core/Src/stm32h7xx_hal_timebase_tim.d ./Application/User/Core/Src/stm32h7xx_hal_timebase_tim.o ./Application/User/Core/Src/stm32h7xx_hal_timebase_tim.su ./Application/User/Core/Src/stm32h7xx_it.cyclo ./Application/User/Core/Src/stm32h7xx_it.d ./Application/User/Core/Src/stm32h7xx_it.o ./Application/User/Core/Src/stm32h7xx_it.su ./Application/User/Core/Src/syscalls.cyclo ./Application/User/Core/Src/syscalls.d ./Application/User/Core/Src/syscalls.o ./Application/User/Core/Src/syscalls.su ./Application/User/Core/Src/sysmem.cyclo ./Application/User/Core/Src/sysmem.d ./Application/User/Core/Src/sysmem.o ./Application/User/Core/Src/sysmem.su

.PHONY: clean-Application-2f-User-2f-Core-2f-Src

