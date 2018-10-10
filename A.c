#include <stdio.h>
#include <stdlib.h>
typedef struct Arbol Arbol;
struct Arbol{
    int dato;
    struct Arbol * izq;
    struct Arbol * derecha;
};

Arbol * NuevoNodo(int dato);
void insertarArbolrecursivo(Arbol ** r, int dato, int niveles);
int main(int argc, char **argv){
    int datos, nodo, i, nivel=0;
    Arbol * r=NULL;
    scanf("%d", &datos);
    for (i=1; i<=datos; i++){
        scanf("%d", &nodo);
        insertarArbolrecursivo(&r, nodo, nivel);
    }
}
Arbol * NuevoNodo (int dato){
    Arbol * nuevo = (Arbol*)malloc(sizeof(Arbol));
    nuevo->dato=dato;
    nuevo->derecha=NULL;
    nuevo->izq=NULL;
    return nuevo;
}
void insertarArbolrecursivo(Arbol ** r, int dato, int niveles){
    if(*r==NULL){
        printf("%d\n", niveles);
        Arbol * nuevo = NuevoNodo(dato);
        *r = nuevo;
    }
    else{
        Arbol * aux = *r;
        if(dato>(aux->dato)){
            niveles++;
            insertarArbolrecursivo(&aux->derecha, dato, niveles);
        }
        else {
            niveles++;
            insertarArbolrecursivo(&aux->izq, dato, niveles);
        }
    }
}
