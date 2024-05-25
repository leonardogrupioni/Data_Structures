//Esta eh uma lista de inteiros positivos
#define ghost 0
#include<stdio.h>
#include"Booleano.h"

typedef struct Celula{
	int info;
	struct Celula *next;
} Celula;

typedef struct{
	int tamanho;
	Celula *inicio;
}Lista;

//interface
Lista newLista();
void mostrarLista(Lista);
bool listaVazia(Lista);
int obterTamanho(Lista);
int buscarItem(Lista, int);
void inserir(Lista*, int);
void buscaRemove(Lista*, int);
int contarIguais(Lista, int);
void buscaInsere(Lista*, int);
bool verificarCrescente(Lista);
bool verificarIgual(Lista, Lista);
Lista concatenarListas(Lista, Lista);
Lista inverterLista(Lista);
void concatenarListas2(Lista*, Lista*);
Lista separarLista(Lista*, int);

int main(){
	Lista L; Lista P;
	int i;
	L = newLista();
	P = newLista();
	
	printf("\n================Antes================\n");
	mostrarLista(L);
	
	inserir(&L, 5);
	inserir(&L, 4);
	inserir(&L, 3);
	inserir(&L, 2);
	inserir(&L, 1);
	
	inserir(&P, 6);
	inserir(&P, 7);
	inserir(&P, 8);
	
	printf("\n=================ListaL=================\n");
	mostrarLista(L);
	
	printf("\n=================ListaP=================\n");
	mostrarLista(P);
	
	/*L = buscaRemove(L, 2);
	
	printf("\n==================Remove==============\n");
	mostrarLista(L);
	
	int iguais = contarIguais(L, 4);
	printf("iguais: %d\n", iguais);
	
	L = buscaInsere(L, 4);
	printf("===================InseriIgual===========\n");
	mostrarLista(L);
	
	L = buscaInsere(L, 5);
	printf("==================InseriDiferente===========\n");
	mostrarLista(L);
	
	*/
	
	bool estado = verificarCrescente(L);
	if(estado){
		printf("crescendo\n");
	}
	else{
		printf("opa\n");
	}
	
	estado = verificarIgual(L, P);
	if(estado){
		printf("Igual\n");
	}
	else{
		printf("opa2\n");
	}
	
	
	concatenarListas2(&L, &P);
	printf("==============L=============\n");
	mostrarLista(L);
	printf("==============P==============\n");
	mostrarLista(P);
	
	P = separarLista(&L, 4);
	
	printf("=============Separei===========\n");
	mostrarLista(P);
	
	L = inverterLista(L);
	
	printf("===============Inverti================\n");
	mostrarLista(L);
}

Lista newLista(){
	Lista L;
	L.inicio =NULL;
	L.tamanho = 0;
	return L;
}

void mostrarLista(Lista L){
	if(L.inicio != NULL){
		Celula *aux;
		aux = L.inicio;
		while(aux != NULL){
			printf("%d ", aux->info);
			aux = aux->next;
		}
		printf("\n\n");
	}
	else{
		printf("\n Lista Vazia\n");
	}
	
}

bool listaVazia(Lista L){
	bool vazio = FALSE;
	if(L.inicio == NULL){
		vazio = TRUE;
	}
	
	return vazio;
}

int obterTamanho(Lista L){
	int tam = 0;
	if(L.inicio != NULL){
		Celula *aux;
		aux = L.inicio;
		do{
			tam++;
			aux = aux->next;
		}
		while(aux != NULL);
	}
	
	return tam;
}

int buscarItem(Lista L, int y){
	int count = 0;
	if(L.inicio != NULL){
		Celula *aux;
		aux = L.inicio;
		while(aux != NULL && aux->info != y){
			count++;
			aux = aux->next;
		}
		return count;
	}
}

void inserir(Lista *L, int y){
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->info = y;
	novo->next = L->inicio;
	L->inicio = novo;

}

void buscaRemove(Lista *L, int y){
	if(L->inicio != NULL){
		Celula *p; Celula *ant;
		p = L->inicio;
		while(p->next != NULL && p->info != y){
			ant = p;
			p = p->next;
		}
		
		if(p->info == y){
			if(p == L->inicio){
				if(p->next == NULL){
					L->inicio = NULL;
				}
				else{
					L->inicio = p->next;
				}
			}
			else{
				ant->next = p->next;
			}
			free(p);
		}
	}
}

int contarIguais(Lista L, int y){
	int iguais = 0;
	if(L.inicio != NULL){
		Celula *p;
		p = L.inicio;
		while(p != NULL){
			if(p->info == y){
				iguais++;
			}
			p = p->next;
		}
	}
	return iguais;
}

void buscaInsere(Lista *L, int y){
	if(L != NULL){
		Celula *p;
		p = L->inicio;
		while(p != NULL && p->info != y){
			p = p->next;
		}
		if(p == NULL){
			Celula *novo;
			novo = malloc(sizeof(Celula));
			novo->info = y;
			novo->next = L->inicio;
			L->inicio = novo;
		}
	}
}

bool verificarCrescente(Lista L){
	bool estado = FALSE;
	if(L.inicio != NULL){
		Celula *p; Celula *a;
		p = L.inicio;
		a = p->next;
		while(a != NULL && p->next != NULL && p->info < a->info){
			p = p->next;
			a = p->next;
		}
	
		if(a == NULL){
			estado = TRUE;
		}
	}
	
	return estado;
}

bool verificarIgual(Lista L, Lista P){
	bool estado = FALSE;
	if(L.inicio != NULL && P.inicio != NULL){
		Celula *p; Celula *a;
		p = L.inicio;
		a = P.inicio;

		while(p != NULL && p->info != a->info){
			a = a->next;
			if(a == NULL){
				a = P.inicio;
				p = p->next;
			}
		}
	
		if(p != NULL){
			estado = TRUE;
		}		
	}	
	return estado;
}

Lista concatenarListas(Lista L, Lista P){
	Lista nova;
	nova = newLista();
	if(L.inicio != NULL && P.inicio != NULL){
		nova.inicio = L.inicio;
		Celula *p;
		p = L.inicio;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = P.inicio;
	}
	
	return nova;
}

Lista inverterLista(Lista L){
	Celula* p; Celula* a; Celula* f;
	
	if(L.inicio != NULL){
		a = NULL;
		p = L.inicio;
		
		while(p != NULL){
			f = p->next;
			p->next = a;
			a = p;
			p = f;
		} 
		
		L.inicio = a;
	}
	return L;
}

void concatenarListas2(Lista* L, Lista* P){
	if(L->inicio != NULL && P->inicio != NULL){
		Celula *p;
		p = L->inicio;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = P->inicio;
		P->inicio = NULL;
	}
}

Lista separarLista(Lista* L, int y){
	Lista A;
	A = newLista();
	if(L->inicio != NULL){
		Celula *p; Celula *ant;
		p = L->inicio;
		while(p->next != NULL && p->info != y){
			p = p->next;
		}
		if(p->info == y){
			A.inicio = p->next;
			p->next = NULL;
		}
	}
	return A;
}
