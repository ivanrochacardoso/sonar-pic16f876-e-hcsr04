#include<16f876.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOBROWNOUT,NOLVP

#include "flex_lcd.c"

//----------------------------------------------------------------------

 #use rs232(baud=9600,PARITY=N, xmit=PIN_C6,rcv=PIN_C7)


#define	BOTAO1	PIN_A5	;
#define	BOTAO2	PIN_C5	;
#define	LED     PIN_C0	;
#define	LED2     PIN_C4

//****************** funcoes *******************

int16  time;    
float distance;



#define trig pin_B0    
#define echo pin_B3    


void main(){
setup_adc_ports(NO_ANALOGS);

lcd_init(); 

lcd_putc("\f iniciando.."); 
delay_ms(1000);

setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);     // inicia timer 

   delay_ms(50);      //espera oscilador estabilizar 

   while(1){ 
      delay_ms(600); 
   
         
         
         
         
         output_high(trig);                         // ping  sonar 
delay_us(20);                           
output_low(trig); 

while(!input(ECHO))                       
{} 

set_timer1(0);                           // seta timer zero 

while(input(ECHO))                       
{} 

time=get_timer1();                     


distance=(time*0.27912)/2 ;
                            
                            

 printf(lcd_putc,"\fDist.: %3.2f Cm",distance);                               
                                  
                                     
          	if(distance>99.1 && distance <101.9){  //se ~ 1 mt ativa saida C0

		output_high(PIN_C0);
           }else{
           
           output_low(PIN_C0);
           }                
                                     
		

		 
   } 
} 



//========================== fim ===========================
