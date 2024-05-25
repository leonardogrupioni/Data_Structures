/*
  Arquivo: exercicioSedjewick.c
  Autor: Leonardo Grupioni
  Date: 12/09/23 
  Descrição: Este programa implementa a operação de inserção 
  			 com rotação em uma árvore binária de busca, de forma
			 que o item inserido seja levado para a raiz da árvore.
*/

#include <stdio.h>
#include <stdlib.h>  /* a constante NULL está nesta biblioteca */
#include "PilhaPointer.h"
#include "FilaPointer.h"
#include "Booleano.h"
#define maxNos 9

typedef struct No{
        int chave;
        struct No *pai;
        struct No *esq; 
        struct No *dir;
} No;

typedef No* ABB;

//protótipos No
void mostrarNo(No*);


// protótipos ABB
ABB criarABB( );

void mostrarArvoreDFS(ABB);
void mostrarArvorebfs(ABB);
void mostrarArvore_edR(ABB);
void mostrarArvore_Red(ABB);
void mostrarPrimeiro(ABB);
void mostrarUltimo(ABB);

No* rodarEsq(No*);                  
No* rodarDir(No*); 	
No* obterAncestral(ABB, No*, No*);
No* buscarABB(ABB, int);
No* obterAnterior(ABB, int);
No* obterPrimeiro(ABB);
No* obterSucessor(ABB, int);
No* select(ABB, int);

ABB inserirNo(ABB, int);
ABB inserir(ABB, int);
ABB removerRaiz(ABB);
ABB inserirRecursivo(ABB, int);
ABB buscaInsere(ABB, int);
ABB remover(ABB, int);
ABB vetorArvore(int*);

int rank(ABB, int);
int* arvoreVetor(ABB);

int v[maxNos];

int main(){
    ABB a;
    int y; int *nos;
    int chaveNos[maxNos] = {1, 5, 9, 14, 15, 17, 19, 20 ,25};
    
    a = criarABB( );
	printf("\n BFS - por nivel: "); mostrarArvorebfs(a); printf("\n");
	
//	a = inserir(a, 20);
//	a = inserir(a, 10);
//	a = inserir(a, 30);
    y = 10;		a = inserirRecursivo(a,y);  
	printf("\n BFS = por nivel:       "); 		mostrarArvorebfs(a); 	
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a); 
	printf("\n Red = pre-ordem:       "); 		mostrarArvore_Red(a);
	printf("\n edR = pos-ordem:       "); 		mostrarArvore_edR(a); 
	printf("\n\n");
	
    y = 190;	a = inserirRecursivo(a,y);
    printf("\n BFS = por nivel:       "); 		mostrarArvorebfs(a); 	
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a); 
	printf("\n Red = pre-ordem:       "); 		mostrarArvore_Red(a);
	printf("\n edR = pos-ordem:       "); 		mostrarArvore_edR(a); 
	printf("\n\n");
	
    y = 50; 	a = inserirRecursivo(a,y);
    printf("\n BFS = por nivel:       "); 		mostrarArvorebfs(a); 	
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a); 
	printf("\n Red = pre-ordem:       "); 		mostrarArvore_Red(a);
	printf("\n edR = pos-ordem:       "); 		mostrarArvore_edR(a); 
	printf("\n\n");
	
	y = 180;	a = inserirRecursivo(a,y);
    printf("\n BFS = por nivel:       "); 		mostrarArvorebfs(a); 	
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a); 
	printf("\n Red = pre-ordem:       "); 		mostrarArvore_Red(a);
	printf("\n edR = pos-ordem:       "); 		mostrarArvore_edR(a); 
	printf("\n\n");
	
	y = 40;		a = inserirRecursivo(a,y);
    printf("\n BFS = por nivel:       "); 		mostrarArvorebfs(a); 	
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a); 
	printf("\n Red = pre-ordem:       "); 		mostrarArvore_Red(a);
	printf("\n edR = pos-ordem:       "); 		mostrarArvore_edR(a); 
	printf("\n\n");
	
	y = 8;		a = inserirRecursivo(a,y);
    printf("\n BFS = por nivel:       "); 		mostrarArvorebfs(a); 	
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a); 
	printf("\n Red = pre-ordem:       "); 		mostrarArvore_Red(a);
	printf("\n edR = pos-ordem:       "); 		mostrarArvore_edR(a); 
	printf("\n\n");
	
	y = 200;	a = inserirRecursivo(a,y);			
	printf("\n BFS = por nivel:       "); 		mostrarArvorebfs(a); 	
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a); 
	printf("\n Red = pre-ordem:       "); 		mostrarArvore_Red(a);
	printf("\n edR = pos-ordem:       "); 		mostrarArvore_edR(a);
	
	y = 8;		a = buscaInsere(a,y);
    printf("\n BFS = por nivel:       "); 		mostrarArvorebfs(a); 	
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a); 
	printf("\n Red = pre-ordem:       "); 		mostrarArvore_Red(a);
	printf("\n edR = pos-ordem:       "); 		mostrarArvore_edR(a); 
	printf("\n\n");
	printf("\n\n");
	
	a = remover(a, 20);
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a); 

	
//	a = remover(a, 10);
//	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(a);*/

	No *ant = obterAnterior(a, 10);
	if(ant != NULL){
		printf("\n\n Anterior: %d\n\n", ant);
	}
	
	
	No *suc = obterSucessor(a, 190);
	
	if(suc != NULL){
		printf("\n\n Sucessor: %d\n\n", suc);
	}
	
	No *p = buscarABB(a, 8);
	printf("\n\n Buscado: %d\n\n", p);
	
	No *q = buscarABB(a, 10);
	printf("\n\n Buscado: %d\n\n", q);
	
	No *anc = obterAncestral(a, p, q);
	//if(anc != NULL){
		printf("\n\n Ancestral: %d\n\n", anc);
	//}
	
	mostrarPrimeiro(a);
	mostrarUltimo(a);
	
	No *primeiro = obterPrimeiro(a);
	printf("\n\n Primeiro: %d -> %d\n\n", primeiro, primeiro->chave);
	
	No *s = select(a, 1);
	printf("\n\n Select: %d -> %d \n\n", s, s->chave);
	
	int ordem = rank(a, 50);
	printf("\n\n Ordem: %d\n\n", ordem);
	
	printf("\n\n");
	nos = arvoreVetor(a);
	
	for(int i = 1; i < sizeof(nos); i++){
		printf(" %d ", nos[i]);
	}
	
	ABB teste;
	teste = vetorArvore(chaveNos);
	
	printf("\n\n");
	printf("\n BFS = por nivel:       "); 		mostrarArvorebfs(teste); 	
	printf("\n DFS = eRd (simetrico): ");		mostrarArvoreDFS(teste); 
	printf("\n Red = pre-ordem:       "); 		mostrarArvore_Red(teste);
	printf("\n edR = pos-ordem:       "); 		mostrarArvore_edR(teste); 
	printf("\n\n");
   	return 0;
}

