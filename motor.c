/*
 * File:   motor.c
 * Author: 20185076
 *
 * Created on 28 de Maio de 2021, 13:23
 */



#include "config.h"
#include "delay.h"
#include <xc.h>


char vetor[4] = {0x08, 0x04, 0x02, 0x01};

//void sentido(void)

void motor_init(void)
{
    ANSELH = 0;
    TRISC = 0x00;
    PORTC = 0x00;
}


