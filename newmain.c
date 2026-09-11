#include <xc.h>

// CONFIGURATION BITS
#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

#define _XTAL_FREQ 20000000   

void main(void) {
    TRISB = 0x00;   // All PORTB pins as output
    PORTB = 0x00;   // All LEDs OFF initially

    while(1) {
        // --- Case 1: Terminal 1 Red ON, Terminal 2 Yellow + Green ON ---
        PORTBbits.RB0 = 1;  // T1 Red ON
        PORTBbits.RB1 = 0;  // T1 Yellow OFF
        PORTBbits.RB2 = 0;  // T1 Green OFF

        PORTBbits.RB3 = 0;  // T2 Red OFF
        PORTBbits.RB4 = 1; __delay_ms(1000); // T2 Yellow ON
        PORTBbits.RB5 = 0;  // T2 Green ON
        __delay_ms(1000);   // 1 second visible blink

        // Reset
        PORTB = 0x00;

        // --- Case 2: Terminal 2 Red ON, Terminal 1 Yellow + Green ON ---
        PORTBbits.RB3 = 0;  // T2 Red ON
        PORTBbits.RB4 = 0;  // T2 Yellow OFF
        PORTBbits.RB5 = 1;  // T2 Green OFF

        PORTBbits.RB0 = 0;  // T1 Red OFF
        PORTBbits.RB1 = 1;__delay_ms(1000);  // T1 Yellow ON
        PORTBbits.RB2 = 0;  // T1 Green ON
        __delay_ms(5000);   // 1 second visible blink

        // Reset
        PORTB = 0x00;
        PORTBbits.RB3 = 1;  // T2 Red ON
        PORTBbits.RB4 = 0;  // T2 Yellow OFF
        PORTBbits.RB5 = 0;  // T2 Green OFF

        PORTBbits.RB0 = 0;  // T1 Red OFF
        PORTBbits.RB1 = 1;__delay_ms(2000);  // T1 Yellow ON
        PORTBbits.RB2 = 1;  // T1 Green ON
        __delay_ms(5000); 
    }
}