// implementações das funções de No       
void mostrarNo(No *p){
    if (p != NULL){ printf("%5d",p->chave);}
    else printf("no inexistente \n\n");
}

              
// implementações das funções de ABB   
 
                 
ABB criarABB( ){
    ABB ap;
    ap = NULL;
    return ap;
}

void mostrarArvorebfs(ABB ap){
    No *p, *e, *d;
    Fila f;
    if (ap != NULL){
        p = ap;
        criarFilaVazia(&f);
        pushFila(&f,p);
        do {
        	p = acessarFila(&f); mostrarNo(p); 
			popFila(&f); e = p->esq; d = p->dir;
            if (e != NULL) pushFila(&f,e);     
            if (d != NULL) pushFila(&f,d);
        } while (verificarFilaVazia(&f) == FALSE);
    } else printf(" arvore vazia ");
}
     
void mostrarArvoreDFS(ABB ap){	// não recursivo
    Pilha s;  No *p;  bool fim;
    if (ap != NULL){
        criarPilhaVazia(&s); fim = FALSE; p = ap;    
        do {
            while (p != NULL){ pushPilha(&s,p);  p = p->esq; }
            if (verificarPilhaVazia(&s) == FALSE){
                p = acessarTopo(&s);  mostrarNo(p); 
	   			popPilha(&s);	p = p->dir;
            } else fim = TRUE;
        } while (fim == FALSE);
    }
}
 

void mostrarArvore_edR(ABB ap){ 	// varredura edR
	if (ap != NULL){
        mostrarArvore_edR(ap->esq);  
        mostrarArvore_edR(ap->dir);
        mostrarNo(ap);
	}      
}

void mostrarArvore_Red(ABB ap){	// varredura Red
	if (ap != NULL){
        mostrarNo(ap);
		mostrarArvore_Red(ap->esq);  
        mostrarArvore_Red(ap->dir);       
	}      
}		       

 
No* rodarEsq(No* p){
    No *y, *z;
    if (p != NULL){
    	y = p->dir; 
    	if (y != NULL){ 		
			z = y->esq;	
			p->dir = z;
			y->esq = p;
    		y->pai = p->pai; 
			p->pai = y;
    		if (z!=NULL) z->pai = p; 
		}
	}
    return y;
}

