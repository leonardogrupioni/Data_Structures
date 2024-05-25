//Esta eh uma lista de inteiros positivos
#define ghost 0
#include<stdio.h>
#include"Booleano.h"

typedef struct Celula{
	int info;
	struct Celula *next;
} Celula;

typedef Celula *Lista;

//interface
Lista newLista();
void mostrarLista(Lista);
bool listaVazia(Lista);
int obterTamanho(Lista);
int buscarItem(Lista, int);
Lista inserir(Lista, int);
Lista buscaRemove(Lista, int);
int contarIguais(Lista, int);
Lista buscaInsere(Lista, int);
bool verificarCrescente(Lista);
bool verificarIgual(Lista, Lista);
Lista concatenarListas(Lista, Lista);
Lista inverterLista(Lista);

int main(){
	Lista L; Lista P;
	int i;
	L = newLista();
	P = newLista();
	
	printf("\n================Antes================\n");
	mostrarLista(L);
	
	L = inserir(L, 5);
	L = inserir(L, 4);
	L = inserir(L, 3);
	L = inserir(L, 2);
	L = inserir(L, 1);
	
	P = inserir(P, 5);
	P = inserir(P, 7);
	P = inserir(P, 8);
	
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
	
	
	L = concatenarListas(L, P);
	
	mostrarLista(L);
	
	L = inverterLista(L);
	
	printf("===============Inverti================\n");
	mostrarLista(L);
}

Lista newLista(){
	Lista L;
	L = NULL;
	return L;
}

void mostrarLista(Lista L){
	if(L != NULL){
		Celula *aux;
		aux = L;
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
	if(L == NULL){
		vazio = TRUE;
	}
	
	return vazio;
}

int obterTamanho(Lista L){
	int tam = 0;
	if(L != NULL){
		Celula *aux;
		aux = L;
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
	if(L != NULL){
		Celula *aux;
		aux = L;
		while(aux != NULL && aux->info != y){
			count++;
			aux = aux->next;
		}
		return count;
	}
}

Lista inserir(Lista L, int y){
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->info = y;
	novo->next = L;
	L = novo;
	return L;
}

Lista buscaRemove(Lista L, int y){
	if(L != NULL){
		Celula *p; Celula *ant;
		p = L;
		while(p->next != NULL && p->info != y){
			ant = p;
			p = p->next;
		}
		
		if(p->info == y){
			if(p == L){
				if(p->next == NULL){
					L = NULL;
				}
				else{
					L = p->next;
				}
			}
			else{
				ant->next = p->next;
			}
			free(p);
		}
	}
	return L;
}

int contarIguais(Lista L, int y){
	int iguais = 0;
	if(L != NULL){
		Celula *p;
		p = L;
		while(p != NULL){
			if(p->info == y){
				iguais++;
			}
			p = p->next;
		}
	}
	return iguais;
}

Lista buscaInsere(Lista L, int y){
	if(L != NULL){
		Celula *p;
		p = L;
		while(p != NULL && p->info != y){
			p = p->next;
		}
		if(p == NULL){
			Celula *novo;
			novo = malloc(sizeof(Celula));
			novo->info = y;
			novo->next = L;
			L = novo;
		}
	}
	return L;
}

bool verificarCrescente(Lista L){
	bool estado = FALSE;
	if(L != NULL){
		Celula *p; Celula *a;
		p = L;
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
	if(L != NULL && P != NULL){
		Celula *p; Celula *a;
		p = L;
		a = P;

		while(p != NULL && p->info != a->info){
			a = a->next;
			if(a == NULL){
				a = P;
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
	if(L != NULL && P != NULL){
		nova = L;
		Celula *p;
		p = L;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = P;
	}
	
	return nova;
}

Lista inverterLista(Lista L){
	Celula* p; Celula* a; Celula* f;
	
	if(L != NULL){
		a = NULL;
		p = L;
		
		while(p != NULL){
			f = p->next;
			p->next = a;
			a = p;
			p = f;
		} 
		
		L = a;
	}
	return L;
}
