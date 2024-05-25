//Esta eh uma pilha de caracteres, com no maximo 100 caracteres

#include "Booleano.h"
#include<stdio.h>
#define Max 101
#define ghost 63
#define sinal 0

typedef struct{		
	
	int topo;	//o campo topo aponta para o ultimo item colocado na pilha
	unsigned char vetor[Max]; 	//o primeiro a entrar na pilha eh colocado na posicao 1
								//o tamanho maximo da pilha eh guardado na posicao 0
} Pilha;

//interface
Pilha criarPilha();						//cria a pilha vazia
bool PilhaVazia(Pilha);					//devolve TRUE se a pilha eh vazia, FALSE, caso contrario
unsigned char acessarPilha(Pilha); 		//devolve o item que esta no topo da pilha
Pilha pushPilha(Pilha, unsigned char); 	//coloca um item na pilha
Pilha popPilha(Pilha);  				//retira um item da pilha
Pilha esvaziarPilha(Pilha); 			//esvazia a pilha
void mostrarPilha(Pilha P);				//mastra o conteudo de uma pilha
int profundidadePilha(Pilha P);			//obtem a profundidade de uma pilha
Pilha inverterPilha(Pilha P);			//inverte o conteudo de uma pilha
Pilha copiarPilha(Pilha P);				//copia os valores da pilha em uma outra
		

int main(){
	Pilha B;
	int i;
	B = criarPilha();
	
	printf("\n--------------pushPilha----------------\n");
	for(i = 65; i < 75; i++){
		B = pushPilha(B, i);
	}
	mostrarPilha(B);
	
	unsigned char ch = acessarPilha(B);
	printf("\nItem do topo: %c\n", ch);
	
	printf("\n--------------popPilha----------------\n");
	B = popPilha(B);
	mostrarPilha(B);
	
	int tam = profundidadePilha(B);
	printf("\nProfundidade da pilha: %d\n", tam);
	
	printf("\n--------------inverterPilha----------------\n");
	B = inverterPilha(B);
	mostrarPilha(B);
	
	printf("\n--------------copiarPilha----------------\n");
	Pilha C;
	C = copiarPilha(B);
	mostrarPilha(C);
	
	printf("\n--------------evaziarPilha----------------\n");
	B = esvaziarPilha(B);
	mostrarPilha(B);
	
	return 0;
}

Pilha criarPilha(){
	Pilha P;
	P.vetor[0] = Max-1;
	P.topo = sinal;
	return P;
}

bool PilhaVazia(Pilha P){
	bool estado;
	if(P.topo == sinal){
		estado = TRUE;
	}
	else{
		estado = FALSE;
	}
	
	return estado;
}

unsigned char acessarPilha(Pilha P){
	unsigned char ch;
	if(P.topo != sinal){
		ch = P.vetor[P.topo];
	}
	else{
		ch = ghost;
	}
	return ch;
}

Pilha pushPilha(Pilha P, unsigned char ch){
	if(P.topo+1 < Max){
		P.topo++;
		P.vetor[P.topo] = ch;
	}
	return P;
}

Pilha popPilha(Pilha P){
	if(P.topo != sinal){
		P.topo--;
	}
	return P;
}

Pilha esvaziarPilha(Pilha P){
	P.topo = sinal;
	return P;
}

void mostrarPilha(Pilha P){
	int i;
	if(P.topo != sinal){
		printf("\n");
		for(i = P.topo; i > 0; i--){
			printf("\t %c\n", P.vetor[i]);
		}
	}
	else{
		printf("\n A pilha esta vazia \n");
	}
}

int profundidadePilha(Pilha P){
	int tam = P.topo;
	return tam;
}

Pilha inverterPilha(Pilha P){
	Pilha A;
	int k = P.topo;
	A = criarPilha();
	if(P.topo != sinal){
		do{
			A.topo++;
			A.vetor[A.topo] = P.vetor[P.topo];
			P.topo--;
		}
		while(P.topo > 0);
	}
	return A;
}

Pilha copiarPilha(Pilha P){
	Pilha A;
	A = P;
	return A;
}



