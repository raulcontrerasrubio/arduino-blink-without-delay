# arduino-blink-without-delay
Tested on a MEGA 2560 base. This programs makes the LED of the base blink on a specific and configurable pattern.<br>
Another implementations use the `delay(time)` function, however, that function blocks the thread. This implementation does not use the delay function so it is possible to do another operations besides blinkink of the LED.