OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
RGBLIGHT_ANIMATIONS = no
WPM_ENABLE = yes
ENCODER_ENABLE = no       # Enables the use of one or more encoders
MOUSEKEY_ENABLE = no

TAP_DANCE_ENABLE = no
STENO_ENABLE = no
BOOTMAGIC_ENABLE =no
TERMINAL_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
KEY_LOCK_ENABLE = no
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
VELOCIKEY_ENABLE = no

EXTRAFLAGS += -flto

SRC += bongo_cat.c frame_manipulation.c test.rs
