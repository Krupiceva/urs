#include <stdio.h>
#include <reg51.h>
main(){
	volatile unsigned char xdata *mem;
	unsigned char vtest;
	bit bdata test = 1;
	TMOD=0x20;		/* Timer1:Gate|C/T|M1|M0| Timer0:Gate|C/T|M1|M0| */
								/* Brojilo T1 radi na nacin rada 2. */
	
	TH1=0xF4;			/* Broj za ponovno punjenje brojila T1 => 2400 bitova/s. */
	
	TL1=0xF4;			/* Pocetni sadr�aj brojila T1 => 2400 bitova/s. */
	
	TR1=1;				/* TF1|TR1|TF0|TR0|IE1|IT1|IE0|IT0 */
								/* Bit u TCON registru koji pokrece rad brojila. */
	
	SCON=0x52;		/* SM0|SM1|SM2|REN|TB8|RB8|TI|RI */
								/* Serijsko sucelje radi na nacin rada 2. */
	
	printf("Zadatak 3 uspjesno napravljen.\n\n");
	
	/*4. zad */  
	for(mem=0x0000; mem<=0x7FFF; mem++){
		*mem = 0xAA;
		vtest = *mem;
		if(vtest != 0xAA){
			test = 0;
			break;
		}
	}
	if(test == 1){
		printf("Memorija je ispravna.\n\n");
	}
	else{
		printf("Memorija nije ispravna.\n\n");
	}
	while(1){}
}