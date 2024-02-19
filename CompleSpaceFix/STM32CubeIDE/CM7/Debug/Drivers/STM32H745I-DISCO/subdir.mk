################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery.c \
C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_bus.c \
C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_lcd.c \
C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_qspi.c \
C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_sdram.c \
C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_ts.c 

C_DEPS += \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery.d \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_bus.d \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_lcd.d \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_qspi.d \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_sdram.d \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_ts.d 

OBJS += \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery.o \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_bus.o \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_lcd.o \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_qspi.o \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_sdram.o \
./Drivers/STM32H745I-DISCO/stm32h745i_discovery_ts.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32H745I-DISCO/stm32h745i_discovery.o: C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery.c Drivers/STM32H745I-DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/CM7/Application/User/gui" -I../../CM7/../../PhonPhot_Complete_System/Middlewares/ST/touchgfx/framework/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/fonts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/gui_generated/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/images/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/texts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/videos/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32H745I-DISCO/stm32h745i_discovery_bus.o: C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_bus.c Drivers/STM32H745I-DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/CM7/Application/User/gui" -I../../CM7/../../PhonPhot_Complete_System/Middlewares/ST/touchgfx/framework/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/fonts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/gui_generated/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/images/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/texts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/videos/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32H745I-DISCO/stm32h745i_discovery_lcd.o: C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_lcd.c Drivers/STM32H745I-DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/CM7/Application/User/gui" -I../../CM7/../../PhonPhot_Complete_System/Middlewares/ST/touchgfx/framework/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/fonts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/gui_generated/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/images/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/texts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/videos/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32H745I-DISCO/stm32h745i_discovery_qspi.o: C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_qspi.c Drivers/STM32H745I-DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/CM7/Application/User/gui" -I../../CM7/../../PhonPhot_Complete_System/Middlewares/ST/touchgfx/framework/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/fonts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/gui_generated/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/images/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/texts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/videos/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32H745I-DISCO/stm32h745i_discovery_sdram.o: C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_sdram.c Drivers/STM32H745I-DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/CM7/Application/User/gui" -I../../CM7/../../PhonPhot_Complete_System/Middlewares/ST/touchgfx/framework/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/fonts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/gui_generated/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/images/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/texts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/videos/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32H745I-DISCO/stm32h745i_discovery_ts.o: C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Drivers/BSP/STM32H745I-DISCO/stm32h745i_discovery_ts.c Drivers/STM32H745I-DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/CM7/Application/User/gui" -I../../CM7/../../PhonPhot_Complete_System/Middlewares/ST/touchgfx/framework/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/fonts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/gui_generated/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/images/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/texts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/videos/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32H745I-2d-DISCO

clean-Drivers-2f-STM32H745I-2d-DISCO:
	-$(RM) ./Drivers/STM32H745I-DISCO/stm32h745i_discovery.cyclo ./Drivers/STM32H745I-DISCO/stm32h745i_discovery.d ./Drivers/STM32H745I-DISCO/stm32h745i_discovery.o ./Drivers/STM32H745I-DISCO/stm32h745i_discovery.su ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_bus.cyclo ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_bus.d ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_bus.o ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_bus.su ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_lcd.cyclo ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_lcd.d ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_lcd.o ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_lcd.su ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_qspi.cyclo ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_qspi.d ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_qspi.o ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_qspi.su ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_sdram.cyclo ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_sdram.d ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_sdram.o ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_sdram.su ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_ts.cyclo ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_ts.d ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_ts.o ./Drivers/STM32H745I-DISCO/stm32h745i_discovery_ts.su

.PHONY: clean-Drivers-2f-STM32H745I-2d-DISCO
