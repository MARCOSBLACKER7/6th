#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
PRACTICA 7 ANALISIS DE ALGORITMOS
BINACCI BUTTOM-UP

DE LOS SANTOS DIAZ LUIS ALEJANDRO
VAZQUEZ MORENO MARCOS OSWALDO


*/

long long fibonacci(int n){
    long long tabla [n];

    if (n<2) {
        return n;
    }else{
        tabla[0]=0;
        tabla[1]=1;
        for(int i = 2; i < n; i++)
        {
            tabla[i]=tabla[i-1]+tabla[i-2];
        }
        for(int i = 0; i < n-1; i++)
        {
            printf("%lld ",tabla[i]);
        }
         
    }
    
    return tabla[n-1];

}

long long main(long long argc, char const *argv[]){
    if (argc!=2) {
        printf("Uso: %s <numero>\n",argv[0]);
        exit(0);
    }

    long long n;
    n=atoi(argv[1]);
    
    printf("%lld\n",fibonacci(n));
    return 0;
}
