################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/kinetis/usb_dci_kinetis.c 

OBJS += \
./driver/kinetis/usb_dci_kinetis.o 

C_DEPS += \
./driver/kinetis/usb_dci_kinetis.d 


# Each subdirectory must supply rules for building sources it contributes
driver/kinetis/%.o: ../driver/kinetis/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DCPU_MK20DX128VFM5 -DTARGET_MK20DX -I"E:\projects\workspace\usb_mk20_rom\class" -I"E:\projects\workspace\usb_mk20_rom\driver" -I"E:\projects\workspace\usb_mk20_rom\driver\kinetis" -I"E:\projects\workspace\usb_mk20_rom\app" -I"E:\projects\workspace\usb_mk20_rom\app\common\kinetis" -std=c11 -include wrapper.h -fshort-wchar -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


