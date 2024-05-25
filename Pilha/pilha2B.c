//Esta eh uma pilha de caracteres, com no maximo 100 caracteres 

#include "Booleano.h"
#include<stdio.h>
#define Max 101
#define ghost 63
#define sinal 0

typedef struct{
	int topo; //o campo topo aponta para o ultimo item colocado na pilha
	unsigned char vetor[Max]; //o primeiro a entrar na pilha eh colocado na posicao 1
							 //o tamanho maximo da pilha eh guardado na posicao 0
} Pilha;

void criarPilha(Pilha * ); 				//cria a pilha vazia
bool PilhaVazia(Pilha *); 				//devolve TRUE se a pilha eh vazia, FALSE, caso contrario
unsigned char acessarPilha(Pilha *); 	//devolve o item que esta no topo da pilha
void pushPilha(Pilha *,unsigned char); 	//coloca um item na pilha
void popPilha(Pilha *); 			    //retira um item da pilha
void esvaziarPilha(Pilha *); 			//esvazia a pilha
void mostrarPilha(Pilha *);
int profundidadePilha(Pilha *p);
void inverterPilha(Pilha *p);
void copiarPilha(Pilha *, Pilha *);
void copiarPilha2(Pilha *p, Pilha *a);

int main(){
	int i;
	Pilha B;
	criarPilha(&B);
	
	printf("\n--------------pushPilha----------------\n");
	for(i = 65; i < 75; i++){
		pushPilha(&B, i);
	}
	mostrarPilha(&B);
	
	unsigned char ch = acessarPilha(&B);
	printf("\nItem do topo: %c\n", ch);
	
	printf("\n--------------popPilha----------------\n");
	popPilha(&B);
	mostrarPilha(&B);
	
	int tam = profundidadePilha(&B);
	printf("\nProfundidade da pilha: %d\n", tam);
	
	printf("\n--------------inverterPilha----------------\n");
	inverterPilha(&B);
	mostrarPilha(&B);
	
	printf("\n--------------copiarPilha----------------\n");
	Pilha C;
	copiarPilha(&B, &C);
	mostrarPilha(&C);
	
	printf("\n--------------evaziarPilha----------------\n");
	esvaziarPilha(&B);
	mostrarPilha(&B);
	
	return 0;
}

void criarPilha(Pilha *p){
	p->topo = sinal;
	p->vetor[0] = Max - 1;
}

bool PilhaVazia(Pilha *p){
	bool estado = FALSE;
	
	if(p->topo == sinal){
		estado = TRUE;
	}
	
	return estado;
}

unsigned char acessarPilha(Pilha *p){
	unsigned char ch;
	
	if(p->topo != sinal){
		ch = p->vetor[p->topo];
	}
	else{
		ch = ghost;
	}
	return ch;
}

void pushPilha(Pilha *p,unsigned char ch){
	if(p->topo+1 < Max){
		p->topo++;
		p->vetor[p->topo] = ch;
	}
}

void popPilha(Pilha *p){
	if(p->topo != sinal){
		p->topo--;
	}
}

void esvaziarPilha(Pilha *p){
	p->topo = sinal;
}

void mostrarPilha(Pilha *p){
	int i;
	if(p->topo != sinal){
		printf("\n");
		for(i = p->topo; i > 0; i--){
			printf("\t %c\n", p->vetor[i]);
		}
	}
	else{
		printf("\n A pilha esta vazia \n");
	}
}

int profundidadePilha(Pilha *p){
	int tam = p->topo;
	return tam;
}

void inverterPilha(Pilha *p){
	Pilha A;
	criarPilha(&A);
	
	if(!PilhaVazia(p)){
		do{
			unsigned char ch = acessarPilha(p);
			pushPilha(&A, ch);
			p->topo--;
			//popPilha(p);
			
		}while(p->topo != sinal);
	}
	*p = A;
}

void copiarPilha(Pilha *p, Pilha *a){
	if(p->topo != sinal){
		*a = *p;
	}	
}

void copiarPilha2(Pilha *p, Pilha *a){
	if(p->topo != sinal){
		do{
			pushPilha(a, p->vetor[p->topo]);
			popPilha(p);
		}
		while(p->topo != sinal);
	}
}
