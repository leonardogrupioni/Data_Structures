/* TAD ListaP */
/*
  Arquivo: teste ListaP.c
  Autor: Leonardo Grupioni
  Date: 09/09/13 13:17
  Descrição: Implementa o tipo ListaP.
*/

#include<stdio.h>
#include "Booleano.h"
#define fantasma 36
#define Max 30
#define sinal -99

typedef struct {
        int tam;
        unsigned char vetor[Max];
} ListaP;

//Interface
    ListaP newLista();           				// criar uma lista vazia [0]
    unsigned char acessarLista(ListaP, int);	// 				

    ListaP appendLista(ListaP,unsigned char);       // inserir um item no final da lista		
    ListaP clearLista(ListaP);						//	
    ListaP copyLista(ListaP);						// 
    int countLista(ListaP, unsigned char);			// 
    ListaP extendLista(ListaP, ListaP);						//  
    int indexLista(ListaP,unsigned char);			//  
    ListaP insertLista(ListaP, unsigned char, int);	// 
    int lenLista(ListaP);                   		// obter o tamanho da lista	  
    unsigned char maxLista(ListaP);					// 
    unsigned char minLista(ListaP);					// 
    ListaP popLista(ListaP, int);					//
    ListaP removeLista(ListaP, unsigned char);		// 
    ListaP reverseLista(ListaP);					// 
    ListaP sortLista(ListaP);						// 
   
    unsigned char acessarLista(ListaP, int);   // obter o item de ordem k		
    void mostrarLista(ListaP);                  // está pronta
    ListaP construirLista(int);             	// está pronta  
	ListaP construirListaAleatoria(int);  	
 
int main(){
	int qtd,local,k;
	unsigned char letra;
	ListaP L1;	L1 = newLista(L1);  //mostrarLista(L1);
	ListaP L2;  L2 = newLista(L2);  //mostrarLista(L2);
	ListaP L3;  L3 = newLista(L3);
	printf("\n--------------ListaL1----------------\n");
	L1 = construirLista(3);	mostrarLista(L1);
	printf("\n--------------ListaL3----------------\n");
	L3 = construirListaAleatoria(4); mostrarLista(L3);
	printf("\n--------------sortListaL3----------------\n");
	L3 = sortLista(L3); mostrarLista(L3);
	printf("\n--------------extendListaL1L3----------------\n");
	L1 = extendLista(L1, L3); mostrarLista(L1);
	printf("\n--------------sortListaL1----------------\n");
	L1 = sortLista(L1); mostrarLista(L1);
	printf("\n--------------appendListaL1----------------\n");
	L1 = appendLista(L1,'Z');  mostrarLista(L1);
	printf("\n--------------insertListaL1----------------\n");
	L1 = insertLista(L1, 'D', 3);  mostrarLista(L1);
	printf("\n");
	int tam = lenLista(L1);
	printf("O tamanho eh: %d\n", tam);
	printf("\n--------------copyListaL2----------------\n");
	L2 = copyLista(L1);  mostrarLista(L2);
	printf("\n--------------maxListaL1----------------\n");
	char maior = maxLista(L1); printf("\n maior = %c ", maior);
	printf("\n--------------minListaL1----------------\n");
	char menor = minLista(L1); printf("\n menor = %c ", menor);
	printf("\n--------------reverseListaL1----------------\n");
	L1 = reverseLista(L1);  mostrarLista(L1);
	printf("\n--------------popListaL1----------------\n");
	L1 = popLista(L1, 2);  mostrarLista(L1);
	printf("\n--------------removeListaL2----------------\n");
	L2 = removeLista(L2, 'B');  mostrarLista(L2);
	printf("\n--------------reverseListaL2----------------\n");
	L2 = reverseLista(L2);  mostrarLista(L2);
	letra = 68;
	qtd = countLista(L1,letra);  printf("\n qtd de letra %c = %d ",letra, qtd);
	local = indexLista(L1,letra);   printf("\n indice letra %c = %d ",letra, local);
	k=2;
	letra = acessarLista(L1,k);
	printf("\n letra = %c \n\n",letra);
	L1 = clearLista(L1);  mostrarLista(L1);
	printf("\n fim ");
	return 0;
}
 
 		
//Implementações

ListaP newLista(){
	ListaP L;
	L.tam = 0;
    return L;    
}

ListaP construirLista(int n){
        ListaP listaA;
        int i,t;
        if(n == 0){
        	listaA.tam = n;	
		}  
        else {
            if((n > 0) && (n <= Max)){
            	t = n;
			}  
            else{
            	t = Max;	
			}
            listaA.tam = t;
            for(i = 0; i < t; i++){
            	listaA.vetor[i] = 65+i;
			}
        }
        return listaA;
}

unsigned char acessarLista(ListaP L, int k){
	int p = L.tam;  //p = 3
	char c;
	if(k < p || k > (p * (-1))){
		if(k > 0){
			c = L.vetor[k];
		}
		else{
			p = L.tam - 1;
			c = L.vetor[p+k];
		}
	}
	else{
		c = fantasma;
	}
	return c;
}

