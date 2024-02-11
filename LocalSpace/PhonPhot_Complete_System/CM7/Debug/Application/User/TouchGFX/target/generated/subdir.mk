################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/TouchGFX/target/generated/OSWrappers.cpp \
C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/TouchGFX/target/generated/STM32DMA.cpp \
C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/TouchGFX/target/generated/TouchGFXConfiguration.cpp \
C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/TouchGFX/target/generated/TouchGFXGeneratedHAL.cpp 

OBJS += \
./Application/User/TouchGFX/target/generated/OSWrappers.o \
./Application/User/TouchGFX/target/generated/STM32DMA.o \
./Application/User/TouchGFX/target/generated/TouchGFXConfiguration.o \
./Application/User/TouchGFX/target/generated/TouchGFXGeneratedHAL.o 

CPP_DEPS += \
./Application/User/TouchGFX/target/generated/OSWrappers.d \
./Application/User/TouchGFX/target/generated/STM32DMA.d \
./Application/User/TouchGFX/target/generated/TouchGFXConfiguration.d \
./Application/User/TouchGFX/target/generated/TouchGFXGeneratedHAL.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/TouchGFX/target/generated/OSWrappers.o: C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/TouchGFX/target/generated/OSWrappers.cpp Application/User/TouchGFX/target/generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/CM7/Application/User/gui" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/TouchGFX/target/generated/STM32DMA.o: C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/TouchGFX/target/generated/STM32DMA.cpp Application/User/TouchGFX/target/generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/CM7/Application/User/gui" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/TouchGFX/target/generated/TouchGFXConfiguration.o: C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/TouchGFX/target/generated/TouchGFXConfiguration.cpp Application/User/TouchGFX/target/generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/CM7/Application/User/gui" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/TouchGFX/target/generated/TouchGFXGeneratedHAL.o: C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/TouchGFX/target/generated/TouchGFXGeneratedHAL.cpp Application/User/TouchGFX/target/generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/LocalSpace/PhonPhot_Complete_System/CM7/Application/User/gui" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-TouchGFX-2f-target-2f-generated

clean-Application-2f-User-2f-TouchGFX-2f-target-2f-generated:
	-$(RM) ./Application/User/TouchGFX/target/generated/OSWrappers.cyclo ./Application/User/TouchGFX/target/generated/OSWrappers.d ./Application/User/TouchGFX/target/generated/OSWrappers.o ./Application/User/TouchGFX/target/generated/OSWrappers.su ./Application/User/TouchGFX/target/generated/STM32DMA.cyclo ./Application/User/TouchGFX/target/generated/STM32DMA.d ./Application/User/TouchGFX/target/generated/STM32DMA.o ./Application/User/TouchGFX/target/generated/STM32DMA.su ./Application/User/TouchGFX/target/generated/TouchGFXConfiguration.cyclo ./Application/User/TouchGFX/target/generated/TouchGFXConfiguration.d ./Application/User/TouchGFX/target/generated/TouchGFXConfiguration.o ./Application/User/TouchGFX/target/generated/TouchGFXConfiguration.su ./Application/User/TouchGFX/target/generated/TouchGFXGeneratedHAL.cyclo ./Application/User/TouchGFX/target/generated/TouchGFXGeneratedHAL.d ./Application/User/TouchGFX/target/generated/TouchGFXGeneratedHAL.o ./Application/User/TouchGFX/target/generated/TouchGFXGeneratedHAL.su

.PHONY: clean-Application-2f-User-2f-TouchGFX-2f-target-2f-generated

