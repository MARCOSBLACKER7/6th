#include <stdio.h>
#include <stdlib.h>

int funcion();

main () {

funcion();
	
	
}


int funcion(){
	char n=0, j=0, i=0, temp= 0;
	printf("Ingresa n \n");
	scanf("%c", &n);
	
	int A[100];
	for(i=1; i<n; i++)
		for(j=0;j<n-1; j++)
		{
			temp= A[j],
			A[j]= A[j+1];
			A[j+1]= temp;
		}
	printf("%d\n",A[j+1]);	
	return A[j+1];
	
}
