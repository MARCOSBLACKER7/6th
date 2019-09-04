struct informacion {
	int numero;
};

struct nodo {
	struct informacion info;
	struct nodo *sig;
};

struct cabecera {
	struct nodo *I, *F;
};

typedef struct informacion INFO;
typedef struct nodo NODO;
typedef struct cabecera CAB;
typedef CAB *cola;
typedef NODO * link;
typedef enum m{NO_MEMORY, OK} mensaje;
typedef enum b{false, true} booleano;


mensaje ini_cola (cola *c);//
void clear_cola (cola *c);//
void delete_cola (cola *c);//
mensaje encolar (cola c, INFO dato);//
INFO desencolar (cola c);//
booleano empty (cola c);//
