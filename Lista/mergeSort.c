#include<stdio.h>
#define Max 1001
#define fantasma 36

typedef struct{
	int tam;
	int vetor[Max];
}Lista;

void mergeSort(Lista*, int, int);
void mostrarLista(Lista*);
void intercalar(Lista*, int, int, int);

int main(){
	Lista a;
	a.vetor[1] = 45;
	a.vetor[2] = 14;
	a.vetor[3] = 62;
	a.vetor[4] = 51;
	a.vetor[5] = 75;
	a.vetor[6] = 96;
	a.vetor[7] = 33;
	a.vetor[8] = 84;
	a.tam = 9;

	mergeSort(&a, 1, (a.tam-1));
	
	mostrarLista(&a);
}

void mergeSort(Lista* ap, int p, int r){
	int q;
	if(p < r){
		q = (p + r)/2;
		mergeSort(ap, p, q);
		mergeSort(ap, q+1, r);
		intercalar(ap, p, q, r);
	}
}

void intercalar(Lista* ap, int p, int q, int r){
	Lista aux;
	int j, k, e;
	printf("%d\n", j);
	
	for(int i = p; i <= r; i++){
		aux.vetor[i] = ap->vetor[i];
	}
	
	j = p;
	k = q+1;
	e = p;
	
	do{
		if(aux.vetor[j] <= aux.vetor[k]){
			ap->vetor[e] = aux.vetor[j];
			j++;
		}
		else{
			ap->vetor[e] = aux.vetor[k];
			k++;
		}
		
		e++;
	}while((j < q) || (k < r));
	
	if(j > q){
		for(int i = k; i <= r; i++){
			ap->vetor[e] = aux.vetor[i];
			e++;
		}
	}
	else{
		for(int i = j; i <= q; i++){
			ap->vetor[e] = aux.vetor[i];
			e++;
		}
	}
	
}

void mostrarLista(Lista* ap){
	for(int i = 1; i < ap->tam; i++){
		printf(" %d ", ap->vetor[i]);
	}
}
