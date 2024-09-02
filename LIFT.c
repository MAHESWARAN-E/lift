/*
 * File:   LIFT.c
 * Author: USER
 *
 * Created on August 1, 2024, 2:56 PM
 */

// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>
void main()
{
    int f=0,s=0;
PORTA=PORTB=PORTC=0;
TRISA=0X0F;
TRISB=0X0F;
TRISC=ANSEL=ANSELH=0;
while(1)
{
    if(RA0=1)
    {
        f=0;
        while(RA0==1);
    }
    if(RA1==1)
    {
        f=1;
         while(RA1==1);
    }
    if(RA2==1)
    {
        f=2;
         while(RA2==1);
    }
    if(RA3==1)
    {
        f=3;
         while(RA3==1);
    }
    
    if(RB0==1)
    {
        s=0;
         while(RB0==1);
    }
    if(RB1==1)
    {
        s=1;
         while(RB1==1);
    }
    if(RB2==1)
    {
        s=2;
         while(RB2==1);
    }
    if(RB3==1)
    {
        s=3;
         while(RB3==1);
    }
    if(f==s)
    {
        RC0=RC1=0;
    }
    if(f>s)
    {
        RC0=1;
        RC1=0;
    }
     if(f<s)
    {
         RC1=1;
         RC0=1;
    }
    
   
    }
}
