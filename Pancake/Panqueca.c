#include<stdio.h>
#include "Booleano.h"
#define Max 10

bool ordenada(char*, int);
int maior(char*, int);

int main(){
	int n, i, k, j, antes;
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
		do{
			while(fscanf(entrada, "%s", linha) == 1){
				n = strlen(linha);
				antes = n;
			}
		
			i = 1;
		
			while(linha[i] < linha[i+1] && i < n){
				i++;
			}
		
			if(linha[i-1] < linha[i]){
				//armazena de 0 a i em um outro array
				k = i+1;
				for(i = 0; i < k; i++){
					aux[j] = linha[i];
					j++;
				}	
				printf("if\n\n");
				i = 0;
				while(j > 0 && i < k){
					j--;
					linha[i] = aux[j];
					i++;
				}
			}
			
			for(i = 0; i < antes; i++){
				printf("linha = %c\n", linha[i]);
			}
			
			int ind = maior(linha, n);
			
			if(ind == n-1){
				n--;
			}
			printf("depois maior\n\n");
			estado = ordenada(linha, n);
			printf("estado\n\n");
		}while(estado != TRUE);
		
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
	char maior = linha[0];
	int i;
	int ind = 0;
	for(i = 1; i < n; i++){
		if(maior < linha[i]){
			maior = linha[i];
			ind = i;
		}
	}
	
	return ind;	
}
