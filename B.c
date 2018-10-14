#include <stdio.h>
#include <stdlib.h>

typedef struct arbol arbol;
typedef struct cola cola;

struct arbol{
	int dato;
	arbol *izq;
	arbol *der;
};

arbol *crearnodo(int dato){
	arbol *nuevo=NULL;
	nuevo=(arbol *)malloc(sizeof(arbol));
	nuevo->dato=dato;
	nuevo->der=NULL;
	nuevo->izq=NULL;
	return nuevo;
}


void insertarecursivo(arbol **r,int dato){
	if (*r==NULL){
		arbol* nuevo=crearnodo(dato);
		*r=nuevo;
	}
	else{
		arbol *aux= *r;
		if(dato>aux->dato){
			insertarecursivo(&aux->der,dato);
		}
		else{
			insertarecursivo(&aux->izq,dato);
		}
	}
}

void preorden(arbol *r,int *a){
	if(r!=NULL){
		printf("%d",a[r->dato]);
		preorden(r->izq,a);
		preorden(r->der,a);
	}
}

int main(int argc, char *argv[]) {
	arbol *raiz=NULL;
	int n,dato;
	scanf("%d",&n);
	int arr[n];
	int a[n];
	for(int i=1;i<=n;i++){
	scanf("%d",&dato);
	arr[dato]=i;
	a[i]=dato;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&dato);
	}
	for(int i=1;i<=n;i++){
		insertarecursivo(&raiz,arr[i]);
	}
	preorden(raiz,a);
	
	return 0;
}
