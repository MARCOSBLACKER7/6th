//MAIN PILA

#include <stdio.h>
#include <stdlib.h>
#include "Pila.c"


booleano busqueda(pila p, int n);

int main(int argc, char *argv[]) {
	unsigned int n, i;
	pila stack;
	ini_pila(&stack);
	printf("\n n: ");
	scanf("%d", &n);
	fflush(stdin);
	generar_numeros(&stack, n);
	printf("\n numero a buscar: ");
	scanf("%d", &n);
	fflush(stdin);
	if(busqueda(stack, n)) printf("\nTu numero esta en la pila\n");
	else printf("\nTu numero no esta en la pila\n");
	return 0;
}
