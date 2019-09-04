#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Práctica 4. Ordenamientos Recursivos (Quick Sort)
Análisis de Algoritmos
Grupo 3CM2
Creadores: De los Santos Díaz Luis ALejandro & Vazquez Moreno Marcos Oswaldo
*/

void QuickSort(long int *A, long int primero, long int ultimo);
void uswtime(double *usertime, double *systime, double *walltime);

int main ()
{
	clock_t c1, c2, c3, c4;
	c1 = clock();
	long int *A, n = 0, i = 0;
	FILE *file, *QS;
	printf("N: ");
	scanf("%d", &n);
	fflush(stdin);
	A = (long int*)malloc(n * sizeof(long int));
	file = fopen("numeros10millones.txt", "r");
	QS = fopen("QuickSort.txt", "w");
	for(i = 0; i < n; i++) fscanf(file, "%ld\n", &A[i]);
	c3 = clock();
	QuickSort(A, 0, n - 1);
	c4 = clock();
	for (i = 0; i < n; i++) fprintf(QS, "%d.- %ld\n", i + 1, A[i]);
	c2 = clock();
	printf("Tiempo total: %f\n", (double)(c2 - c1)/CLOCKS_PER_SEC);
	printf("Tiempo de procesamiento: %f", (double)(c4 - c3)/CLOCKS_PER_SEC);
	return 0;
}

void QuickSort(long int *A, long int primero, long int ultimo)
{
	long int pivote, temp, i, j;
	if(ultimo - primero >= 1)
	{
		pivote = primero;
		i = primero;
		j = ultimo;
		while(i < j)
		{
			while(A[i] <= A[pivote] && i <= ultimo) i++;
			while(A[j] > A[pivote] && j >= primero) j--;
			if(i < j)
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			};		
		};
		temp = A[j];
		A[j] = A[pivote];
		A[pivote] = temp;
		QuickSort(A, primero, j - 1);
		QuickSort(A, j + 1, ultimo);
	}
	else return;
};
