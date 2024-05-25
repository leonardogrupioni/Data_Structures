/* TAD ListaP */
/*
  Arquivo: teste ListaP.c
  Autor: Leonardo Grupioni
  Date: 09/09/13 13:17
  Descrição: Implementa o tipo ListaP.
*/

#include<stdio.h>
#include "Booleano.h"
#define fantasma 36
#define Max 30
#define sinal -99

typedef struct{
    int tam;
    unsigned char vetor[Max];
}Ovo;

typedef struct Ovo* Lista;
//Interface
	
	Lista *newLista(); 	
    void mostrarLista(Lista);                  // está pronta
    Lista construirLista(int);             	// está pronta  	
 
int main(){
	int qtd,local,k;
	unsigned char letra;
	Lista L1;	L1 = newLista();  //mostrarLista(L1);
	Lista L2;  L2 = newLista();  //mostrarLista(L2);
	Lista L3;  L3 = newLista();
	printf("\n--------------ListaL1----------------\n");
	L1 = construirLista(3);	mostrarLista(L1);

	return 0;
}
 
 		
//Implementações

Lista *newLista(){
	Lista L;
	L = malloc(sizeof(Ovo));
	L->tam = 0;
	return L;
}

Lista construirLista(int n){
        Lista listaA;
        int i,t;
        if(n == 0){
        	listaA->tam = n;	
		}  
        else {
            if((n > 0) && (n <= Max)){
            	t = n;
			}  
            else{
            	t = Max;	
			}
            listaA->tam = t;
            for(i = 0; i < t; i++){
            	listaA->vetor[i] = 65+i;
			}
        }
        return listaA;
}

void mostrarLista(Lista s1){
	int k;
	if(s1->tam == 0){
		printf("\nLista Vazia\n");
	}
	else{
		for(k = 0; k < s1->tam; k++){
			printf("\t %c\n", s1->vetor[k]);
		}
	}
}
