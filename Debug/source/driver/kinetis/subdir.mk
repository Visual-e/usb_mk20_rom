################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/driver/kinetis/usb_dci_kinetis.c 

OBJS += \
./source/driver/kinetis/usb_dci_kinetis.o 

C_DEPS += \
./source/driver/kinetis/usb_dci_kinetis.d 


# Each subdirectory must supply rules for building sources it contributes
source/driver/kinetis/%.o: ../source/driver/kinetis/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-builtin -flto  -g3 -DTWR_K20X128 -I"E:\projects\workspace\usb_mk20_rom\app\cdc" -I"E:\projects\workspace\usb_mk20_rom\app\common\kinetis" -I"E:\projects\workspace\usb_mk20_rom\app\common" -I"E:\projects\workspace\usb_mk20_rom\source\class" -I"E:\projects\workspace\usb_mk20_rom\source\common" -I"E:\projects\workspace\usb_mk20_rom\source\driver" -I"E:\projects\workspace\usb_mk20_rom\source\driver\kinetis" -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


