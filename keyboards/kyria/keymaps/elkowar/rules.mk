LTO_ENABLE = yes
OLED_DRIVER_ENABLE = no   # Enables the use of OLED displays
ENCODER_ENABLE = no       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
COMBO_ENABLE = yes
UNICODE_ENABLE = yes
TAP_DANCE_ENABLE = yes
STENO_ENABLE = yes
MOUSEKEYS_ENABLE = no
LEADER_ENABLE = yes

SRC += features/casemodes.c
# SRC += g/engine.c

VPATH += keyboards/gboards/

