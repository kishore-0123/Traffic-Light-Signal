#include <xc.h>

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
    TRISB = 0x00;  
    PORTB = 0x00;   

    while(1) {
        
        PORTBbits.RB0 = 1;  
        PORTBbits.RB1 = 0; 
        PORTBbits.RB2 = 0;  

        PORTBbits.RB3 = 0;  
        PORTBbits.RB4 = 1;
        __delay_ms(1000); 
        PORTBbits.RB5 = 0; 
        __delay_ms(1000);   
        PORTB = 0x00;
        
        PORTBbits.RB3 = 0; 
        PORTBbits.RB4 = 0;  
        PORTBbits.RB5 = 1;  
        
        PORTBbits.RB0 = 0;  
        PORTBbits.RB1 = 1;
        __delay_ms(1000);  
        PORTBbits.RB2 = 0;  
        __delay_ms(5000);   
        
        PORTB = 0x00;
        PORTBbits.RB3 = 1;  
        PORTBbits.RB4 = 0; 
        PORTBbits.RB5 = 0;  

        PORTBbits.RB0 = 0;  
        PORTBbits.RB1 = 1;
        __delay_ms(2000);  
        PORTBbits.RB2 = 1;  
        __delay_ms(5000); 
    }
}
