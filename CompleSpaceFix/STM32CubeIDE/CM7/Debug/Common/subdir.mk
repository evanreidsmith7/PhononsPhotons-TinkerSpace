################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Common/Src/system_stm32h7xx_dualcore_boot_cm4_cm7.c 

C_DEPS += \
./Common/system_stm32h7xx_dualcore_boot_cm4_cm7.d 

OBJS += \
./Common/system_stm32h7xx_dualcore_boot_cm4_cm7.o 


# Each subdirectory must supply rules for building sources it contributes
Common/system_stm32h7xx_dualcore_boot_cm4_cm7.o: C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/Common/Src/system_stm32h7xx_dualcore_boot_cm4_cm7.c Common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Application/User/Core/Inc -I../../Drivers/BSP/Components/mt48lc4m32b2 -I../../Drivers/BSP/Components/ft5336 -I../../Drivers/BSP/Components/mt25tl01g -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H745I-DISCO -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/ST/touchgfx/3rdparty/libjpeg/include -I../../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor -I../../TouchGFX/generated/simulator/include -I../../TouchGFX/App -I../../TouchGFX/target -I../../TouchGFX/target/generated -I../../TouchGFX/gui/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/gui_generated/include -I"C:/Projects/PhononsPhotons-TinkerSpace/CompleSpaceFix/STM32CubeIDE/CM7/Application/User/gui" -I../../CM7/../../PhonPhot_Complete_System/Middlewares/ST/touchgfx/framework/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/fonts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/gui_generated/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/images/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/texts/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/generated/videos/include -I../../CM7/../../PhonPhot_Complete_System/TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common

clean-Common:
	-$(RM) ./Common/system_stm32h7xx_dualcore_boot_cm4_cm7.cyclo ./Common/system_stm32h7xx_dualcore_boot_cm4_cm7.d ./Common/system_stm32h7xx_dualcore_boot_cm4_cm7.o ./Common/system_stm32h7xx_dualcore_boot_cm4_cm7.su

.PHONY: clean-Common
