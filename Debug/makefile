################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include source/driver/kinetis/subdir.mk
-include source/driver/subdir.mk
-include source/common/subdir.mk
-include source/class/subdir.mk
-include app/common/kinetis/subdir.mk
-include app/common/subdir.mk
-include app/cdc/subdir.mk
-include System/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ve_k20_usb_cdc.hex \

SECONDARY_SIZE += \
ve_k20_usb_cdc.siz \


# All Target
all: ve_k20_usb_cdc.elf secondary-outputs

# Tool invocations
ve_k20_usb_cdc.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-builtin -flto  -g3 -T "E:\projects\workspace\usb_mk20_rom\System\MK20D32xxx5_flash.ld" -Xlinker --gc-sections -Wl,-Map,"ve_k20_usb_cdc.map" -Xlinker --cref -specs=nano.specs -specs=nosys.specs -o "ve_k20_usb_cdc.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ve_k20_usb_cdc.hex: ve_k20_usb_cdc.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "ve_k20_usb_cdc.elf"  "ve_k20_usb_cdc.hex"
	@echo 'Finished building: $@'
	@echo ' '

ve_k20_usb_cdc.siz: ve_k20_usb_cdc.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "ve_k20_usb_cdc.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) ve_k20_usb_cdc.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
