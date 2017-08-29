################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/ctrlapp.cpp \
/home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/devicehandler.cpp \
/home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/devices.cpp \
/home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/systembox.cpp 

OBJS += \
./ctrlapp/ctrlapp.o \
./ctrlapp/devicehandler.o \
./ctrlapp/devices.o \
./ctrlapp/systembox.o 

CPP_DEPS += \
./ctrlapp/ctrlapp.d \
./ctrlapp/devicehandler.d \
./ctrlapp/devices.d \
./ctrlapp/systembox.d 


# Each subdirectory must supply rules for building sources it contributes
ctrlapp/ctrlapp.o: /home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/ctrlapp.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I/home/yarib/ZYBO_projects/app_workspace -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ctrlapp/devicehandler.o: /home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/devicehandler.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I/home/yarib/ZYBO_projects/app_workspace -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ctrlapp/devices.o: /home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/devices.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I/home/yarib/ZYBO_projects/app_workspace -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ctrlapp/systembox.o: /home/yarib/ZYBO_projects/app_workspace/ctrlapp/src/systembox.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -I/home/yarib/ZYBO_projects/app_workspace -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


