//MAIN COLA


#include <stdio.h>
#include <stdlib.h>
#include "Cola.c"


int main(int argc, char *argv[]) {
	unsigned int n, i;
	cola queue;
	ini_cola(&queue);
	printf("n: ");
	scanf("%d", &n);
	fflush(stdin);
	generar_numeros(queue, n);
	printf("\nnumero a buscar: ");
	scanf("%d", &n);
	fflush(stdin);
	if(busqueda(queue, n)) printf("\nTu numero esta en la cola\n");
	else printf("\nTu numero no esta en la cola\n");
	return 0;
}

/*
PRACTICA 2 
ALGORITMOS
PROFRA LUZ MARIA
MARCOS OSWALDO VAZQUEZ MORENO 
ESCUELA SUPERIOR DE COMPUTO
2016601777

  */
