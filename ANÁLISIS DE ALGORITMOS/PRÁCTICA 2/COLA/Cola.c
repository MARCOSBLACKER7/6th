#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Cola.h"

//COLA IMPLEMENTACION

mensaje ini_cola (cola *c)
{
	cola temp = NULL;
	temp = (cola) malloc (sizeof (NODO));
	if (temp == NULL)
	{
		return NO_MEMORY;
	}
	temp->I = temp->F = NULL;
	*c = temp;
	return OK;
};

void clear_cola (cola *c)
{
	while (!empty(*c))
	{
		desencolar (*c);
	}
};

INFO desencolar (cola c)
{
	INFO copia;
	link aux = NULL;
	copia = c->I->info;
	if (c->I == c->F && c->I != NULL)
	{
		free (c->I);
		c->I = c->F = NULL;
		return copia;
	}
	else if (c->I != c->F)
	{
		aux = c->I;
		c->I = aux->sig;
		free (aux);
		return copia;
	}
}

booleano empty (cola c)
{
	if (c->I == NULL && c->F == NULL)
		return TRUE;
	return FALSE;
}

mensaje encolar(cola c, INFO dato){
	link temp = NULL;
	temp = (link)malloc(sizeof(NODO)); //Solicitamos el nuevo nodo
	if(temp==NULL) //Si el recurso fue denegado	
		return NO_MEMORY; //Mensaje de acceso denegado
	temp->info = dato; //Asignamos la información a guardar
	if(empty(c)){ //Cola vacía
		temp->sig = NULL;
		c->I = c->F = temp; 
	}
	else
	{ 
		c->F->sig = temp;
		temp->sig = NULL;
		c->F= temp;
	} 	
	return OK;	
}

void delete_cola (cola *c)
{
	while (!empty(*c))
	{
		desencolar (*c);
	}
	free (c);
	*c = NULL;
}
 
void generar_numeros (cola c, int n)
{
	INFO N;
	int i;
	for (i = 0; i < n; i++)
	{
		N.numero = rand () % 1000;
		encolar (c, N);
	}
}

booleano busqueda(cola c, int n)
{
	while(!empty(c))
	{
		printf("%d  ", c->I->info.numero);
		if(desencolar(c).numero == n)
			return TRUE;
	}
	return FALSE;
}
