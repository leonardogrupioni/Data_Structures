/* QUAL A ÁRVORE ? */
/*
  Arquivo: qual_a_Arvore.c
  Autor: Leonardo Grupioni
  Data: 19/03/13 14:49
  Descrição: Este programa implementa uma Árvore Binária para brincar.
  A função de construir liga uma raiz a duas árvores esquerda e direita.
  Implementa o caminhamento bfs - por nível, os tres caminhamentos recursivos
  e o caminhamento eRd não recursivo.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "FilaPointer.h"
#include "PilhaPointer.h"
#include "Booleano.h"

typedef struct No{
    int elemento;            
    struct No * esq; 
    struct No * dir;
} No;

typedef No* Arvore;

Arvore criarArvoreVazia( );
Arvore construirArvore(int, Arvore, Arvore);
Arvore construirArvoreRam(int);
Arvore construirExemplo();
No* buscar(Arvore, int);
No* rodar_Direita(No*);
No* rodar_Esquerda(No*);
No* rodar_DuplaDireita(No*);
No* rodar_DuplaEsquerda(No*);
No* obterPrimeiro(Arvore);
No* obterUltimo(Arvore);
No* obterSucessor(Arvore, int);
No* obterAnterior(Arvore, int);
bool verificarArvoreVazia(Arvore);
void mostrarRaiz(Arvore);
void mostrarArvore_eRd(Arvore);
void mostrarArvore_Red(Arvore);
void mostrarArvore_edR(Arvore);
void mostrarArvorebfs(Arvore);
void mostrarArvoreDFS(Arvore);
void mostrarPrimeiro(Arvore);
void mostrarUltimo(Arvore);
void mostrarFolhas(Arvore);
int obterAlturaNaoRecursivo(Arvore);
int obterAltura(Arvore);
int contarNos(Arvore);
int contarNosNaoRecursivo(Arvore);
int contarFolhas(Arvore);
int contarFolhasNaoRecursivo(Arvore);

int main(){
    Arvore tree;
    printf(" \n QUAL A ARVORE ? \n");
    //tree = construirExemplo();
	tree = construirArvoreRam(4);

    printf("\n\n Caminhamento por nivel: \n\n");			mostrarArvorebfs(tree);
    printf("\n\n Caminhamento eRd: \n\n");  				mostrarArvore_eRd(tree);
    printf("\n\n Caminhamento Red: \n\n");     				mostrarArvore_Red(tree);
    printf("\n\n Caminhamento edR: \n\n");     				mostrarArvore_edR(tree);
	printf("\n\n Caminhamento eRd nao recursivo: \n\n");	mostrarArvoreDFS(tree);  
    
    printf("\n\n");
    
//    int altura = obterAlturaNaoRecursivo(tree);
    int altura = obterAltura(tree);
	printf("\n\n Altura: %d\n\n", altura);
	
//	int qtdNos = contarNos(tree);
	int qtdNos = contarNosNaoRecursivo(tree);
	printf("\n\n qtdNos: %d\n\n", qtdNos);
	
//	int qtdFolhas = contarFolhas(tree);
	int qtdFolhas = contarFolhasNaoRecursivo(tree);
	printf("\n\n qtdFolhas: %d\n\n", qtdFolhas);
	
	printf("\n\nFolhas: \n\n");								mostrarFolhas(tree);
	
	No *y = buscar(tree, 7);
	printf("\n\n busca: %d\n\n", y);
	
	mostrarPrimeiro(tree);
	mostrarUltimo(tree);
	
	No* primeiro = obterPrimeiro(tree);
	printf("\n\n primeiro: %d = %d\n\n", primeiro, primeiro->elemento);
	
	No* ultimo = obterUltimo(tree);
	printf("\n\n ultimo: %d = %d\n\n", ultimo, ultimo->elemento);
	
	No* anterior = obterAnterior(tree, 1);
	printf("\n\n anterior: %d = %d\n\n", anterior, anterior->elemento);
	
//	No* sucessor = obterSucessor(tree, 6);
//	printf("\n\n sucessor: %d = %d\n\n", sucessor, sucessor->elemento);
	
	No *novo = rodar_Direita(tree);
//	printf("\n\n rodar_Direita: \n\n");  				    mostrarArvore_eRd(novo);
	
//	No *novo2 = rodar_Esquerda(tree);
//	printf("\n\n Caminhamento eRd: \n\n");  				mostrarArvore_eRd(novo2);

//	No *novo3 = rodar_DuplaDireita(tree);
//	printf("\n\n Caminhamento eRd: \n\n");  				mostrarArvore_eRd(novo3);
	
	No *novo4 = rodar_DuplaEsquerda(novo);
	printf("\n\n Caminhamento eRd: \n\n");  			    mostrarArvore_eRd(novo4);
	

    printf("\n\n");
    return 0;
}

Arvore criarArvoreVazia( ){
    Arvore ap;
    ap = NULL;
	return ap;
}

Arvore construirArvore(int item, Arvore e, Arvore d){
    Arvore raiz;
    raiz = malloc(sizeof(No));
    raiz->elemento = item;
    raiz->esq = e;
    raiz->dir = d;
    return raiz;
}

Arvore construirExemplo(){
	Arvore a, b, c, d;
	a = criarArvoreVazia();
	b = construirArvore(6, a, a);
	c = construirArvore(7, b, a);
	b = construirArvore(4, a, a);
	c = construirArvore(1, c, b);
	b = construirArvore(5, a, a);
	d = construirArvore(2, a, b);
	a = construirArvore(3, c, d);
}

bool verificarArvoreVazia(Arvore ap){
    bool ok;
   	if(ap == NULL) ok = TRUE;
   	else ok = FALSE;
    return ok;
}

void mostrarRaiz(Arvore ap){
    if (ap != NULL) printf(" %d  ",ap->elemento);
}

void mostrarArvore_eRd(Arvore ap){ // eRd
    if (ap != NULL){
        mostrarArvore_eRd(ap->esq);
        mostrarRaiz(ap);
        mostrarArvore_eRd(ap->dir);
	}      
}

void mostrarArvore_Red(Arvore ap){ // Red
    if(ap != NULL){
    	mostrarRaiz(ap);
		mostrarArvore_Red(ap->esq);
		mostrarArvore_Red(ap->dir);
	}
}

void mostrarArvore_edR(Arvore ap){ // edR
    if(ap != NULL){
    	mostrarArvore_edR(ap->esq);
    	mostrarArvore_edR(ap->dir);
    	mostrarRaiz(ap);
	}
}

void mostrarArvorebfs(Arvore ap){	// nivel
    No *p;
    Fila f;
    if(ap != NULL){
    	criarFilaVazia(&f);
    	p = ap;
    	pushFila(&f, p);
    	do{
    		p = acessarFila(&f);
    		printf(" %d  ", p->elemento);
    		popFila(&f);
    		if(p->esq != NULL) pushFila(&f, p->esq);
    		if(p->dir != NULL) pushFila(&f, p->dir);
		}while(verificarFilaVazia(&f) == 0);
	}
}

void mostrarArvoreDFS(Arvore ap){   // eRd nao recursivo
	No *p; Pilha s; int fim;
	if(ap != NULL){
		criarPilhaVazia(&s);
		fim = 0;
		p = ap;
		do{
			while(p != NULL){
				pushPilha(&s, p);
				p = p->esq;
			}
			
			if(verificarPilhaVazia(&s) == 0){
				p = acessarTopo(&s);
				printf(" %d  ",p->elemento);
				popPilha(&s);
				p = p->dir;
			}else{
				fim = 1;
			}
		}while(fim == 0);
	}
	
}

int obterAlturaNaoRecursivo(Arvore ap){
	int h = -1;
	if(ap != NULL){
		int esq, dir; No *p;
		esq = 0; dir = 0; p = ap;
		
		while(p->esq != NULL){
			esq++;
			p = p->esq;
		}
		p = ap;
		
		while(p->dir != NULL){
			dir++;
			p = p->dir;
		}
		if(esq > dir){
			h = esq;
		} else h = dir;
	}
	
	return h;
}

int obterAltura(Arvore ap){
	int h;
	if(ap == NULL) h = -1;
	else{
		int esq = obterAltura(ap->esq);
		int dir = obterAltura(ap->dir);
		if(esq > dir) h = esq + 1;
		else h = dir + 1;
	}
	
	return h;
}

int contarNos(Arvore ap){
	int numNos;
	if(ap == NULL) numNos = 0;
	else{
		int esq = contarNos(ap->esq);
		int dir = contarNos(ap->dir);
		numNos = esq + dir + 1;
	}
	return numNos;
}

int contarNosNaoRecursivo(Arvore ap){
	int numNos;
	if(ap == NULL) numNos = 0;
	else{
		int esq, dir; No *p;
		esq = 0; dir = 0; p = ap;
		while(p->esq != NULL){
			p = p->esq;
			esq++;
			if(p->dir != NULL) esq++;
		}
		
		p = ap;
		
		while(p->dir != NULL){
			p = p->dir;
			dir++;
			if(p->esq != NULL) dir++;
		}
		
		numNos = esq + dir + 1; //+1 eh a raiz
	}
	
	return numNos;
}

int contarFolhas(Arvore ap){
	int numFolhas;
	if(ap == NULL) numFolhas = 0;
	else if(ap->esq == NULL && ap->dir == NULL) numFolhas = 1;
		else{
			int esq = contarFolhas(ap->esq);
			int dir = contarFolhas(ap->dir);
			numFolhas = esq + dir;
		}
		
	return numFolhas;
}

int contarFolhasNaoRecursivo(Arvore ap){
	int numFolhas;
	if(ap == NULL) numFolhas = 0;
	else if(ap->esq == NULL && ap->dir == NULL) numFolhas = 1;
		else{
			Pilha s; No *p; int fim;
			p = ap; fim = 0;
			criarPilhaVazia(&s);
			do{
				while(p != NULL){
					pushPilha(&s, p);
					p = p->esq;
				}
				if(verificarPilhaVazia(&s) == 0){
					p = acessarTopo(&s);
					if(p->dir == NULL && p->esq == NULL) numFolhas++;
					popPilha(&s);
					p = p->dir;
				}else fim = 1;
			}while(fim == 0);
		}
	return numFolhas;
}

No* buscar(Arvore ap, int n){
	No *p, *y;
	y = NULL;
	if(ap != NULL){
		int achou = 0;
		p = ap;
		Fila f; criarFilaVazia(&f);
		pushFila(&f, p);
		do{
			p = acessarFila(&f);
			if(p->elemento == n){
				y = p;
				achou = 1;
			}else{
				popFila(&f);
				if(p->esq != NULL) pushFila(&f, p->esq);
				if(p->dir != NULL) pushFila(&f, p->dir);
			}
		}while(verificarFilaVazia(&f) == 0 && achou == 0);
	}
	
	return y;
}

No* rodar_Direita(No* p){
	No* y, *re;
	re = p;
	if(p != NULL){
		y = p->esq;
		if(y != NULL){
			p->esq = y->dir;
			y->dir = p;
			re = y;
		}
	}
	return re;
}

No* rodar_Esquerda(No* p){
	No *y, *re;
	re = p;
	if(p != NULL){
		y= p->dir;
		if(y != NULL){
			p->dir = y->esq;
			y->esq = p;
			re = y;
		}
	}
	return re;
}

No* rodar_DuplaDireita(No* p){
	No *y, *z, *re;
	re = p;
	if(p != NULL){
		y = p->esq;
		if(y != NULL && y->dir != NULL){
			z = y->dir;
			p->esq = z->dir;
			y->dir = z->esq;
			z->dir = p;
			z->esq = y;
			re = z;
		}
	}
	return re;
}

No* rodar_DuplaEsquerda(No* p){
	No *y, *z, *re;
	re = p;
	if(p != NULL){
		y = p->dir;
		if(y != NULL && y->esq != NULL){
			z = y->esq;
			p->dir = z->esq;
			y->esq = z->dir;
			z->esq = p;
			z->dir = y;
			re = z;
		}
	}
	return re;
}

void mostrarPrimeiro(Arvore ap){
	No *p;
	if(ap != NULL){
		p = ap;
		while(p->esq != NULL) p = p->esq;
		printf("Primeiro no: %d \n\n", p->elemento);
	}
}

void mostrarUltimo(Arvore ap){
	No *p;
	if(ap != NULL){
		p = ap;
		while(p->dir != NULL) p = p->dir;
		printf("Ultimo no: %d \n\n", p->elemento);
	}
}

No* obterPrimeiro(Arvore ap){
	No *p; p = NULL;
	if(ap != NULL){
		p = ap;
		while(p->esq != NULL) p = p->esq;
	}
	return p;
}

No* obterUltimo(Arvore ap){
	No *p; p = NULL;
	if(ap != NULL){
		p = ap;
		while(p->dir != NULL) p = p->dir;
	}
	return p;
}

No* obterAnterior(Arvore ap, int n){
	No* p, *ant, *d, *e;
	Pilha s; int achou;
	ant = NULL;
	if(ap != NULL){
		p = ap;
		criarPilhaVazia(&s);
		achou = 0;
		do{
			while(p != NULL){
				pushPilha(&s, p);
				p = p->esq;
			}
			
			if(verificarPilhaVazia(&s) == 0){
				p = acessarTopo(&s);
				if(p->dir != NULL){
					d = p->dir;
					if(d->elemento == n){
						ant = p;
						achou = 1;
					}
				}
				if(p->esq != NULL){
					e = p->esq;
					if(e->elemento == n){
						ant = p;
						achou = 1;
					}
				}
				popPilha(&s);
				p = p->dir;
				
			}else achou = 1;
		}while(achou == 0);
	}
	return ant;
}

void mostrarFolhas(Arvore ap){
	if(ap != NULL){
		if(ap->dir == NULL && ap->esq == NULL) printf(" %d ", ap->elemento);
		mostrarFolhas(ap->esq);
		mostrarFolhas(ap->dir);
	}
}

/*
		NAO FUNCIONA
Arvore construirArvoreRam(int n){
	Arvore ap, e, d;No* p; ap = p;
	ap = malloc(sizeof(No));
	if(n == 0) ap == NULL;
	else{
		int n1, n2, random;
		n1 = n/2; n2 = n - n1;
		srand(time(0));
		random = rand() % 11;
		ap->elemento = random;
		ap->esq = construirArvoreRam(n1);
		ap->dir = construirArvoreRam(n2);
	}
	return ap;
}*/

