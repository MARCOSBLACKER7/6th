#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"


void Initialize(lista *l){
    l->inicio=NULL;
    l->fin=NULL;
    l->tamano=0;
    return;
}

void InsertarInicio (lista *l, int x){
    nodo *nuevo;
    nuevo = malloc(sizeof(nodo));
    if(nuevo==NULL){
		printf("\nERROR(&l,x): Desbordamiento de la lista, no hay más memoria disponible");
		exit(1);
	}
    nuevo->in=x;
    if(l->tamano==0){
        nuevo->siguiente=NULL;
        l->inicio=nuevo;
        l->fin=nuevo;
        
    }
    else{
        nuevo->siguiente=l->inicio;
        l->inicio=nuevo;
    }
    l->tamano++;
    return;
}

void InsertarFin (lista *l, int x){
    nodo *nuevo;
    nuevo = malloc(sizeof(nodo));
    if(nuevo==NULL){
		printf("\nERROR(&l,x): Desbordamiento de la lista, no hay más memoria disponible");
		exit(1);
	}
    nuevo->in=x;
    nuevo->siguiente=NULL;
    if(l->tamano==0){
        l->inicio=nuevo;
        l->fin=nuevo;
    }
    else{
        l->fin->siguiente=nuevo;
        l->fin=nuevo;
    }
    l->tamano++;
    return;
}

void Insertar(lista *l, int x, int pos){
	int i = 0;
    if (l->tamano < 2){
        printf("\nERROR: Tiene que haber más de 2 elementos en la lista");
        exit(1);
    }
    if (pos < 1 || pos >= l->tamano){
        printf("\nERROR: La posicion no puede ser el inicio o el fin");
        exit(1);
    }
    
    nodo *actual;
    nodo *nuevo;

    nuevo = malloc(sizeof(nodo));
    actual = l->inicio;
    for (i = 1; i < pos; ++i)
        actual = actual->siguiente;
    nuevo->in=x;
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
    l->tamano++;
    return;   
}

int EliminarInicio(lista *l){
    if(l->tamano==0){
        printf("\nERROR: no hay elementos en la lista");
        exit(1);
    }
    nodo *aux;
    int r;
    aux=l->inicio;
    r=l->inicio->in;
    l->inicio=l->inicio->siguiente;

    if (l->tamano == 1)
        l->fin = NULL;
    free(aux);
    l->tamano--;
    return r;
}

int Eliminar (lista *l, int pos){
	int i = 0;
    if (l->tamano <= 1 || pos < 1 || pos >= l->tamano){
        printf("\nERROR: Posicion no valida");
        exit(1);
    }
    int r;
    nodo *aux;
    nodo *actual;

    actual=l->inicio;
    for (i = 1; i < pos; ++i)
        actual = actual->siguiente;
    
    aux=actual->siguiente;
    r=aux->in;
    actual->siguiente=actual->siguiente->siguiente;
    
    if(actual->siguiente == NULL)
        l->fin = actual;
    
    free(aux);
    l->tamano--;
    return r;
}

int Ver (lista *l, int pos){
    int r, i = 0;
    nodo *actual;
    if(pos>=l->tamano){
        printf("\nERROR: posicion no valida");
        exit(1);
    }
    actual=l->inicio;
    for (i = 1; i < pos; ++i)
        actual = actual->siguiente;
    if(pos==0)
        r=actual->in;
    else
        r=actual->siguiente->in;

    return r;
}

void Destroy (lista *l){
    while (l->tamano > 0){
        EliminarInicio (l);
    }
}

int Size(lista *l){
    return l->tamano;
}

int empty(lista *l)
{
	return l->tamano == 0;
}

int busqueda(lista *l, int n)
{
	int tam = Size(l);
	int pos = 0;
	while(!empty(l))
	{
		printf("%d  ", Ver(l, pos));
		if(l->inicio->in == n)
			return TRUE;
		EliminarInicio(l);
	}
	return FALSE;
}

void generar_numeros (lista *l, int n)
{
	int i, num;
	for (i = 0; i < n; i++)
	{
		num = rand () % 1000;
		InsertarInicio(l, num);
	}
	
}
