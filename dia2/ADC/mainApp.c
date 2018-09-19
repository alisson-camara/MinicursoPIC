/*
 * File:   mainApp.c
 * Author: root
 *
 * Created on 10 de Setembro de 2018, 14:21
 */


#include <xc.h>
#define _XTAL_FREQ 8000000
#include "adclib.h"



void main(void) {
   
    TRISA=0xff;
    TRISB=0x00;
    TRISC0=0;
    TRISC1=0;
    PORTC=0x00;
    PORTB=0x00;
    adcConfig(ADC_CLOCK_32,ADC_CONFIG_0);
    unsigned int valor;
    while(1){
        valor=adcRead(0,RIGHT_JUST);
        PORTB=valor&0xff;//oito primeiros bits
        RC0=valor>>8; //nono bit para rc0
        RC1=valor>>9; //décimo bit para rc1
        
    }
    return;
}
