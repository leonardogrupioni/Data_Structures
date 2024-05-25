#include<stdio.h>
#include<String.h>
#include "Booleano.h"
#define Max 10

bool ordenada(char*, int);
int maior(char*, int);

int main(){
	int n, i, k, j, antes, ind;
	bool estado;
	char y;
	unsigned char linha[Max];
	unsigned char aux[1];
	FILE *entrada;
	
	entrada = fopen("panqueca.txt", "r");
	
	if(entrada == NULL){
		printf("\n\nArquivo nao encontrado\n\n");
	}
	else{
		//do{
			while(fscanf(entrada, "%s", linha) == 1){
				n = strlen(linha);
				antes = n;
			}
			
			ind = maior(linha, n);
			
			if(ind == n-1){
				n--;
			}
			else{
				for(i = ind; i > 0; i--){
					printf("i: %d\n", i);
					printf("linha = %c\n", linha[i]);
					aux[j] = linha[i];
					j++;
				}
				
				for(i = 0; i <= ind; i++){
					printf("aux = %c\n", aux[i]);
				}
				
				i = 0;
				j = ind;
				while(j >= 0 && i <= ind){
					printf("j: %d e aux = %c\n", j, aux[j]);
					linha[i] = aux[j];
					j--;
					i++;
				}
			}
			
			estado = ordenada(linha, n);
		//}while(estado != TRUE);
		
		for(i = 0; i < antes; i++){
			printf("linha = %c\n", linha[i]);
		}
	}
}


bool ordenada(char* linha, int n){
	int i = 0;
	bool estado;
	int count = 0;
	for(i = 0; i < n; i++){
		if(linha[i] < linha[i+1]){
			count++;
		}
	}

	if(count == n){
		return TRUE;
	}
	
	return FALSE;
}

int maior(char* linha, int n){
	char maior = linha[1];
	int i;
	int ind = 1;
	for(i = 2; i < n; i++){
		if(maior < linha[i]){
			maior = linha[i];
			ind = i;
		}
	}
	
	return ind;	
}
