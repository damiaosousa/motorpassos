/*
 * File:   delay.c
 * Author: 20185076
 *
 * Created on 20 de Maio de 2021, 14:33
 */



#include <xc.h>
#include "config.h"

void delay(unsigned t) 
{
    while(t)
    {
    __delay_ms(1);
    --t;
    }
}