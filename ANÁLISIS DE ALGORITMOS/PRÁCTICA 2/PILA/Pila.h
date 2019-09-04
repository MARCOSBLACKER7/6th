struct informacion
{
	int numero;
};

struct nodo
{
	struct informacion dato;
	struct nodo * siguiente;
};

typedef struct nodo * pila; 
typedef struct informacion INFO; 
typedef struct nodo NODO; 
typedef enum B{FALSE,TRUE} booleano; 
typedef enum M{NO_MEMORY,OK} mensaje;

void ini_pila(pila * p);
void reiniciar_pila(pila * p); 
INFO pop(pila * p); //Último elemento guardado
mensaje push(pila * p, INFO dato); //Confirma el último elemento leído
booleano empty(pila p); //Vacía la pila
INFO top(pila p); //Obtiene una copia del top de la pila
