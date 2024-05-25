/*  Exemplo de medição de tempo de execução 
  Arquivo: ordenarLista.c
  Autor: Leonardo Grupioni
  Date: 10/02/09 09:01
  Descrição: Este programa implementa algoritmos elementares 
  de ordenação.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define Max 21

typedef struct {
      int tamanho;
      int Tabela[Max];
} Lista;

//interface

Lista criarListaAleatoria(int, int, int);

void mostrarLista(Lista);

void ordenarListaCrescenteB(Lista *);	// bubbleSort
void ordenarListaCrescenteS(Lista *);	// selectionSort
void ordenarListaCrescenteI(Lista *);	// insertionSort



int main(){
	Lista L1;
	clock_t start, finish;
	double pf;
	
	printf(" \n\n\nConstruir uma lista com inteiros na faixa 100..999 \n\n");
    L1 = criarListaAleatoria(Max-1,100,999);
    mostrarLista(L1); printf(" \n\n");    
	  
	printf(" executando SelectionSort ... ");
	
	start = clock(); 
	ordenarListaCrescenteS(&L1);
	finish = clock();

    pf = (double)(finish - start)/CLOCKS_PER_SEC;  printf("    elapsed = %f segundos ",pf);

	printf(" \n\n\n"); mostrarLista(L1);  printf(" \n\n");
	
   	printf("\n\nfim");
   	return 0;
}


// implementação

Lista criarListaAleatoria(int N, int a, int b){
	Lista L;
	int i,k,g,tam;
    double d;
	if (N>=Max) tam = Max-1; else tam = N; 
  	srand((int) time(NULL)); 	//semente obtida pelo relógio do sistema
	L.tamanho = tam;
    for(i=1; i<=tam; i++){  	
       d = (double)rand()/((double)RAND_MAX +1);
       k = (int)(d*(b-a+1));
       g = a+k;
       L.Tabela[i] = g;
    };
	return L;
}

Lista criarListaVazia(){
	Lista L;
	L.tamanho = 0;
	return L;
}

void mostrarLista(Lista A){
     int n,i,cont;
     n = A.tamanho;
     if(n==0)printf("\n lista vazia\n");
     else{
     	printf("\n n = %d \n", n);
        cont = 0;
		for(i=1;i<=n;i++){ 
			printf(" %d ",A.Tabela[i]);
			cont++;
			if (cont == 5) {printf("\n");cont = 0;}
		}
        printf("\n");
     }
}


void ordenarListaCrescenteB(Lista *ap){      /* BubbleSort: trocar pares consecutivos fora da ordem */
     int i,j,fim,n,aux;
     n = ap->tamanho;                           /* n = quantidade de elementos da lista */
     fim = n-1;
     for(i=1;i<n;i++){                          /* n-1 etapas  */
        for(j=1;j<=fim; j++){                   /* comparar/trocar do primeiro ao penultimo */
            if (ap->Tabela[j] > ap->Tabela[j+1]){
                 aux = ap->Tabela[j]; ap->Tabela[j] = ap->Tabela[j+1]; ap->Tabela[j+1] = aux;
            };
        }
        fim = fim -1;
     }
}


void ordenarListaCrescenteS(Lista *ap){      /* SelectionSort: localizar o menor e colocar no seu lugar */
     int i,j,min,n,aux;
     n = ap->tamanho;                           /* n = quantidade de elementos da lista */
     for(i=1;i<n;i++){                          /* n-1 etapas  */
         min = i;                                                                  /* min = local onde se encontra o menor */
         for(j=i+1;j<=n; j++) if (ap->Tabela[j] < ap->Tabela[min]) min = j;          /* atualização de min */
         aux = ap->Tabela[i]; ap->Tabela[i] = ap->Tabela[min]; ap->Tabela[min] = aux;   /* troca com o menor */
     }
}


void ordenarListaCrescenteI(Lista *ap){      /* InsertionSort - ordenação por inserção */
     int i,k,n,aux;
     n = ap->tamanho;                           /* n = quantidade de elementos da lista */
     for(i=2;i<=n;i++){                         /* n-1 etapas  */
         aux = ap->Tabela[i];
         k = i-1;
         while ((k>0) && (ap->Tabela[k] > aux)) {ap->Tabela[k+1] = ap->Tabela[k]; k = k - 1;}  /* desloca */
         ap->Tabela[k+1] = aux;                                                              /* insere  */
         }
     }
