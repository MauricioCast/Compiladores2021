#include<stdio.h>
#include "sintactico.tab.h"

int main(void) {
	
	if(yyparse() == 0) {
		printf("\nAnalisis concluido sin errores\n");
	} 
	return 0;
}
