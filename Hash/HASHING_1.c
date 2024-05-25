/* FUNÇÃO HASH */
/*
  Arquivo: HASHING_1.c
  Autor: Lisbete Madsen Barbosa
  Date: 26/01/21 14:53
  Descrição: FUNÇÃO HASH
*/

#include <string.h>
#include <stdio.h>
#define max 41

int hash1(char*);

int main(){
    char* nome;
    int codigo;
    int i;
	char* LISTA[max] = {"ALICE","BRENO","BRUNO","CAIO","DAVI","DIOGO",
		 				"FELIPE","FILIPI","GABRIEL","GIOVANA","GUSTAVO","JEFFERSON",
		 				"JOAO","JULIA","LEONARDO","LUCAS","MURILO","PEDRO",
		 				"RAFAEL","RICARDO","THIAGO","VICTOR","VINICIUS","ANDRE",
		 				"ANNE","ARTUR","BEATRIZ","CINTHIA","DAVID","GUILHERME",
		 				"IGOR","ISABEL","ISABELLA","KAIKY","LUCAS","MATEUS",
		 				"REBECCA","RODRIGO","STEVEN","THAIZA","VICTORIA"};  
		 				
//44   char* LISTA[max] = {"ARTHUR","ARTUR","BRUNO","CAIO","CESAR","CONSTANTINOS",
//	                    "DAVI","DIEGO","EDUARDO","GABRIEL","GIOVANNA","GUILHERME",
//                        "GUSTAVO","HENRY","IGOR","JOAO","JOISON","JONAS",
//						"JUAN","JULIO","LEONARDO","LUAN","LUCAS","LUCCA",
//						"LUIS","MARCO","MATEUS","MIGUEL","MURILO","NATALIA",
//						"PAULO","PEDRO","PIETRO","RAFAEL","RICARDO","RODRIGO",
//						"SERGIO","THIAGO","TIAGO","VICTOR","VINICIUS","VITOR",
//						"YGOR","YUCAI"};
// 47    char* LISTA[max] = {"ALLAN","ANA","ANDRE","ARTHUR","CAIO","CARLOS",
//						"CAROLINE","CESAR","DANIEL","DIOGO","EMILI","ENZO",
//						"FELIPE","GIOVANA","GUILHERME","GUSTAVO","HANNAH","HELIO",
//						"IGOR","ISABELA","ISADORA","JOAO","JOSE","JUAN",
//						"JULIANA","KAUA","LEONARDO","LORENA","LORENZA","LUAN",
//						"LUCAS","LUIS","MANOELA","MARIA","MATHEUS","MORGANA",
//						"MURILLO","NICOLAS","PALOMA","PEDRO","PRISCILLA","RAFAEL",
//						"RAUL","RUBENS","SABRINA","VICENTE","VICTOR"};
					
    for(i=0;i<max;i++){
    	nome = LISTA[i];  printf("%11s",nome) ;
        //codigo = hash1(nome);
        //codigo = hash2(nome);
        codigo = hash3(nome);
		printf(" %4d\n",codigo);	
    }
    printf("\n");

	nome = "ABA";
  	printf("%11s",nome) ;
    //codigo = hash1(nome);
    codigo = hash3(nome);
    printf(" %4d\n",codigo);	
	printf("\n fim\n");   
    return 0;
}

int hash1(char* nome){
	int code = 0;
	int j = 0;
	int m = 37;
	int n = strlen(nome);
	
	while(n > j){
		code = code + nome[j];
		j++;
	}
	
	code = code % m;
	
	return code;
}

int hash2(char* nome){
	int code = 0;
	int i = 0;
	int j = 1;
	int m = 37;
	int n = strlen(nome);
	
	while(n > i){
		code = code + (nome[i]*j);
		j++;
		i++;
	}
	
	code = code % m;
	
	return code;
}

int hash3(char* nome){
	long long int code = 0;
	int exp = 0;
	int i = 0;
	int j = 1;
	int m = 37;
	int n = strlen(nome);
	
	while(n > i){
		exp = n-j;
		int sent = 0;
		long long int pot = 1;
		while(sent < exp){
			pot = pot * 128;
			sent++;
		}
		code = code + (nome[i]*pot);
		j++;
		i++;
	}
	
	code = code % m;
	
	return code;
}

