#include <CP74HC595.h>


CP74HC595 led(2/* DS*/, 3/* SH_CP*/, 4/* ST_CP*/, 16/* Pin*/);  // DS, SH_CP, ST_CP, Pins

void setup() {
    
}

void loop() {
    led.setPin(0,HIGH);
    delay(100);
    led.setPin(0,LOW);
    delay(100);

}
