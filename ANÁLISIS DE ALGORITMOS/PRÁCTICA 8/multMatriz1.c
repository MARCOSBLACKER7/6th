#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 10

/*
ANALISIS DE ALGORITMOS
VAZQUEZ MORENO MARCOS OSWALDO
DE LOS SANTOS DIAZ LUIS ALEJANDRO

PRACTICA 8 MULTIPLICACION OPTIMA DE MATRICES
17 DE ABRIL DE 2019
*/

long i, iN, iCase;
long aiMatrizSize[MAX + 1];
long aiPartition[MAX][MAX];

long matrix_mult(long iSize)
{
	long aiCost[MAX][MAX];
	long iStart, iEnd, iCut, iLength, iTemp;
	memset(aiCost, 0, sizeof(aiCost));

	for (iLength = 2; iLength <= iSize; iLength++)
	{
		for(iStart = 0; iStart + iLength - 1 < iSize; iStart++)
		{
			iEnd = iLength + iStart - 1;
			aiCost[iStart][iEnd] = LONG_MAX;
			for(iCut = iStart; iCut < iEnd; iCut++)
			{
				iTemp = aiCost[iStart][iCut] + aiCost[iCut + 1][iEnd] + aiMatrizSize[iStart]*aiMatrizSize[iCut + 1]*aiMatrizSize[iEnd + 1];
				if (iTemp < aiCost[iStart][iEnd])
				{
					aiCost[iStart][iEnd] = iTemp;
					aiPartition[iStart][iEnd] = iCut;
				}
			}
		}
	}
	return (aiCost[0][iSize - 1]);
}

void print_solution(long iStart, long iEnd)
{
	if (iStart == iEnd) printf("A%ld", iStart + 1);
	else
	{
		printf("(");
		print_solution(iStart, aiPartition[iStart][iEnd]);
		printf(" x ");
		print_solution(aiPartition[iStart][iEnd] + 1, iEnd);
		printf(")");
	}
}

int main(void)
{
	long unsigned int res = 0;
	iCase = 0;
	scanf("%ld", &iN);
	while (iN != 0)
	{
		for(i = 0; i < iN; i++) scanf("%ld %ld", &aiMatrizSize[i], &aiMatrizSize[i + 1]);
		res = matrix_mult(iN);
		printf("Case %ld: ", iCase++);
		print_solution(0, iN - 1);
		printf(" = %ld\n", res);
		scanf("%ld", &iN);
	}
	return 0;
}
