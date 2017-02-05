################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../class/usb_audio.c \
../class/usb_batt_chg.c \
../class/usb_cdc.c \
../class/usb_cdc_pstn.c \
../class/usb_composite.c \
../class/usb_dfu.c \
../class/usb_hid.c \
../class/usb_msc.c \
../class/usb_msc_scsi.c \
../class/usb_phdc.c \
../class/usb_printer.c \
../class/usb_video.c 

OBJS += \
./class/usb_audio.o \
./class/usb_batt_chg.o \
./class/usb_cdc.o \
./class/usb_cdc_pstn.o \
./class/usb_composite.o \
./class/usb_dfu.o \
./class/usb_hid.o \
./class/usb_msc.o \
./class/usb_msc_scsi.o \
./class/usb_phdc.o \
./class/usb_printer.o \
./class/usb_video.o 

C_DEPS += \
./class/usb_audio.d \
./class/usb_batt_chg.d \
./class/usb_cdc.d \
./class/usb_cdc_pstn.d \
./class/usb_composite.d \
./class/usb_dfu.d \
./class/usb_hid.d \
./class/usb_msc.d \
./class/usb_msc_scsi.d \
./class/usb_phdc.d \
./class/usb_printer.d \
./class/usb_video.d 


# Each subdirectory must supply rules for building sources it contributes
class/%.o: ../class/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DCPU_MK20DX128VFM5 -DTARGET_MK20DX -I"E:\projects\workspace\usb_mk20_rom\class" -I"E:\projects\workspace\usb_mk20_rom\driver" -I"E:\projects\workspace\usb_mk20_rom\driver\kinetis" -I"E:\projects\workspace\usb_mk20_rom\app" -I"E:\projects\workspace\usb_mk20_rom\app\common\kinetis" -std=c11 -include wrapper.h -fshort-wchar -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


