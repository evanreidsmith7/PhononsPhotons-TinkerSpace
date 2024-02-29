################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../X-CUBE-AI/App/ann_762.c \
../X-CUBE-AI/App/ann_762_data.c \
../X-CUBE-AI/App/ann_762_data_params.c \
../X-CUBE-AI/App/app_x-cube-ai.c 

OBJS += \
./X-CUBE-AI/App/ann_762.o \
./X-CUBE-AI/App/ann_762_data.o \
./X-CUBE-AI/App/ann_762_data_params.o \
./X-CUBE-AI/App/app_x-cube-ai.o 

C_DEPS += \
./X-CUBE-AI/App/ann_762.d \
./X-CUBE-AI/App/ann_762_data.d \
./X-CUBE-AI/App/ann_762_data_params.d \
./X-CUBE-AI/App/app_x-cube-ai.d 


# Each subdirectory must supply rules for building sources it contributes
X-CUBE-AI/App/%.o X-CUBE-AI/App/%.su X-CUBE-AI/App/%.cyclo: ../X-CUBE-AI/App/%.c X-CUBE-AI/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Lib/Include/dsp -I../Lib/Include -I../Lib/PrivateInclude -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I"../../Drivers/CMSIS/Device/ST/STM32H7xx/Include" -I"C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/CompleSpaceFix/PhonPhot_Complete_System/CM4/X-CUBE-AI/App" -I"C:/Users/evanr/MiniMachineSTM32Work/PhononsPhotons-TinkerSpace/CompleSpaceFix/PhonPhot_Complete_System/Middlewares/ST/AI/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-X-2d-CUBE-2d-AI-2f-App

clean-X-2d-CUBE-2d-AI-2f-App:
	-$(RM) ./X-CUBE-AI/App/ann_762.cyclo ./X-CUBE-AI/App/ann_762.d ./X-CUBE-AI/App/ann_762.o ./X-CUBE-AI/App/ann_762.su ./X-CUBE-AI/App/ann_762_data.cyclo ./X-CUBE-AI/App/ann_762_data.d ./X-CUBE-AI/App/ann_762_data.o ./X-CUBE-AI/App/ann_762_data.su ./X-CUBE-AI/App/ann_762_data_params.cyclo ./X-CUBE-AI/App/ann_762_data_params.d ./X-CUBE-AI/App/ann_762_data_params.o ./X-CUBE-AI/App/ann_762_data_params.su ./X-CUBE-AI/App/app_x-cube-ai.cyclo ./X-CUBE-AI/App/app_x-cube-ai.d ./X-CUBE-AI/App/app_x-cube-ai.o ./X-CUBE-AI/App/app_x-cube-ai.su

.PHONY: clean-X-2d-CUBE-2d-AI-2f-App

