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
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>

#include <xc.h>
#define RS RE0
#define DATA PORTD
#define EN RE1
void delay(unsigned int n){
    while(n--);
}
void enable()
{
    EN=1;
    delay(100);
    EN=0;
    delay(100);    
}
void lcd(char rs,char data)
{
    RS=rs;
    DATA=data;
    enable();
}
int f=0,s=0;
void main()
{

PORTA=PORTB=PORTC=0;
TRISA=0X0F;
TRISB=0X0F;
PORTD=TRISD=TRISE=PORTE=0X00;
TRISC=ANSEL=ANSELH=0;
lcd(0,0x38);
lcd(0,0x0E);
while(1)
{
    if(RA0==1)
    {
        f=0;
//        while(RA0==1);
    }
    if(RA1==1)
    {
        f=1;
//         while(RA1==1);
    }
    if(RA2==1)
    {
        f=2;
//         while(RA2==1);
    }
    if(RA3==1)
    {
        f=3;
//         while(RA3==1);
    }
    
    if(RB0==0)
    {
        s=0;
         //while(RB0==0);
    }
    if(RB1==0)
    {
        s=1;
//         while(RB1==0);
    }
    if(RB2==0)
    {
        s=2;
       //  while(RB2==0);
    }
    if(RB3==0)
    {
        s=3;    
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
         RC0=0;
    }
    lcd(0,0x80);
    lcd(1,48+f);
    lcd(0,0xc0);
    lcd(1,48+s);
   
    }
}