bool verificarListaVazia(ListaP L){
	bool estado;
	if(L.tam == 0){
		estado = TRUE;
	}
	else{
		estado = FALSE;
	}
	
	return estado;
}

void mostrarLista(ListaP s1){
	int k;
	if(s1.tam == 0){
		printf("\nLista Vazia\n");
	}
	else{
		for(k = 0; k < s1.tam; k++){
			printf("\t %c\n", s1.vetor[k]);
		}
	}
}

ListaP clearLista(ListaP L){
	L.tam = 0;
	return L;
}

ListaP copyLista(ListaP L){
	ListaP A;
	int i;
	int n = L.tam;
	A.tam = n;
	for(i = 0; i < n; i++){
		A.vetor[i] = L.vetor[i];
	}
	
	return A;
}

int indexLista(ListaP L, unsigned char ch){
	int i = 0;
	int ind = 0;
	
	while(ch != L.vetor[i] && i < L.tam){
		i++;
	}
	if(ch == L.vetor[i]){
		ind = i;
	}
	else{
		ind = fantasma;
	}
	
	return ind;
}

int lenLista(ListaP L){
	int tam = L.tam;
	return tam;
}

int countLista(ListaP L, unsigned char ch){
	int i;
	int n = L.tam;
	int count = 0;
	for(i = 0; i < n; i++){
		if(L.vetor[i] == ch){
			count++;
		}
	}
	
	return count;
}

ListaP appendLista(ListaP L,unsigned char y){
	if(L.tam < Max-1){
		L.vetor[L.tam] = y;
		L.tam++;
	}
	
	return L;
}

ListaP insertLista(ListaP L, unsigned char y, int k){
	int i;
	if(k < L.tam && k >= 0){
		for(i = L.tam; i > k; i--){
			L.vetor[i] = L.vetor[i-1];
		}
//		for(i = L.tam-1; i >= k; i--){
//			L.vetor[i+1] = L.vetor[i];
//		}
	}
	L.vetor[k] = y;
	L.tam++;
	return L;
}

unsigned char maxLista(ListaP L){
	char maior;
	int i;
	maior = L.vetor[0];
	for(i = 1; i < L.tam; i++){
		if(maior < L.vetor[i]){
			maior = L.vetor[i];
		}
	}
	return maior;
}

unsigned char minLista(ListaP L){
	char menor;
	int i;
	menor = L.vetor[0];
	for(i = 1; i < L.tam; i++){
		if(L.vetor[i] < menor){
			menor = L.vetor[i];
		}
	}
	return menor;
}

ListaP popLista(ListaP L, int k){
	int i;
	if(k >= 0 && k < L.tam){
		for(i = k; i < L.tam; i++){
			L.vetor[i] = L.vetor[i+1];
		}
//		for(i = k+1; i < L.tam; i++){
//			L.vetor[i-1] = L.vetor[i];
//		}
		L.tam--;
	}
	return L;
}

ListaP removeLista(ListaP L, unsigned char y){
	int i = 0;
	int k;
	while(L.vetor[i] != y && i < L.tam){
		i++;
	}
	if(L.vetor[i] == y){
		int n = i;
		for(k = n; k < L.tam; k++){
			L.vetor[k] = L.vetor[k+1];
		}
//		for(k = i+1; k < L.tam; k++){
//			L.vetor[k-1] = L.vetor[k];
//		}
		L.tam--;
	}
	return L;
}

ListaP reverseLista(ListaP L){
	int meio = L.tam/2;
	int n = L.tam-1;
	int k;
	char aux;
	//if(L.tam%2 == 0){
		for(k = 0; k < meio; k++){
			aux = L.vetor[k];
			L.vetor[k] = L.vetor[n];
			L.vetor[n] = aux;
			n--;
		}
	//}
	//else{
	//	for(k = 0; k < meio; k++){
	//		aux = L.vetor[k];
	//		L.vetor[k] = L.vetor[n];
	//		L.vetor[n] = aux;
	//		n--;
	//	}
	//}
	return L;
}

ListaP construirListaAleatoria(int tam){
	ListaP L;
	int y;
	int k;
	if(tam < Max){
		srand(time(NULL));
		L.tam = tam;
		for(k = 0; k < L.tam; k++){
			y = 65 + (rand() % 26);
			L.vetor[k] = (char) y;
		}
	}
	return L;
}

ListaP sortLista(ListaP L){
	int i, k;
	unsigned char aux;
	int n = L.tam;
	int fim = L.tam - 1;
	for(i = 1; i < n; i++){
		for(k = 0; k < fim; k++){
			if(L.vetor[k] > L.vetor[k+1]){
				aux = L.vetor[k];
				L.vetor[k] = L.vetor[k+1];
				L.vetor[k+1] = aux;
			}
		}
	}

	return L;	
}

ListaP extendLista(ListaP A, ListaP B){
	int n = A.tam;
	int k;
	A.tam = A.tam + B.tam;
	if(B.tam != sinal){
		for(k = 0; k < B.tam; k++){
			A.vetor[n] = B.vetor[k];
			n++;
		}
	}
	
	return A;
}
