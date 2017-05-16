#include <stdio.h>
#include <reg51.h>
main(){
	TMOD=0x20;		/* Timer1:Gate|C/T|M1|M0| Timer0:Gate|C/T|M1|M0| */
								/* Brojilo T1 radi na nacin rada 2. */
	
	TH1=0xF4;			/* Broj za ponovno punjenje brojila T1 => 2400 bitova/s. */
	
	TL1=0xF4;			/* Pocetni sadržaj brojila T1 => 2400 bitova/s. */
	
	TR1=1;				/* TF1|TR1|TF0|TR0|IE1|IT1|IE0|IT0 */
								/* Bit u TCON registru koji pokrece rad brojila. */
	
	SCON=0x52;		/* SM0|SM1|SM2|REN|TB8|RB8|TI|RI */
								/* Serijsko sucelje radi na nacin rada 2. */
	
	printf("Zadatak 3 uspjesno napravljen");
	while(1){}
}