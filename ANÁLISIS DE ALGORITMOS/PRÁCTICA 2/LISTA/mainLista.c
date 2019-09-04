#include <stdio.h>
#include <stdlib.h>
#include "Lista.c"


int main(int argc, char *argv[]) {
	unsigned int n, i;
	lista list;
	Initialize(&list);
	printf("n: ");
	scanf("%d", &n);
	fflush(stdin);
	generar_numeros(&list, n);
	printf("\n numero a buscar: ");
	scanf("%d", &n);
	fflush(stdin);
	if(busqueda(&list, n)) printf("\nTu numero esta en la lista\n");
	else printf("\nTu numero no esta en la lista\n");
	return 0;
}
