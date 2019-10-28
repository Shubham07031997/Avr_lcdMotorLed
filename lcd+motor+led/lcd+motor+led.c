#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include<lcdavr.h>
void main()
{
   DDRB=0xff;
   lcd_init();
   DDRA=0xff;
   DDRC=0xff;
   DDRD=0x00;
   PIND=(1<<PA7)|(1<<PA6)|(1<<PA5);
   while(1)
   {  
       if((PIND & 0b11100000)==0b01100000)
           { lcd_clear();
	         lcd_command(0x80);
	         lcd_string("welcome lets");
	          lcd_command(0xc0);
	         lcd_string(" play with lcd");
	          _delay_ms(100);}
			  
			      else
				  lcd_clear();

				  if((PIND & 0b11100000)==0b10100000)
				  {  //lCD_clear();
				      lcd_command(0x80);
					  lcd_string("alternade led");
					    PORTC=0b10101010;
						_delay_ms(100);
						PORTC=0b01010101;
						_delay_ms(100);
						lcd_command(0x80);
						lcd_clear();
						lcd_string("chaser led");
						  PORTC=0b10000000;
						  _delay_ms(100);
						  PORTC=0b11000000;
						  _delay_ms(100);
						  PORTC=0b11100000;
						  _delay_ms(100);
						  PORTC=0b11110000;
						  _delay_ms(100);
						  PORTC=0b11111000;
						  _delay_ms(100);
						  PORTC=0b11111100;
						  _delay_ms(100);
						  PORTC=0b11111110;
						  _delay_ms(100);
						  PORTC=0b11111111;
						  _delay_ms(100);
						}
						else
						  lcd_clear();
						  PORTC=0x00;
						      if((PIND &0b11100000)==0b11000000)
						  {    
						      lcd_command(0x80);
							  lcd_string("forward/direction");
							  PORTA=0b10100000;
							  _delay_ms(100);
							  }
							  else
							  lcd_clear();
							  PORTA=0x00;
	   }
	   }
