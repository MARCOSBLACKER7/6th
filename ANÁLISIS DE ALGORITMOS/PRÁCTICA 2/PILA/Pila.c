#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

INFO pop(pila * p)
{
	pila temp = NULL; 
	INFO copia;
	copia = (*p)->dato; 
	temp = *p; 
	*p = (*p)->siguiente; 
	free(temp); 
	return copia;
};

mensaje push(pila * p, INFO dato)
{
	pila temp = NULL;
	temp = (pila)malloc(sizeof(NODO)); 
	if(temp == NULL)
	{
		return NO_MEMORY; 
	}
	temp->dato = dato; 
	temp->siguiente = *p; 
	*p = temp; 
	return OK;  
};

void ini_pila(pila * p)
{
	*p = NULL;
};

void reiniciar_pila(pila * p)
{
	while(!empty(*p))
		pop(p);	
};

booleano empty(pila p){
	if(p==NULL)
	{
		return TRUE; 
	}
	return FALSE; 
};

INFO top(pila p)
{
	INFO copia;
	copia = p->dato; 
	return copia;
};

void generar_numeros (pila *p, int n)
{
	INFO N;
	//N.numero = 11;
	//push(p, N);
	int i;
	for (i = 0; i < n; i++)
	{
		N.numero = rand () % 1000;
		push(p, N);
	}
	
}

booleano busqueda(pila p, int n)
{
	while(!empty(p))
	{
		printf("%d  ", top(p).numero);
		if(pop(&p).numero == n)
			return TRUE;
	}
	return FALSE;
}