No* rodarDir(No* p){
    No* y, *z;
    if (p != NULL) {
    	y = p->esq; 
    	if(y != NULL) { 		
    		z = y->dir;
			p->esq = z;
			y->dir = p;
    		y->pai = p->pai;  
			p->pai = y;  
			if (z!=NULL) z->pai = p; 
    	}
    }
    return y; 
}

ABB inserirNo(ABB ap, int y){		// inserir sem rotações
	No *novo, *ant, *p;
	novo = (struct No*) malloc(sizeof(struct No));
    novo->chave = y; novo->pai = NULL;	novo->esq = NULL;  novo->dir = NULL;
	if (ap==NULL) {
		ap=novo;
	}
	else{
			p=ap;
			while (p!=NULL){
				ant = p; 
				if (y < p->chave) p = p->esq; else p = p->dir;
			}
			if (y < ant->chave)  ant->esq = novo;	else ant->dir = novo; 
			novo->pai = ant;
	}
    return ap;
}

ABB inserir(ABB ap, int y){			// insere e faz rotações para levar o item novo para a raiz
	No *novo, *p, *fa, *aux, *q;
	bool  FIM;
	FIM = FALSE;  
	
	novo = (struct No*) malloc(sizeof(struct No));
    novo->chave = y; novo->pai = NULL;	novo->esq = NULL;  novo->dir = NULL;
    printf("\n inserindo %d  \n",y);
    
	if (ap==NULL) ap=novo;
	else{
		p=ap;
		while (p!=NULL){
			q = p; 
			if (y < p->chave) p = p->esq; else p = p->dir;
		}
		if (y < q->chave)  q->esq = novo; else q->dir = novo;
		novo->pai = q;
		do{		 
		 	fa = q->pai;				
			if (y < q->chave) aux = rodarDir(q);	
 			else aux = rodarEsq(q);  
			
			if (fa==NULL) { ap = aux; FIM = TRUE; }
			else {
				if (q->chave < fa->chave) fa->esq = aux; else fa->dir = aux; 
				q = fa;
			}		
		}while (FIM == FALSE);
	}		
    return ap;	
}

No* obterAncestral(ABB ap, No* p, No* q){
	No *anc;
	if(ap == NULL) {
		anc = NULL;
	}else if(ap->chave == p->chave || ap->chave == q->chave) {
		anc = ap->pai;
	}
	else{
		if(p->chave < ap->chave && q->chave < ap->chave) {
			anc = obterAncestral(ap->esq, p, q);
		}
		else if (p->chave > ap->chave && q->chave > ap->chave){
			anc = obterAncestral(ap->dir, p , q);
		} else anc = ap;
	}
	return anc;
}

