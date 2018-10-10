#include <stdio.h>
#include <stdlib.h>
typedef struct Arbol Arbol;
struct Arbol{
    int dato;
    struct Arbol * izq;
    struct Arbol * derecha;
};

Arbol * NuevoNodo(int dato);
void insertarArbolrecursivo(Arbol ** r, int dato);
void preOrden(Arbol * r);
int main(int argc, char **argv){
    int datos, nodo, i;
    Arbol * r=NULL;
    scanf("%d", &datos);
    int arrayaux[datos];
    for (i=1; i<=datos; i++){
        scanf("%d", &nodo);
        arrayaux[i]=nodo;
    }
    for (i=datos; i>0; i--){
        insertarArbolrecursivo(&r, arrayaux[i]);
    }
    preOrden(r);
}
Arbol * NuevoNodo (int dato){
    Arbol * nuevo = (Arbol*)malloc(sizeof(Arbol));
    nuevo->dato=dato;
    nuevo->derecha=NULL;
    nuevo->izq=NULL;
    return nuevo;
}
void insertarArbolrecursivo(Arbol ** r, int dato){
    if(*r==NULL){
        Arbol * nuevo = NuevoNodo(dato);
        *r = nuevo;
    }
    else{
        Arbol * aux = *r;
        if(dato>(aux->dato)){
            insertarArbolrecursivo(&aux->derecha, dato);
        }
        else {
            insertarArbolrecursivo(&aux->izq, dato);
        }
    }
}
void preOrden(Arbol * r){
    if(r!=NULL){
        printf("%d ", r->dato);
        preOrden(r->izq);
        preOrden(r->derecha);
    }
}
