/*
 * File:   mainApp.c
 * Author: root
 *
 * Created on September 8, 2018, 2:47 PM
 */

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include "timer0lib.h"
#define _XTAL_FREQ      8000000

unsigned char cont_time=0x00;

void interrupt ISR_(){
    if(T0IF){
        T0IF=0;
        cont_time++;
        if(cont_time==61){
            RB1=~RB1;
            cont_time=0x00;
        }
        
    }
}

void main(void) {
    TRISB1=0;
    RB1=0;
    configTimer0(PRESCALER64);
    resetTimer0();
    GIE=1;
    PEIE=1;
    while(1);
    return;
}
