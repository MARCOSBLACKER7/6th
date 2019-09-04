#include <stdio.h>
#include <stdlib.h>

int funcion();

main () {

funcion();

	
	
}


int funcion(){
	char polinomio=0, z, n;
	int A[100], i;
	printf("ingresa el valor de n\n");
	scanf("%d", &n);
	printf("ingresa el valor de z\n");
	scanf("%d", &z);
	
	for (i=0; i<=n; i++)
	{
		polinomio = polinomio*z + A[n-i];
		
	}
	printf("%d", polinomio);
	return polinomio;
}
