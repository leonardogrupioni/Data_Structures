#include<stdio.h>
#define Max 1001
#define fantasma 36

typedef struct{
	int tam;
	int vetor[Max];
}Lista;

void quickSort(Lista*, int, int);
int separarLista(Lista*, int, int);
void trocar(Lista*, int, int);
void mostrarLista(Lista*);

int main(){
	Lista a;
	a.vetor[1] = 10;
	a.vetor[2] = 30;
	a.vetor[3] = 40;
	a.vetor[4] = 60;
	a.vetor[5] = 50;
	a.tam = 6;
	
	quickSort(&a, 1, (a.tam-1));
	//separarLista(&a, 1, (a.tam-1));
	mostrarLista(&a);
}

void quickSort(Lista* ap, int p, int r){
	int j;
	printf("p: %d e r: %d\n\n", p, r);
	if(p < r){
		j = separarLista(ap, p ,r);
		printf("j quick: %d e j-1 = %d\n", j, j-1);
		printf("r: %d\n", r);
		quickSort(ap, p, j-1);
		printf("segundo quick, j+1: %d\n", j+1);
		printf("r: %d\n", r);
		quickSort(ap, j+1, r);
		
		printf("acabou\n");
	}
}

int separarLista(Lista* ap, int p, int r){
	int i, j, pivo;
	printf("p: %d, r: %d\n", p, r);
	i = p;
	j = r + 1;
	pivo = ap->vetor[p];
	
	printf("i: %d, j: %d, pivo: %d\n", i, j, pivo);
	printf("\nloop\n");
	while(i < j){
		
		do{
			i++;
		}while((ap->vetor[i] < pivo) && (i < j));
		
		printf("i: %d\n", i);
		
		do{
			j--;
		}while(ap->vetor[j] > pivo);
		
		printf("j: %d\n");
		
		if(i < j) trocar(ap, i, j);
	}
	
	trocar(ap, p, j);
	return j;
}

void trocar(Lista* ap, int i, int j){
	int aux;
	
	printf("\ntrocar\n");
	printf("%d   %d\n", ap->vetor[i], ap->vetor[j]);
	aux = ap->vetor[i];
	ap->vetor[i] = ap->vetor[j];
	ap->vetor[j] = aux;
}

void mostrarLista(Lista* ap){
	for(int i = 1; i < ap->tam; i++){
		printf(" %d ", ap->vetor[i]);
	}
}
