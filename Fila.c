//Esta eh uma fila circular de inteiros positivos, com no maximo 100 numeros
#include "Booleano.h"
#include<stdio.h>
#define Max 100
#define ghost 0
#define sinal -1

typedef struct{
	
	int inicio;
	int fim;
	int tam;
	int vetor[Max];
	
} cFila;

typedef cFila* Fila;

//interface
Fila newFila();
bool FilaVazia(Fila Q);
bool FilaCheia(Fila Q);
int acessarFila(Fila Q);
void pushFila(Fila Q, int y);
void popFila(Fila Q);
Fila esvaziaFila(Fila Q);
void mostrarFila(Fila Q);


int main(){
	
	Fila A;
	int i;
	
	A = newFila();
	
	for(i = 1; i < 20; i++){
		pushFila(A, i);
	}
	
	printf("=======mostrarFila========\n");
	mostrarFila(A);
	
	popFila(A);
	
	printf("=======popFila======\n");
	mostrarFila(A);
	
	int n = acessarFila(A);
	printf("n = %d\n", n);
	
	pushFila(A, 20);
	mostrarFila(A);
	
	bool cheia = FilaCheia(A);
	if(cheia){
		printf("esta cheia\n");
	}
	else{
		printf("opa\n");
	}
	
	A = esvaziaFila(A);
	mostrarFila(A);
	
	
}

Fila newFila(){
	Fila Q;
	
	Q = malloc(sizeof(cFila));
	Q->inicio = sinal;
	Q->fim = sinal;
	Q->tam = 0;
	
	return Q;
}

bool FilaVazia(Fila Q){
	bool vazio = FALSE;
	
	if(Q->inicio == sinal){
		vazio = TRUE;
	}
	
	return vazio;
}

bool FilaCheia(Fila Q){
	bool vazio = FALSE;
	
	if(Q->tam == Max){
		vazio = TRUE;
	}
	
	return vazio;
}

int acessarFila(Fila Q){
	int y = ghost;
	
	if(Q->inicio != sinal){
		y = Q->vetor[Q->inicio];
	}
	
	return y;
}

void pushFila(Fila Q, int y){
	/*int pos;
	
	if(Q->tam != Max){
		pos = (Q->fim+1) % Max;
		Q->vetor[pos] = y;
		
		if(Q->inicio == sinal){
			Q->inicio++;
		}
		
		Q->fim++;
		Q->tam++;
	}
	*/
	
	int pos = (Q->fim+1) % Max;
	if(pos != Q->inicio){
		Q->vetor[pos] = y;
		printf("pos: %d\n", pos);
		if(Q->inicio == sinal){
			Q->inicio = pos;
		}
		
		Q->fim = pos;
		Q->tam++;
	}
}

void popFila(Fila Q){
	if(Q->inicio != sinal){
		if(Q->fim == Q->inicio){
			Q->fim = sinal;
			Q->inicio = sinal;
			Q->tam = 0;
		}
		else{
			Q->inicio++;
			Q->tam--;
		}
	}
}

Fila esvaziaFila(Fila Q){
	
	Q->inicio = sinal;
	Q->fim = sinal;
	Q->tam = 0;
	
	return Q;
}

void mostrarFila(Fila Q){
	if(Q->inicio != sinal){
		int seg = (Q->fim+1) % Max;
		int i = Q->inicio;
		while(i != seg){
			printf(" %d\n", Q->vetor[i]);
			i = (i+1)%Max;
		}
	}
	else{
		printf("\nA fila esta vazia\n");
	}
}
