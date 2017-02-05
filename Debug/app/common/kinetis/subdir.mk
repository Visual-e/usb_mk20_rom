################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/common/kinetis/RealTimerCounter_kinetis.c \
../app/common/kinetis/printf.c \
../app/common/kinetis/sci.c \
../app/common/kinetis/wdt_kinetis.c 

OBJS += \
./app/common/kinetis/RealTimerCounter_kinetis.o \
./app/common/kinetis/printf.o \
./app/common/kinetis/sci.o \
./app/common/kinetis/wdt_kinetis.o 

C_DEPS += \
./app/common/kinetis/RealTimerCounter_kinetis.d \
./app/common/kinetis/printf.d \
./app/common/kinetis/sci.d \
./app/common/kinetis/wdt_kinetis.d 


# Each subdirectory must supply rules for building sources it contributes
app/common/kinetis/%.o: ../app/common/kinetis/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-builtin -flto  -g3 -DTWR_K20X128 -I"E:\projects\workspace\usb_mk20_rom\app\cdc" -I"E:\projects\workspace\usb_mk20_rom\app\common\kinetis" -I"E:\projects\workspace\usb_mk20_rom\app\common" -I"E:\projects\workspace\usb_mk20_rom\source\class" -I"E:\projects\workspace\usb_mk20_rom\source\common" -I"E:\projects\workspace\usb_mk20_rom\source\driver" -I"E:\projects\workspace\usb_mk20_rom\source\driver\kinetis" -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


