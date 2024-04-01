#include <avr/io.h>

void main() {
    PORTB |= 0b11110000;
    DDRB |= 0b11110000;
    DDRD &= 0b11000011;

    while (1) {
        if (PIND & 0x04) {
            PORTB |= 0x10;
        } else {
            PORTB &= ~0x10;
        }
        if (PIND & 0x08) {
            PORTB |= 0x20;
        } else {
            PORTB &= ~0x20;
        }
        if (PIND & 0x10) {
            PORTB |= 0x40;
        } else {
            PORTB &= ~0x40;
        }
        if (PIND & 0x20) {
            PORTB |= 0x80;
        } else {
            PORTB &= ~0x80;
        }
    }
}