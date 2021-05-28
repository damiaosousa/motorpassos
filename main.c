/*
 * File:   main.c
 * Author: 20185076
 *
 * Created on 20 de Maio de 2021, 14:33
 */

//==============================================================================
#include "config.h"
#include "delay.h"
#include "motor.h"
#include <xc.h>


void main(void) 
{
    int sentido = 1;            // 1 = antihorario 0 = horario
    int passo = 1;              // 1 = (1/2 passo)
    unsigned int t = 100;       // definir delay entre passos
    int estado = 0;
    
    while(1)
    {
        switch(estado)
        {
            case 0:
                estado = 1;
                break;

            case 1:
                motor_init();
                estado = 2;
                break;

            case 2: 
                if(sentido == 0)
                {
                    if(passo == 1)
                        estado = 6;
                    else 
                        estado = 3;
                }
                
                
                if(sentido == 1)
                {
                    if(passo == 1)
                        estado = 5;               
                    else
                        estado = 4; 
                }               
 
                break;

            case 3:
                while(1)
                {
                    PORTC = 0x08;  // sentido horario = 0
                    delay(t);
                    PORTC = 0x04;
                    delay(t);
                    PORTC = 0x02; 
                    delay(t);               
                    PORTC = 0x01;
                    delay(t);             
                }
                break;

            case 4:
                while(1)
                {
                    PORTC = 0x01;  // sentido antihorario = 1
                    delay(t);
                    PORTC = 0x02;
                    delay(t);
                    PORTC = 0x04; 
                    delay(t);               
                    PORTC = 0x08;
                    delay(t);
                }                       
                break;
                
            case 5:
                while(1)
                {
                    PORTC = 0x08;  // sentido horario = 0
                    delay(t);
                    PORTC = 0x09;
                    delay(t);
                    PORTC = 0x01; 
                    delay(t);               
                    PORTC = 0x03;
                    delay(t);
                    PORTC = 0x02;
                    delay(t);
                    PORTC = 0x06;
                    delay(t);
                    PORTC = 0x04;
                    delay(t);
                    PORTC = 0x0C;
                    delay(t);             
                } 
                break;    
                
            case 6:
                while(1)
                {
                    PORTC = 0x0C;  // sentido antihorario = 1
                    delay(t);
                    PORTC = 0x04;
                    delay(t);
                    PORTC = 0x06; 
                    delay(t);               
                    PORTC = 0x02;
                    delay(t);
                    PORTC = 0x03;
                    delay(t);
                    PORTC = 0x01;
                    delay(t);
                    PORTC = 0x09;
                    delay(t);
                    PORTC = 0x08;
                    delay(t);           
                } 
                break;                
        }
    }        
} // end main