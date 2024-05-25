//Esta eh uma lista de inteiros de 1 a 60

#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"
#define ghost 0

typedef struct Celula{
	char prim;
	struct Celula *suc;
	struct Celula *pre;
} Celula;

typedef struct{
	int tamanho;
	Celula *inicio;
	Celula *fim;
} Lista;

//interface
Lista criarLista();				//o construtor cria a lista vazia
bool listaVazia(Lista);			//devolve TRUE se a lista estiver vazia
void mostrarLista(Lista);		//mostra o conteudo da lista a partir do inicio
void mostrarListaDE(Lista);		//mostra o conteudo da lista a partir do fim
void inserir(Lista *, char);		//acrescenta o item no inicio da Lista
void inserirFim(Lista *, char);	//acrescenta o item no final da lista
void removePos(Lista *, int);	//remove o item de ordem k
int obterMaximo(Lista);			//devolve o maior valor existente na lista ou ghost
int localizarMaior(Lista);		//devolve a ordem do maior valor existente na lista ou zero
int obterSoma(Lista);
void inserirOrdenado(Lista*, char);

int main(){
	Lista L, A, B, C;
	int i;
	L = criarLista();
	A = criarLista();
	B = criarLista();
	C = criarLista();
	
	for(i = 2; i < 10; i++){
		inserir(&L, i);
	}
	
	mostrarLista(L);
	
	inserirFim(&L, 1);
	
	mostrarListaDE(L);
	
	removePos(&L, 2);
	
	mostrarLista(L);
	
	int maior = obterMaximo(L);
	printf("maiorL: %d\n", maior);
	
	int pos = localizarMaior(L);
	printf("posL: %d\n", pos);

	//Lista A
	inserir(&A, 1);
	inserir(&A, 5);
	inserir(&A, 9);
	inserir(&A, 4);
	
	mostrarLista(A);
	
	maior = obterMaximo(A);
	printf("maiorA: %d\n", maior);
	
	pos = localizarMaior(A);
	printf("posA: %d\n", pos);
	
	inserirOrdenado(&B, 1);
	inserirOrdenado(&B, 5);
	inserirOrdenado(&B, 9);
	inserirOrdenado(&B, 4);
	
	mostrarLista(B);
	
	int soma = obterSoma(B);
	printf("soma: %d\n", soma);
	
	inserir(&C, 10);
	
	mostrarLista(C);
	
	removePos(&C, 1);
	
	mostrarLista(C);
	
}
Lista criarLista(){
	Lista L;
	L.tamanho = 0;
	L.inicio = NULL;
	L.fim = NULL;
	return L;
}

bool listaVazia(Lista L){
	bool estado = FALSE;
	
	if(L.inicio == NULL){
		estado = TRUE;
	}
	
	return estado;
}

void mostrarLista(Lista L){
	Celula *p;
	if(L.inicio == NULL){
		printf("\n Lista Vazia \n");
	}
	else{
		p = L.inicio;
		printf(" %d ", p->prim);
		while(p->suc != NULL){
			p = p->suc;
			printf(" %d ", p->prim);
		}
		printf("\n\n");
	}
}

void mostrarListaDE(Lista L){
	Celula *p;
	if(L.fim == NULL){
		printf("\n Lista Vazia \n");
	}
	else{
		p = L.fim;
		printf(" %d ", p->prim);
		while(p->pre != NULL){
			p = p->pre;
			printf(" %d ", p->prim);
		}
		printf("\n\n");
	}
}

void inserir(Lista* L, char y){
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->prim = y;
	novo->pre = NULL;
	if(L->inicio != NULL){
		Celula *f;
		f = L->inicio;
		novo->suc = f;
		f->pre = novo;
		L->inicio = novo;
		L->tamanho++;
	}
	else{
		novo->suc = NULL;
		L->inicio = novo;
		L->fim = novo;
		L->tamanho++;
	}
}

void inserirFim(Lista *L, char y){
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->prim = y;
	novo->suc = NULL;
	if(L->fim != NULL){
		Celula *p;
		p = L->fim;
		novo->pre = p;
		p->suc = novo;
		L->fim = novo;
		L->tamanho++;
	}
	else{
		novo->pre = NULL;
		L->fim = novo;
		L->inicio = novo;
		L->tamanho++;
	}
}

void removePos(Lista *L, int y){
	int count = 1;
	
	if(y > 0 && y <= L->tamanho){
		Celula *p; Celula *f; Celula *U;
		p = L->inicio;
		while(p != NULL && count != y){
			p = p->suc;
			count++;
		}
		
		if(count == y){
			if(p->suc == NULL && p->pre != NULL){
				U = p->pre;
				U->suc = p->suc;
				L->fim = U;
				L->tamanho--;
			}
			else if(p->pre == NULL && p->suc != NULL){
				f = p->suc;
				f->pre = p->pre;
				L->inicio = f;
				L->tamanho--;
			}
			else if (p->pre != NULL && p->suc != NULL){
				f = p->pre;
				f->suc = p->suc;
				U = p->suc;
				U->pre = p->pre;
				L->tamanho--;
			}
			else{
				L->inicio = NULL;
				L->fim = NULL;
				L->tamanho--;
			}
		}
		free(p);
	}
	
}

int obterMaximo(Lista L){
	int max = ghost;
	if(L.inicio != NULL){
		Celula *p;
		p = L.inicio;
		max = p->prim;
		
		do{
			p = p->suc;
			if(max < p->prim){
				max = p->prim;
			}	
		}while(p->suc != NULL);	
	}

	return max;
}

int localizarMaior(Lista L){
	int pos = 0;
	int count = 1;
	int maior = ghost;
	if(L.inicio != NULL){
		Celula *p;
		p = L.inicio;
		maior = p->prim;
		pos = count;
		do{
			p = p->suc;
			count++;
			if(p->prim > maior){
				maior = p->prim;
				pos = count;
			}
			
		}
		while(p->suc != NULL);
	}
	
	return pos;
}

void inserirOrdenado(Lista *L, char y){
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->prim = y;
	if(L->inicio != NULL){
		Celula *p;
		p = L->inicio;
		while(p != NULL && p->prim <= y){
			p = p->suc;
			
		}
		
		if(p == NULL){
			novo->suc = NULL;
			p = L->fim;
			p->suc = novo;
			novo->pre = p;
			L->fim = novo;
			L->tamanho++;
		}
		else{
			if(p == L->inicio){
				novo->pre = NULL;
				novo->suc = p;
				p->pre = novo;
				L->inicio = novo;
				L->tamanho++;
			}
			else{
				Celula *a;
				a = p->pre;
				novo->suc = p;
				novo->pre = a;
				p->pre = novo;
				a->suc = novo;
				L->tamanho++;
			}
		}
	}
	else{
		novo->suc = NULL;
		novo->pre = NULL;
		L->inicio = novo;
		L->fim = novo;
		L->tamanho++;
	}
}

int obterSoma(Lista L){
	int soma = 0;
	if(L.inicio != NULL){
		Celula *p;
		p = L.inicio;
		do{
			soma = soma + p->prim;
			p = p->suc;
		}
		while(p != NULL);
	}
	
	return soma;
}
