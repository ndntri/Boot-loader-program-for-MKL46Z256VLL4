################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/BOOT.c \
../Sources/FLASH.c \
../Sources/QUEUE.c \
../Sources/SREC.c \
../Sources/main.c 

OBJS += \
./Sources/BOOT.o \
./Sources/FLASH.o \
./Sources/QUEUE.o \
./Sources/SREC.o \
./Sources/main.o 

C_DEPS += \
./Sources/BOOT.d \
./Sources/FLASH.d \
./Sources/QUEUE.d \
./Sources/SREC.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


