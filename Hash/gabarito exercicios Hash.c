/* Hashing - cálculo de algumas funções 
  Arquivo: FUNCA0_HASH.c
  Autor: Lisbete Madsen Barbosa
  Date: 22/09/09 09:40
  Descrição: Exemplo de cálculos de função hash.             
*/

#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"


# define hash(k,M) (k % M)   // aqui está definida uma função hash
# define max 9
# define max4 13

typedef unsigned char TipoChave;

int h1(TipoChave,int);
int h2(TipoChave,int);
int h3(TipoChave,int);
int h4(TipoChave,int);
int hQ(int, int);

int main (){
   	int j;
   	int M, k,hC1, hC2, hC3,hC4,hC;
   	TipoChave key;
   	unsigned char L[max] = {44,46,49,70,27,71,90,97,95};
   	unsigned char B[max4] = {17,26,41, 44,46,55, 68,71,97, 118,121,182, 242};
   
   
   	M = 23;
   	printf("\n\n  Lista L \n");
   	printf("  chave     h1   h2   h3");
   	for (j=0;j<max; j++){
		key = L[j];
		hC1 = h1(key,M);	hC2 = h2(key,M);    hC3 = h3(key,M);
		printf("\n  %4d   %4d %4d %4d ", key, hC1,hC2,hC3);
	}
    
	
	printf("\n\n Lista B hash h4 M = 11\n ");
	printf(" chave     h4");
   	M = 11;
   	for (j=0;j<max4; j++){
		key = B[j];
		hC4 = h4(key,M);
		printf("\n  %4d   %4d", key, hC4);
   	}	
    
	
	printf("\n\n Lista B hash M = 13 \n");
	printf(" chave    hash");
   	M = 13;
    for (j=0;j<max4; j++){
		k = B[j];
		hC = hash(k,M);
		printf("\n  %4d   %4d", k, hC);
   	}	
   	
   	printf("\n\n");
   	hQ(19540, 53);
    
	printf("\n");
    printf("\n");
    return 0;
}


int h1(TipoChave k,int M){
	int hc;
	hc = k % M;
	return hc;
}


int h2(TipoChave k,int M){
	int hc;
	double alfa = 0.61803;
	hc = (int) (alfa * k) % M;
	return hc;
}


int h3(TipoChave k,int M){
	int hc, q, aux;
	q = k * k;
	aux = q/100;
	hc = (q - aux * 100) % M;
	return hc;
}

int h4(TipoChave k,int M){
	int hc;
	hc = (k % 3 + 1);
	return hc;
}

int hQ(int k, int M){
	int hc;
	long long int y = k * k;
	
	
	return hc;
}
