#debug
KEYCODE_STRING_ENABLE = yes

# for split space keyboard the shared USB endpoint is required to keep all features
ifeq ($(KEYMAP), split)
KEYBOARD_SHARED_EP = yes
endif

#rgb matrix
WS2812_DRIVER_REQUIRED = yes

#other
UART_DRIVER_REQUIRED = yes
