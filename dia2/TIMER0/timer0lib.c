/*
 * File:   timer0lib.c
 * Author: root
 *
 * Created on September 8, 2018, 2:06 PM
 */


#include <xc.h>
#include "timer0lib.h"

void configTimer0(unsigned char prescalerValue){
    
    //Option_Reg register configuration
    T0CS=0;     //Clock Source = Internal instruction cycle
    PSA = 0;    //Prescaler assigned to the timer0 Module
    OPTION_REG=OPTION_REG&0b11111000; //Zerando configuracoes de prescaler
    OPTION_REG=(OPTION_REG|prescalerValue);
    
    //IntCON register configuration
    T0IE=1;
    TMR0IF=0;
}
void setTimer0Value(unsigned char value){
    TMR0=value;
    
}
unsigned char getTimer0Value(void){
    return (TMR0);
}
void resetTimer0(void){
    TMR0=0x00;
}