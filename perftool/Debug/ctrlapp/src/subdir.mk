################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/ctrlapp.cpp \
/home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/devicehandler.cpp \
/home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/devices.cpp 

OBJS += \
./ctrlapp/src/ctrlapp.o \
./ctrlapp/src/devicehandler.o \
./ctrlapp/src/devices.o 

CPP_DEPS += \
./ctrlapp/src/ctrlapp.d \
./ctrlapp/src/devicehandler.d \
./ctrlapp/src/devices.d 


# Each subdirectory must supply rules for building sources it contributes
ctrlapp/src/ctrlapp.o: /home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/ctrlapp.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I/home/yarib/ZYBO_projects/app_workspace -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ctrlapp/src/devicehandler.o: /home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/devicehandler.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I/home/yarib/ZYBO_projects/app_workspace -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ctrlapp/src/devices.o: /home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/devices.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I/home/yarib/ZYBO_projects/app_workspace -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


