#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
PRACTICA 7 ANALISIS DE ALGORITMOS
BINACCI TOP-DOWN

DE LOS SANTOS DIAZ LUIS ALEJANDRO
VAZQUEZ MORENO MARCOS OSWALDO


*/
long long fibo(int n){
    long long t[n];
    for(int i = 0; i < n; i++)
    {
        t[i]=-1;
    }
    
    if (n<2) {
        return n;
    }

    if (t[n-1]==-1) {
        t[n-1]=fibo(n-1);
    }

    if (t[n-2]==-1) {
        t[n-2]=fibo(n-2);
    }
    
    t[n]=t[n-1]+t[n-2];
    
    return t[n];

}

long long main(long long argc, char const *argv[]){
    if (argc!=2) {
        printf("Uso: %s <numero>\n",argv[0]);
        exit(0);
    }

    int n;
    n=atoi(argv[1]);
    for(int i = 0; i < n; i++)
    {
        printf("%lld ",fibo(i));
    }
    printf("\n");
    
    return 0;
}