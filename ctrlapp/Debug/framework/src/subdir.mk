################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/yarib/ZYBO_projects/app_workspace/framework/src/devicehandler.cpp \
/home/yarib/ZYBO_projects/app_workspace/framework/src/devices.cpp \
/home/yarib/ZYBO_projects/app_workspace/framework/src/systembox.cpp 

OBJS += \
./framework/src/devicehandler.o \
./framework/src/devices.o \
./framework/src/systembox.o 

CPP_DEPS += \
./framework/src/devicehandler.d \
./framework/src/devices.d \
./framework/src/systembox.d 


# Each subdirectory must supply rules for building sources it contributes
framework/src/devicehandler.o: /home/yarib/ZYBO_projects/app_workspace/framework/src/devicehandler.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I"/home/yarib/ZYBO_projects/app_workspace/framework/src" -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

framework/src/devices.o: /home/yarib/ZYBO_projects/app_workspace/framework/src/devices.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I"/home/yarib/ZYBO_projects/app_workspace/framework/src" -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

framework/src/systembox.o: /home/yarib/ZYBO_projects/app_workspace/framework/src/systembox.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I"/home/yarib/ZYBO_projects/app_workspace/framework/src" -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


