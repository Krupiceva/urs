			CSEG AT 00h			
			mov DPTR, #0000h			;RAM pocinje na toj adresi
			mov R0, #064h				;incijalizacija brojaca R0=100
			
loop:		mov A, #0AAh					;stavi AA u acc
			movx @DPTR, A				;upisi A u ono sta je na adr DPTR tj upisi u vanjski RAM AA
			movx A, @DPTR				;upisi u A ono sta je na adr DPTR tj citaj vanjski RAM
			cjne A, #0AAh, false			;ako nije AA skoci na false
			inc DPTR						;povecaj data pointer
			djnz R0, loop					;smanjuj brojac dok nije 0 i vrti petlju loop
			
			mov A, #0F5h					;stavi 0x00F5 u acc, s F5 dobimo A na prikazniku
			
display:	mov DPTR, #8000h			;lijevi pokaznik je na toj adresi
			movx @DPTR, A				;stavi na adresu 0x8000 acc, tj na lijevi pokaznik A ili 0
			inc DPTR						;povecaj data pointer jer je na 0x8001 desni pokaznik
			movx @DPTR, A				;stavi na adresu 0x8001 acc, tj na lijevi pokaznik A ili 0
			jmp toend					
					
false:		mov A, #077h					;stavi 0x0077 u acc, s 77 dobimo 0 na prikazniku
			jmp display						;skoci na prikazivanje
			
toend:	jmp toend						;inf loop

			END