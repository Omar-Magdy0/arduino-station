#include "PeripheralsCustom.h"
#include <math.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

//USART funcs
#define asyncBaudtoUBRRN(b) (round((1e6/b)-1))

void USART_Start(int baud){
	UCSR0B |= ( (1 << RXEN0) | (1 << TXEN0) );
	UCSR0B &= ~( 1 << UCSZ02 );
	UCSR0C &= ~( ( 1 << UMSEL01) | ( 1 << UMSEL00) | ( 1 << UPM00) | ( 1 << UCPOL0)  );
	UCSR0C |= ( 1 << UCSZ01) | ( 1 << UCSZ00) | ( 1 << UPM01 ) | ( 1 << USBS0) ;
	UBRR0 = asyncBaudtoUBRRN(baud);
}

void USART_Send(unsigned char data){
	while (!(UCSR0A & ( 1<<UDRE0)));
	UDR0 = data;
}



// TIMERCOUNTER1 settings
volatile uint16_t globalTimeMillis;
volatile uint8_t allRemainingFract;
#define remainingFractSH ((4096 % 4000) >> 4)
#define maxFract (4000 >> 4)

ISR(TIMER1_OVF_vect){
	uint16_t mils; 
	uint8_t frcts;
	//pass global vars to local ones
	mils = globalTimeMillis;
	frcts = allRemainingFract;
	mils += 4;
	frcts += remainingFractSH;
	//logic for the remaining fract time
	if (frcts >= maxFract){
		frcts -= maxFract;
		mils += 4;
	}
	//pass again to global
	globalTimeMillis = mils;
	allRemainingFract = frcts;
}
// end for timer 1

// TIMER 1 count millis
#define START 1
#define END 0

void clk1CountMillis(uint8_t command){
	if (command == START)TIMSK1 |= ( 1 << TOIE1);
	if (command == END)TIMSK1 &= ~( 1 << TOIE1);}
