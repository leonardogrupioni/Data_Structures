/* Hashing - cálculo de algumas funções 
  Arquivo: FUNCA0_HASH.c
  Autor: Leonardo Grupioni
  Date: 22/09/09 09:40
  Descrição: Exemplo de cálculos de função hash.             
*/

#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"


# define hash(k,M) (k % M)   // aqui está definida uma função hash
# define max 9
# define max4 7

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
   	//unsigned char L[max] = {44,46,49,70,27,71,90,97,95};
   	unsigned char B[max4] = {71,44,60,65,29,51,35};
	
	M = 7;
   	for (j=0;j<max4;j++){
		key = B[j];
		hC4 = h4(key,M);
		printf("\n  %4d   %4d", key, hC4);
   	}
    
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
	hc = (k % M) + 1;
	return hc;
}


int hQ(int k, int M){
	int hc;
	long long int y = k * k;
	
	
	return hc;
}
