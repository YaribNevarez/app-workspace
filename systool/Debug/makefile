################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include extension_framework/Debug/base_framework/network/subdir.mk
-include extension_framework/Debug/base_framework/hid/subdir.mk
-include extension_framework/Debug/base_framework/device/subdir.mk
-include extension_framework/Debug/base_framework/application/subdir.mk
-include extension_framework/Debug/subdir.mk
-include extension_framework/subdir.mk
-include base_framework/network/subdir.mk
-include base_framework/hid/subdir.mk
-include base_framework/device/subdir.mk
-include base_framework/application/subdir.mk
-include base_framework/Debug/network/subdir.mk
-include base_framework/Debug/hid/subdir.mk
-include base_framework/Debug/device/subdir.mk
-include base_framework/Debug/application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
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
ELFSIZE += \
systool.elf.size \


# All Target
all: systool.elf secondary-outputs

# Tool invocations
systool.elf: $(OBJS)  $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linux g++ linker'
	arm-xilinx-linux-gnueabi-g++ -pthread -static -o "systool.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

systool.elf.size: systool.elf
	@echo 'Invoking: ARM Linux Print Size'
	arm-xilinx-linux-gnueabi-size systool.elf  |tee "systool.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS)$(ELFSIZE) systool.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
