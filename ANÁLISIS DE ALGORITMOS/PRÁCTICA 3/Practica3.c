#include <stdio.h>
#include <stdlib.h>
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

void BurbujaSimple(int *A, int n)
{
	int i = 0, j = 0, temp = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if(A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}	
		}	
	}
	//for (i = 0; i < n; i++) printf("%d ", A[i]);
}

void BurbujaMejorada(int *A, int n)
{
	int i = 0, j = 0, temp = 0;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if(A[i] < A[j])
			{
				temp = A[j];
				A[j] = A[i];
				A[i] = temp;
			}	
		}	
	}
	//for (i = 0; i < n; i++) printf("%d ", A[i]);
}

void Insercion(int *A, int n)
{
	int i = 0, j = 0, temp = 0;
	for(i = 1; i < n; i++)
	{
		temp = A[i];
		j = i - 1;
		while((A[j] > temp) && (j >= 0))
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
	}
	//for (i = 0; i < n; i++) printf("%d ", A[i]);
}

void Seleccion(int *A, int n)
{
	int i = 0, k = 0, p = 0, temp = 0;
	for(k = 0; k < n - 1; k++)
	{
		p = k;
		for(i = k + 1; i < n; i++)
		{
			if(A[i] < A[p])
			{
				p = i;
			}
		}
		if(p != k)
		{
			temp = A[p];
			A[p] = k;
			A[k] = temp;
			
		}
	}
	//for (i = 0; i < n; i++) printf("%d ", A[i]);
}

void Shell(int *A, int n)
{
	int i = 0, j = 0, k = 0, v = 0;
	k = n/2;
	while( k >= 1)
	{
		for(i = k; i >= n; i++)
		{
			v = A[i];
			j = i - k;
			while(j >= 0 && A[j] > v)
			{
				A[j + k] = A[j];
				j -= k;
			}
			A[j + k] = v;
		}
		k /= 2;
	}
//	for (i = 0; i < n; i++) printf("%d ", A[i]);
}
