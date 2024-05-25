/*
  Arquivo: caminhamentos.c
  Autor: Leonardo Grupioni
  Date: 19/08/23
  Descrição: Este programa implementa as operações de 
  			 caminhamento em uma Árvore Binária 
*/
#include <stdio.h>
#include <stdlib.h>  /* a constante NULL está nesta biblioteca */
#include "PilhaPointer.h"
#include "FilaPointer.h"
#include "Booleano.h"

#define MaxNos 9

typedef struct No{
        int chave;
        struct No *esq; 
        struct No *dir;
}No;

typedef No *Arvore;

// interface Arvore

Arvore criarArvore( );
bool verificarArvoreVazia(Arvore);

void mostrarArvore(Arvore);	// eRd recursivo
void mostrarArvore_edR(Arvore);
void mostrarArvore_Red(Arvore);

void mostrarArvorebfs(Arvore);
void mostrarArvoreDFS(Arvore);	// eRd não recursivo

Arvore inserirNo(Arvore, int);
Arvore remover(Arvore, int);

No *buscarABB(Arvore, int);


int main(){
  	Arvore a;
	No *novo;
    int i,item;	
	int chaves[MaxNos] = {5, 1, 19, 17, 9, 25, 20, 15, 14};

    a = criarArvore(); // mostrarArvoreDFS(a);

    printf("\n MaxNos = %d     Entrada de dados: ",MaxNos);   
	for(i = 0; i < MaxNos; i++){
		item = chaves[i]; printf(" %d  ",item);	
    	a = inserirNo(a, item);	
    }
    
    
    
    printf("\n");
    printf(" \neRd:  ");   mostrarArvore(a);   		printf("\n");
    printf(" \nbfs:  ");   mostrarArvorebfs(a); 	printf("\n");    
    printf(" \nRed:  ");   mostrarArvore_Red(a);   	printf("\n");
    printf(" \nedR:  ");   mostrarArvore_edR(a);   	printf("\n"); 
     printf(" \ndfs:  ");   mostrarArvoreDFS(a);   	printf("\n"); 
    printf(" \n \n");
    
    No *p = buscarABB(a, 15);
    printf("\nbuscado: %d -> %d\n", p, p->chave);
    
    return 0;
}


               
// implementações das funções de Arvore    
                 
Arvore criarArvore( ){
    Arvore ap;
    ap = NULL;
    return ap;
}

bool verificarArvoreVazia(Arvore ap){
    bool ok;
    if (ap == NULL) ok = TRUE; else ok = FALSE;
    return ok;
}

void mostrarArvore(Arvore ap){   // varredura eRd recursivo
    if (ap != NULL){
        mostrarArvore(ap->esq);
        printf(" %d  ",ap->chave);
        mostrarArvore(ap->dir);
    }      
}

void mostrarArvore_edR(Arvore ap){ 	// varredura edR
	if (ap != NULL){
        mostrarArvore_edR(ap->esq);  
        mostrarArvore_edR(ap->dir);
        printf(" %d  ",ap->chave);
	}      
}

void mostrarArvore_Red(Arvore ap){	// varredura Red
	if (ap != NULL){
        printf(" %d  ",ap->chave);
		mostrarArvore_Red(ap->esq);  
        mostrarArvore_Red(ap->dir);       
	}      
}
 
void mostrarArvorebfs(Arvore ap){	// caminhamento por nivel
    No *p, *e, *d;
    Fila f;
    if (ap != NULL){
        p = ap;
        criarFilaVazia(&f);
        pushFila(&f,p);
        do {
            p = acessarFila(&f); printf(" %d  ",p->chave); popFila(&f);
            e = p->esq;
            if (e != NULL) pushFila(&f,e);
            d = p->dir;
            if (d != NULL) pushFila(&f,d);
        } while (verificarFilaVazia(&f) == 0);
    }
}
      
void mostrarArvoreDFS(Arvore ap){	// varredura eRd não recursivo
    Pilha s;
    No *p;
    int fim;
    if (ap != NULL){
        criarPilhaVazia(&s);
        fim = 0;
        p = ap;           
        do {
            while (p != NULL){
                pushPilha(&s,p);
                p = p->esq;
            }
            if (verificarPilhaVazia(&s) == 0){
                p = acessarTopo(&s);
                printf(" %d  ",p->chave);
                popPilha(&s);
                p = p->dir;
            } else fim = 1;
        } while (fim == 0);
    } else printf("\n arvore vazia \n");
}

Arvore inserirNo(Arvore ap, int item){
    No *p, *ant;
	int i = 0;
	No *novo;
   	novo = (struct No*) malloc(sizeof(struct No));
   	novo->chave = item; 
   	novo->esq = NULL;  novo->dir = NULL;

    if (ap == NULL) ap = novo;  // árvore vazia
    else {	p = ap;
            while (p != NULL){
                ant = p; 
                if (novo->chave < p->chave){
                	p = p->esq;
                	i++;
				}
                else{
                	p = p->dir;
					i++;	
				} 
            }
            if (novo->chave < ant->chave) { ant->esq = novo; i++;}
            else { ant->dir = novo; i++;}
            
    }
    printf("\n\n Comparacoes: %d\n", i);
    return ap;
}

No *buscarABB(Arvore ap, int n){
	No *p;
	p = ap;
	if(p != NULL && p->chave != n){
		if(n < p->chave) p = buscarABB(ap->esq, n);
		else p = buscarABB(ap->dir, n);
	}
	
	return p;
}

Arvore remover(Arvore ap, int y){
	No *p, *ant, *m;
	if(ap != NULL){
		p = ap;
		while(p != NULL && p->chave != y){
			ant = p;
			if(y < p->chave) p = p->esq;
			else p = p->dir;
		}
		if(p != NULL){
			if(p->esq == NULL && p->dir == NULL){
				if(p == ant->esq) ant->esq = NULL;
				else ant->dir = NULL;
				free(p);
			} 
			else if(p->esq == NULL && p->dir != NULL){
				if(p->chave > ant->chave) ant->dir = p->dir;
				else ant->esq = p->dir;
				free(p);
			}else if(p->dir == NULL && p->esq != NULL){
				if(p->chave > ant->chave) ant->dir = p->esq;
				else ant->esq = p->esq; 
				free(p);
			}else{
				m = p->esq;
				ant = p;
				while(m->dir != NULL){
					ant = m;
					m = m->dir;
				}
				if(ant != p) ant->dir = m->esq;
				else ant->esq = m->esq;
				p->chave = m->chave;
				free(m);
			}
		}
	}
	return ap;
}


