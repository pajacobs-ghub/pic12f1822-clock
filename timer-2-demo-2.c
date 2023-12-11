// timer-2-demo-2.c
// PJ 2023-12-09 Start with MCU on Gooligum board and powered from PICkit3. 
//    2023-12-10 Power MCU from batteries attached to the strip board.

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

void tmr2_init(void)
{
    // Timer2 receives FOSC/4 ticks per second.
    T2CONbits.T2CKPS = 0b11; // 1:64 prescale
    // PR2 = 31; // 250ms period
    PR2 = 127; // 1 second period
    PIR1bits.TMR2IF = 0;
    T2CONbits.TMR2ON = 1;
}

static inline void tmr2_wait(void)
{
    while (!PIR1bits.TMR2IF) { /* wait */ }
    PIR1bits.TMR2IF = 0;
}

static inline void pulse_pin(void)
{
    // Emit pulse on RA2
    LATAbits.LATA2 = 1;
    TRISAbits.TRISA2 = 0; // drive pin as output high.
    __delay_ms(5);
    TRISAbits.TRISA2 = 1; // turn off output
    LATAbits.LATA2 = 0;
    TRISAbits.TRISA2 = 0; // drive pin as output low
    __delay_ms(5);
    TRISAbits.TRISA2 = 1; // turn off output
}

void main(void) {
    tmr2_init();
    while (1) {
        tmr2_wait();
        pulse_pin();
    }
    return;
}
