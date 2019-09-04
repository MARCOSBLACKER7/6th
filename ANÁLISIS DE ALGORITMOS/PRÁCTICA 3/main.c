#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Practica3.c"
	/* 
	PRACTICA 3  
	ANALISIS DE ALGORITMOS DE ORDENAMIENTO
.	ALGORITMOS 
	PROFRA LUZ MARIA 
	LUIS ALEJANDRO DE LOS SANTOS
	MARCOS OSWALDO VAZQUEZ MORENO  
	ESCUELA SUPERIOR DE COMPUTO 
	2016601777 	 
	  */ 

int main(int argc, char *argv[]) {
	long int *A, n, i, *aux;
	FILE *archivo, *burbujaS, *burbujaM, *insercion, *seleccion, *shell;
	clock_t ini, fin, BS, BM, I, S, SH;
	archivo = fopen("numeros10millones.txt", "r");
	burbujaS = fopen("Burbuja Simple.txt", "w");
	burbujaM = fopen("Burbuja Mejorada.txt", "w");
	insercion = fopen("Insercion.txt", "w");
	seleccion = fopen("Seleccion.txt", "w");
	shell = fopen("Shell.txt", "w");
	scanf("%ld", &n);
	fflush(stdin);
	A = (long int*)malloc(n * sizeof(long int));
	aux = (long int*)malloc(n * sizeof(long int));
	for (i = 0; i < n; i++)
	{
		fscanf(archivo, "%ld\n", &A[i]);
	} 
	printf("\t\n\n\n==========>Burbuja Simple<=============\n\n");
	ini = clock();
	BurbujaSimple(A, n);
	fin = clock();
	BS = fin - ini;
	for (i = 0; i < n; i++) fprintf(burbujaS ,"%d\n", A[i]);
	printf("\t\n\n\n==========>Burbuja Mejorada<=============\n\n");
	ini = clock();
	BurbujaMejorada(A, n);
	fin = clock();
	BM = fin - ini;
	for (i = 0; i < n; i++) fprintf(burbujaM ,"%d\n", A[i]);
	printf("\t\n\n\n==========>Insercion<=============\n\n");
	ini = clock();
	Insercion(A, n);
	fin = clock();
	I = fin - ini;
	for (i = 0; i < n; i++) fprintf(insercion ,"%d\n", A[i]);
	printf("\t\n\n\n==========>Seleccion<=============\n\n");
	ini = clock();
	Seleccion(A, n);
	fin = clock();
	S = fin - ini;
	for (i = 0; i < n; i++) fprintf(seleccion ,"%d\n", A[i]);
	printf("\t\n\n\n==========>Shell<=============\n\n");
	ini = clock();
	Shell(A, n);
	fin = clock();
	SH = fin - ini;
	for (i = 0; i < n; i++) fprintf(shell ,"%d\n", A[i]);
	printf("\n\nTiempos de ejecucion\n");
	printf("Burbuja Simple: %f\n", (double)BS/CLOCKS_PER_SEC);
	printf("Burbuja Mejorada: %f\n", (double)BM/CLOCKS_PER_SEC);
	printf("Insercion: %f\n", (double)I/CLOCKS_PER_SEC);
	printf("Seleccion: %f\n", (double)S/CLOCKS_PER_SEC);
	printf("Shell: %f\n", (double)SH/CLOCKS_PER_SEC);
	fclose(archivo);
	fclose(burbujaS);
	fclose(burbujaM);
	fclose(insercion);
	fclose(seleccion);
	fclose(shell);
	return 0;
}
