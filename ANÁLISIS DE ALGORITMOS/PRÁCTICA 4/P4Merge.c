#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Práctica 4. Ordenamientos Recursivos (Quick Sort)
Análisis de Algoritmos
Grupo 3CM2
Creadores: De los Santos Díaz Luis ALejandro & Vazquez Moreno Marcos Oswaldo
*/

void mergesort(long int *A, long int i, long int f);
void merge(long int *A, long int i, long int m, long int f);

int main(int argc, char *argv[]) 
{
	clock_t c1, c2, c3, c4;
	c1 = clock();
	long int *A, n, i;
	FILE *file, *MS;
	printf("Ingrese n: ");
	scanf("%d", &n);
	fflush(stdin);
	A = (long int*)malloc(n*sizeof(long int));
	file = fopen("numeros10millones.txt", "r");
	MS = fopen("Merge Sort.txt", "w");
	for(i = 0; i < n; i++) fscanf(file, "%ld\n", &A[i]);
	c3 = clock();
	mergesort(A, 0, n - 1);
	c4 = clock();
	for(i = 0; i < n; i++) fprintf(MS, "%d.- %d\n", i + 1, A[i]);
	fclose(file);
	fclose(MS);
	c2 = clock();
	printf("Tiempo total: %f\n", (double)(c2 - c1)/CLOCKS_PER_SEC);
	printf("Tiempo de procesamiento: %f", (double)(c4 - c3)/CLOCKS_PER_SEC);
	
	return 0;
}

void mergesort(long int *A, long int i, long int f)
{
	if( i < f)
	{
		long int m = (i + f)/2;
		mergesort(A, i, m);
		mergesort(A, m + 1, f);
		merge(A, i, m, f);
	}
}

void merge(long int *A, long int i, long int m, long int f)
{
	long int *aux = (long int*)malloc((m - i + 1)*sizeof(long int));
	long int j = 0, k = 0;
	for (j = i; j <= m; j++) aux[j - i] = A[j];
	long int c1 = 0, c2 = m + 1;
	for(j = i; j <= f; j++)
	{
		if(aux[c1] < A[c2])
		{
			A[j] = aux[c1++];
			if(c1 == m - i + 1)
				for(k = c2; k <= f; k++)
					A[j++] = A[k];
		}
		else
		{
			A[j] = A[c2++];
			if(c2 == f + 1)
				for(k = c1; k <= m - i; k++)
					A[j++] = aux[k];
		}
	}
}
