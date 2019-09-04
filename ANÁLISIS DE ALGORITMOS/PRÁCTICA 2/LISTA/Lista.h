#define TRUE 1
#define FALSE 0

typedef struct nodo {
    int in;
    struct nodo *siguiente;
}nodo;

typedef struct lista{
    struct nodo *inicio;
    struct nodo *fin;
    int tamano;
}lista;

typedef unsigned char boolean;
//typedef enum b{FALSE, TRUE} booleano;

void Initialize(lista *l);
void InsertarInicio(lista *l,int x);
void InsertarFin(lista *l, int x);
void Insertar(lista *l, int x, int pos);
int EliminarInicio(lista *l);
int Eliminar(lista *l, int pos);
int Ver(lista *l, int pos);
void Destroy (lista *l);
int Size(lista *l);
