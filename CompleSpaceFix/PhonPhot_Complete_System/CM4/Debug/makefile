################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include X-CUBE-AI/App/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Common/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := PhonPhot_Complete_CM4
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
PhonPhot_Complete_CM4.elf \

MAP_FILES += \
PhonPhot_Complete_CM4.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PhonPhot_Complete_CM4.list \


# All Target
all: main-build

# Main-build Target
main-build: PhonPhot_Complete_CM4.elf secondary-outputs

# Tool invocations
PhonPhot_Complete_CM4.elf PhonPhot_Complete_CM4.map: $(OBJS) $(USER_OBJS) C:\Users\evanr\MiniMachineSTM32Work\PhononsPhotons-TinkerSpace\CompleSpaceFix\PhonPhot_Complete_System\CM4\STM32H745XIHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "PhonPhot_Complete_CM4.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\evanr\MiniMachineSTM32Work\PhononsPhotons-TinkerSpace\CompleSpaceFix\PhonPhot_Complete_System\CM4\STM32H745XIHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PhonPhot_Complete_CM4.map" -Wl,--gc-sections -static -L"C:\Users\evanr\MiniMachineSTM32Work\PhononsPhotons-TinkerSpace\CompleSpaceFix\PhonPhot_Complete_System\CM4\Lib" -L"C:\Users\evanr\MiniMachineSTM32Work\PhononsPhotons-TinkerSpace\CompleSpaceFix\PhonPhot_Complete_System\CM4\X-CUBE-AI\App" -L../../Middlewares/ST/AI/Lib --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PhonPhot_Complete_CM4.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PhonPhot_Complete_CM4.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) PhonPhot_Complete_CM4.elf PhonPhot_Complete_CM4.list PhonPhot_Complete_CM4.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
