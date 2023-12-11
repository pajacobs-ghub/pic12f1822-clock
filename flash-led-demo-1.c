// flash-led-demo-1.c
// PJ 2023-12-07

// PIC12F1822 Configuration Bit Settings (generated in MPLAB-X memory view)
// CONFIG1
#pragma config FOSC = LP
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = ON
#pragma config CLKOUTEN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = ON

// CONFIG2
#pragma config WRT = OFF
#pragma config PLLEN = OFF
#pragma config STVREN = ON
#pragma config BORV = LO
#pragma config DEBUG = OFF
#pragma config LVP = ON


#define _XTAL_FREQ 32768
#include <xc.h>

void main(void) {
    TRISAbits.TRISA2 = 0; // RA2 as output
    LATAbits.LATA2 = 1;   // Light up LED D6 on curiosity board.
    while (1) {
        __delay_ms(1000);
        LATAbits.LATA2 ^= 1; // toggle pin
    }
    return;
}
