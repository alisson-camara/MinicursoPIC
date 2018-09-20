#ifndef PWM_H
#define	PWM_H

#define _XTAL_FREQ 8000000
#define TMR2PRESCALE 16

#include <xc.h>

unsigned long frequency;

void PWM2_setup(float frequencyArg);

void set_PWM2(unsigned int duty);

int PWM_max_duty();

void PWM2_start();

void PWM2_stop();

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */