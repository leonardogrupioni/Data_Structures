//Esta eh uma lista de inteiros de 1 a 60

#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"
#define ghost 0

typedef struct Celula{
	char elemento;
	struct Celula *next;
} Celula;

typedef Celula* Lista;

//interface
Lista criarLista();				//o construtor cria a lista vazia
bool listaVazia(Lista);			//devolve TRUE se a lista estiver vazia
void mostrarLista(Lista);		//mostra o conteudo da lista
Lista inserir(Lista, char);		//acrescenta o item no inicio da Lista
Lista inserirFim(Lista, char);	//acrescenta o item no final da lista
Lista inserirOrdenado(Lista, char);
Lista removePos(Lista, int);	//remove o item de ordem k
int obterTamanho(Lista);
int buscarItem(Lista, char);
char obterMaximo(Lista);			//devolve o maior valor existente na lista ou ghost
int localizarMaior(Lista);		//devolve a ordem do maior valor existente na lista ou zero
int obterSoma(Lista);

int main(){
	Lista A, B;
	int i;
	A = criarLista();
	B = criarLista();
		
	for(i = 2; i < 5; i++){
		A = inserir(A, i);
	}
	
	mostrarLista(A);
	
	A = inserirFim(A, 1);
	
	mostrarLista(A);

	B = inserirOrdenado(B, 4);
	B = inserirOrdenado(B, 1);
	B = inserirOrdenado(B, 5);
	B = inserirOrdenado(B, 2);
	
	mostrarLista(B);
	
	B = removePos(B, 1);
	printf("R\n");
	mostrarLista(B);
	
	int tam = obterTamanho(B);
	printf("tamanho: %d\n", tam);
	
	int ordem = buscarItem(B, 3);
	printf("ordem: %d\n", ordem);
	
	char maior = obterMaximo(B);
	printf("maior: %d\n", maior);
	
	int posMaior = localizarMaior(B);
	printf("posMaior: %d\n", posMaior);
	
	int soma = obterSoma(B);
	printf("soma: %d\n", soma);
	
}

Lista criarLista(){
	Lista L;
	L = NULL;
	return L;
}

bool listaVazia(Lista L){
	bool estado = FALSE;
	if(L == NULL){
		estado = TRUE;
	}
	return estado;
}

void mostrarLista(Lista L){
	if(L != NULL){
		Celula *p;
		p = L;
		printf(" %d ", p->elemento);
		while(p->next != L){
			p = p->next;
			printf(" %d ", p->elemento);
		}
		printf("\n\n");
	}
	else{
		printf("\n Lista Vazia \n");
	}
}

Lista inserir(Lista L, char y){
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->elemento = y;
	if(L != NULL){
		Celula *p;
		p = L;
		while(p->next != L){
			p = p->next;
		}
		
		novo->next = L;
		p->next = novo;
		L = novo;
	}
	else{
		novo->next = novo;
		L = novo;
	}
	
	return L;
}

Lista inserirFim(Lista L, char y){
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->elemento = y;
	if(L != NULL){
		Celula *p;
		p = L;
		while(p->next != L){
			p = p->next;
		}
	
		novo->next = p->next;
		p->next = novo;
	}
	else{
		novo->next = novo;
		L = novo;
	}
	
	return L;
}

Lista inserirOrdenado(Lista L, char y){
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->elemento = y;
	if(L != NULL){
		Celula *p; Celula *d;
		p = L;
		while(p->next != L && p->elemento <= y){
			p = p->next;
	 	}

		if(p->elemento >= y){
			if(p == L){
				d = L;
				while(d->next != L){
					d = d->next;
				}
				novo->next = p;
				d->next = novo;
				L = novo;
			}
			else{
				d = L;
				while(d->next != p){
					d = d->next;
				}
				d->next = novo;
				novo->next = p;
			}
		}
		else{
			novo->next = p->next;
			p->next = novo;
			
		}
	}
	else{
		novo->next = novo;
		L = novo;
	}
	
	return L;
}

Lista removePos(Lista L,int y){
	int count = 1;
	Celula *p; Celula *a;
	p = L;
	while(p->next != L && count != y){
		count++;
		a = p;
		p = p->next;
		
	}
	
	if(count == y){
		if(p == L){
			Celula *U;
			U = L;
			while(U->next != L){
				U = U->next;
			}
			if(p->next != L){
				L = p->next;
				U->next = L;
			}
			else{
				L = NULL;
			}
		}
		else {
			a->next = p->next;
		}

		free(p);
	}
	
	return L;
}

int obterTamanho(Lista L){
	int tam = 0;
	if(L != NULL){
		Celula *p;
		p = L;
		tam = 1;
		while(p->next != L){
			tam++;
			p = p->next;
		}
	}
	
	return tam;
}

int buscarItem(Lista L, char y){
	int count = 1;
	if(L != NULL){
		Celula *p;
		p = L;
		while(p->next != L && p->elemento != y){
			count++;
			p = p->next;
		}
		
		if(p->elemento != y){
			count = 0;
		}
	}
	
	return count;
}

char obterMaximo(Lista L){
	char max;
	if(L != NULL){
		Celula *p; Celula *d;
		p = L;
		max = p->elemento;
		do{
			d = p->next;
			if(d->elemento > max){
				max = d->elemento;
			}
			
			p = p->next;
		}
		while(p->next != L);
	}
	
	return max;
}

int localizarMaior(Lista L){
	int count = 0;
	if(L != NULL){
		char max;
		count = 1;
		Celula *p; Celula *d;
		p = L;
		max = p->elemento;
		do{
			d = p->next;
			if(d->elemento > max){
				max = d->elemento;
				count++;
			}
			
			p = p->next;
		}
		while(p->next != L);			
		}
	
	return count;
}

int obterSoma(Lista L){
	int soma = 0;
	if(L != NULL){
		Celula *p;
		char num;
		p = L;
		do{
			num = p->elemento;
			soma = soma + num;
			p = p->next;
		}
		while(p != L);
	}
	
	return soma;
}
