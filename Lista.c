#include<stdio.h>
#define Max 1001
#define fantasma 36

typedef struct{
	int tam;
	unsigned char vetor[Max];
}Lista;

//interface
Lista criarLista();
int obterTamanho(Lista);
void mostrarLista(Lista);
unsigned char obterElemento(Lista, int);
Lista inserir(Lista, unsigned char);

int main(){
	Lista L1;
	int i;
	L1 = criarLista();
	mostrarLista(L1);
	printf("\n\n");
	
	for(i = 65; i < 72; i++){
		L1 = inserir(L1, i);
	}
	mostrarLista(L1);
	printf("\n\n");
	
	unsigned char y = obterElemento(L1, 5);
	printf("y: %c\n", y);
	
	int tam = obterTamanho(L1);
	printf("tam: %d\n", tam);
}

Lista criarLista(){
	Lista L;
	L.tam = 0;
	return L;
}

int obterTamanho(Lista L){
	int tam = L.tam;
	return tam;
}

void mostrarLista(Lista L){
	int i;
	if(L.tam == 0){
		printf("\n\n Lista Vazia\n\n");
	}
	else{
		for(i = 0; i < L.tam; i++){
			printf("%c ", L.vetor[i]);
		}
		printf("\n\n");
	}
}

unsigned char obterElemento(Lista L, int p){
	unsigned char ch;
	if(p >= 0 && p < L.tam){
		ch = L.vetor[p];
	}
	else{
		ch = fantasma;
	}
	
	return ch;
}

Lista inserir(Lista L, unsigned char ch){
	if(L.tam < Max-1){
		L.vetor[L.tam] = ch;
		L.tam++;
	}
	
	return L;
}
