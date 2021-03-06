# MCU name
MCU = STM32F303
BOARD = QMK_PROTON_C


# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
MIDI_ENABLE = no            # MIDI support
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
<<<<<<< HEAD
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
<<<<<<< HEAD
=======
=======
>>>>>>> 9c94de070a651c477ed8d65228af4255a35ea6aa

LAYOUTS = alice alice_split_bs
>>>>>>> 9971caa6327274b230695afb4d76f83bf9b77f3a

DEFAULT_FOLDER = mechlovin/adelais/standard_led/rev2
