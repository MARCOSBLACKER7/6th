/*
Marcos Oswaldo Vazquez Moreno 2016601777
Practica 1 analisis de algoritmos 
analisis de complejidad espacial y temporal
Profesora Luz Maria 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int funcion();

main () {

funcion();
	
	
}

int funcion(){
	
float clock_inicio= 0,  clock_fin= 0,   clock_total=  0;
	clock_inicio= clock();
	
int aux=1, anterior = 1;
long n, actual= 1;

printf("Ingresa n\n");
scanf("%d", &n);
while (n>2)
{
	aux = anterior + actual;
	anterior = actual;
	actual = aux;
	n = n-1;
}clock_fin= clock(); 
	clock_total= clock_fin - clock_inicio;
	
	printf("Tiempo de ejecucion %f\n", (double)clock_total/CLOCKS_PER_SEC);
	return actual;
	

}
