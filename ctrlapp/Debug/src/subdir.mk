################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ctrlapp.cpp \
../src/devicehandler.cpp \
../src/devices.cpp \
../src/main.cpp \
../src/systembox.cpp 

OBJS += \
./src/ctrlapp.o \
./src/devicehandler.o \
./src/devices.o \
./src/main.o \
./src/systembox.o 

CPP_DEPS += \
./src/ctrlapp.d \
./src/devicehandler.d \
./src/devices.d \
./src/main.d \
./src/systembox.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux g++ compiler'
	arm-xilinx-linux-gnueabi-g++ -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