ABB removerRaiz(ABB ap){
	No *m, *ant, *p, *q;
	
	if(ap != NULL){
		if(ap->dir == NULL && ap->esq == NULL) {
			free(ap);
			p = NULL;
		}
		else if(ap->dir != NULL && ap->esq == NULL){
			q = ap->dir;
			ant = ap;
			free(ap);
			p = q;
			p->pai = NULL;
		}
		else{
			p = ap;
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
	return p;
}

No *buscarABB(ABB ap, int y){
	No *p;
	if(ap == NULL) p = NULL;
	else if(ap->chave == y) p = ap;
		else{
			if(y < ap->chave) p = buscarABB(ap->esq, y);
			else p = buscarABB(ap->dir, y);
		}
	return p;
}

ABB inserirRecursivo(ABB ap, int y){
	No *p, *novo;

	if(ap == NULL){
		novo = malloc(sizeof(No));
		novo->chave = y;
		novo->dir = NULL; novo->esq = NULL;
		novo->pai = NULL;
		ap = novo;
	}else{
		if(y < ap->chave) {
			p = inserirRecursivo(ap->esq, y);
			ap->esq = p;
			p->pai = ap;
		}
		else {
			p = inserirRecursivo(ap->dir, y);
			ap->dir = p;
			p->pai = ap;
		}
	}
	return ap;
}

No *obterAnterior(ABB ap, int y){
	No *p, *achou, *ant;
	Pilha s; int fim;
	if(ap == NULL) achou = NULL;
	else{
		p = ap;
		fim = FALSE;
		achou = NULL;
		ant = NULL;
		criarPilhaVazia(&s);
		do{
			while(p != NULL){ 
				pushPilha(&s, p);
				p = p->esq;
			}
			if(verificarPilhaVazia(&s) == FALSE){
				p = acessarTopo(&s);
				if(p->chave == y){
					achou = ant;
					fim = TRUE;
				}
				ant = p;
				popPilha(&s);
				p = p->dir;
			}else fim = TRUE;
		}while(fim == FALSE);
	}
	return achou;
}

void mostrarPrimeiro(ABB ap){
	No *p;
	if(ap != NULL){
		p = ap;
		while(p->esq != NULL) p = p->esq;
		printf("\n\n Primeiro: %d\n\n", p->chave);
	}
}

void mostrarUltimo(ABB ap){
	No *p;
	if(ap != NULL){
		p = ap;
		while(p->dir != NULL) p = p->dir;
		printf("\n\n Ultimo: %d\n\n", p->chave);
	}
}

No *obterPrimeiro(ABB ap){
	No *p;
	if(ap != NULL){
		p = ap;
		while(p->esq != NULL) p = p->esq;
	}else p = NULL;
	return p;
}

No *obterSucessor(ABB ap, int y){
	Pilha s;
	No *p, *suc, *ant;
	bool fim;
	if(ap == NULL) suc = NULL;
	else{
		p = ap; fim = FALSE;
		suc = NULL; ant = NULL;
		criarPilhaVazia(&s);
		do{
			while(p != NULL){
				pushPilha(&s, p);
				p = p->esq;
			}
			if(verificarPilhaVazia(&s) == FALSE){
				p = acessarTopo(&s);
				if(ant != NULL && ant->chave == y){
					suc = p;
					fim = TRUE;
				}
				ant = p;
				popPilha(&s);
				p = p->dir;
			}else fim = TRUE;
		}while(fim == FALSE);
	}
	return suc;
}

ABB buscaInsere(ABB ap, int y){
	No *p, *novo, *ant;
	if(ap != NULL){
		p = ap;
		//busca para ver se tem duplicata
		while(p != NULL && p->chave != y){
			ant = p;
			if(y < p->chave) p = p->esq;
			else p = p->dir;
		}
		if(p == NULL){ //nn achou duplicata
			novo = malloc(sizeof(No));
			novo->chave = y;
			novo->dir = NULL;
			novo->esq = NULL;
			if(novo->chave < ant->chave) ant->esq = novo;
			else ant->dir = novo;
			novo->pai = ant;
		}
	}else{
		novo = malloc(sizeof(No));
		novo->chave = y;
		novo->dir = NULL;
		novo->esq = NULL;
		novo->pai = NULL;
		ap = novo;
	}
	return ap;
}

No *select(ABB ap, int y){
	Pilha s; bool fim;
	int ordem = 0;
	No *p;
	p = ap;
	if(p != NULL){
		criarPilhaVazia(&s);
		fim = FALSE;
		do{
			while(p != NULL){
				pushPilha(&s, p);
				p = p->esq;
			}
			if(verificarPilhaVazia(&s) == FALSE){
				p = acessarTopo(&s);
				ordem++;
				if(ordem == y) fim = TRUE;
				else{
					popPilha(&s);
					p = p->dir;
				}
				
			}else fim = TRUE;
		}while(fim == FALSE);
	}
	return p;
}

int rank(ABB ap, int y){
	Pilha s;
	bool fim;
	No *p;
	int ordem = 0;
	if(ap != NULL){
		p = ap;
		criarPilhaVazia(&s);
		fim = FALSE;
		do{
			while(p != NULL){
				pushPilha(&s, p);
				p = p->esq;
			}
			if(verificarPilhaVazia(&s) == FALSE){
				p = acessarTopo(&s);
				ordem++;
				if(p->chave == y) fim = TRUE;
				popPilha(&s);
				p = p->dir;
			}else {
				fim = TRUE;
				ordem = 0;
			}
		}while(fim == FALSE);
	}
	return ordem;
}

ABB remover(ABB ap, int y){
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

int *arvoreVetor(ABB ap){
	No *p;
	bool fim;
	Pilha s;
	
	int tam = 0;
	
	if(ap != NULL){
		p = ap;
		fim = FALSE;
		criarPilhaVazia(&s);
		do{
			while(p != NULL){
				pushPilha(&s, p);
				p = p->esq;
			}
			if(verificarPilhaVazia(&s) == FALSE){
				p = acessarTopo(&s);
				tam++;
				v[tam] = p->chave;
				popPilha(&s);
				p = p->dir;
			}else fim = TRUE;
		}while(fim == FALSE);
	}
	return v;
}

ABB vetorArvore(int chaveNos[]){
	ABB a;
	a = criarABB();
	int meio = ((maxNos-1)/2);
	int esq = meio/2;
	int dir = meio + esq + 1;
	
	a = inserirNo(a, chaveNos[meio]);	
	a = inserirNo(a, chaveNos[esq]);
	a = inserirNo(a, chaveNos[dir]);	
	
	for(int i = 0; i < maxNos; i++){
		if(chaveNos[i] != chaveNos[meio] && chaveNos[i] != chaveNos[esq] && chaveNos[i] != chaveNos[dir]){
			a = inserirNo(a, chaveNos[i]);
		}
	}
	
	return a;
}
