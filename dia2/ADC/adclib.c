/*
 * File:   adclib.c
 * Author: root
 *
 * Created on September 9, 2018, 11:41 PM
 */


#include <xc.h>
#include "adclib.h"

void adcConfig(unsigned char conversionRate, unsigned char portConfig){
    //Configuring Conversion Rate
    ADCON0=ADCON0|(conversionRate<<1);
    ADCON1=ADCON1|((conversionRate&0b10000000)>>1); //Select only the msbit of conversionRate and puts it on the bit 6 of register
    //....
    //Result Format and Port Configuration 
    ADCON1=ADCON1|(portConfig);
    ADON=1; //Turn on ADC Module
    
}
unsigned int adcRead(unsigned char channel,unsigned char resultFormat){
    unsigned int returnValue=0;
        if(channel>7) // Tratamento para canais invalidos
    {
        returnValue= 0;
    }
    ADCON0=ADCON0&0b11000101; // Limpando bits de selecao do canal
    ADCON0=ADCON0|(channel<<3); // Setando bits de selecao do canal a partir da variavel
    ADCON1=ADCON1|(resultFormat); //Right or Left Justified
   
    //_delay(40);
    GO_nDONE=1; // Initializes ADC conversion
    while(GO_nDONE) // Wait for A/D conversion to complete
    {};
    if(resultFormat==RIGHT_JUST)
        returnValue= (ADRESH<<8)|ADRESL;
    else if(resultFormat==LEFT_JUST)
        returnValue=(ADRESH<<2)|(ADRESL>>6);
    return returnValue;
        
}
