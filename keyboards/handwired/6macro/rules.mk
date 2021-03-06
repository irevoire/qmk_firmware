# MCU name
MCU = atmega32u2

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      	# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes      	# Mouse keys
EXTRAKEY_ENABLE = yes      	# Audio control and System control
CONSOLE_ENABLE = no        	# Console for debug
COMMAND_ENABLE = no        	# Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no      	# Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes          	# USB Nkey Rollover
<<<<<<< HEAD
RGB_MATRIX_ENABLE = yes     # Enable per-key coordinate based RGB effects. Do not enable with RGBlight (+8500)
RGB_MATRIX_DRIVER = WS2812
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
=======
RGB_MATRIX_ENABLE = no     # Enable per-key coordinate based RGB effects. Do not enable with RGBlight
RGB_MATRIX_DRIVER = WS2812
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
>>>>>>> 9971caa6327274b230695afb4d76f83bf9b77f3a
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
UNICODE_ENABLE = yes        # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
