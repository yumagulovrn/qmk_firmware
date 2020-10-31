#include <stdio.h>
#include "crkbd.h"

char host_led_state_str[24];

const char *read_host_led_state(void)
{
  uint8_t leds = host_keyboard_leds();
  snprintf(host_led_state_str, sizeof(host_led_state_str), "NL:%s CL:%s SL:%s",
           (leds & (1 << USB_LED_NUM_LOCK)) ? " on" : "off",
           (leds & (1 << USB_LED_CAPS_LOCK)) ? " on" : "off",
           (leds & (1 << USB_LED_SCROLL_LOCK)) ? " on" : "off");

  return host_led_state_str;
}
