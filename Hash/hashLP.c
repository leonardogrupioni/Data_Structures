/* tratamento de colisão - endereçamento aberto */
/*
  Arquivo: hashLP.c
  Autor: Leonardo Grupioni
  Date: 26/01/21 14:53
  Descrição: Exemplo de tratamento de colisão por 
             endereçamento aberto
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"
#define max 128
#define maxH 71
#define NULLItem "FUBA"

typedef char* string;
typedef struct{
	bool OCC;
	string RA;
 	string NOME;
}Item;

typedef Item TabelaH[maxH];

unsigned char hash(char*);
void inicializarDic(TabelaH);
void mostrarDic(TabelaH);

int main(){
	TabelaH Aluno;
    char* nome;
    char* chave;
    unsigned char codigo;
    int i;
    
	char* LISTA[max] = {"RA00320429","Breno Rodrigues Souza","RA00320039","Bruno dos Santos Torres Novo","RA00318945","Caio Pereira Guimarães","RA00301497","Davi Augusto Palhano Barbosa",
"RA00323309","Diogo Filipe Pereira Lopes de Napolis","RA00319173","Felipe Farinelli Itri","RA00318885","Filipi Mantelato Goncalves","RA00307367","Gabriel Cabral Costa",
"RA00325868","Gabriel Carlos Silva","RA00297625","Gabriel Cavalcanti Francisco","RA00227270","Gabriel de Moraes Monteiro Zaninotti","RA00321554","Gabriel Jose da Silva",
"RA00319564","Gabriel Leitao Odakura Silva","RA00318850","Giovana Akemi Maeda Mathias","RA00325934","Gustavo Bertolini Carvalho de Castro","RA00324057","Jefferson da Silva de Souza",
"RA00297597","Joao Antonio Malheiros Barbosa","RA00324063","Joao Augusto Carrascoza","RA00275231","Joao Murilo de Amorim Mariano Santos","RA00319514","Joao Pedro do Carmo Ribeiro",
"RA00320589","Joao Pedro Grinover Borgneth","RA00311253","Julia Marques de Castro","RA00301492","Leonardo Souza Silva","RA00318828","Lucas Kenji Hayashi",
"RA00321538","Lucas Lombardi de Brito","RA00325647","Matheus Ferreira dos Santos Silvestre","RA00321715","Murilo Bonventi Romani Pinto","RA00318693","Pedro Franca de Godoi",
"RA00318728","Pedro Marques Prado","RA00325920","Rafael Santos Sakatauskas","RA00323973","Thiago Amaral de Oliveira","RA00297765","Victor Castaldini Bitchatcho",
"RA00178198","Vinicius do Nascimento Silva","RA00321629","André Cavalcanti Teles dos Santos","RA00319228","Anne Yumi Kagawa","RA00319192","Beatriz Lopes Rizzo",
"RA00325161","Cinthia Alves Barreto","RA00319777","David Mendes Saldanha de Miranda","RA00320015","Felipe Carvalho Paleari","RA00319488","Felipe Casagrande Espel",
"RA00320191","Gabriel Souza de Carvalho","RA00319543","Guilherme Diniz Leocadio","RA00321528","Gustavo Leite Ioels","RA00325498","Igor Matos Gaeta","RA00320301",
"Isabel Cavalcante Motta","RA00319673","Isabella Rubio Venancio","RA00321617","Joao Marcos Ribeirete Garbelini","RA00319987","Joao Pedro Basso Coura",
"RA00320412","Joao Pedro de Souza Oliveira","RA00319473","Joao Pedro Figols Neco","RA00319869","Joao Victor Espanholi França","RA00319540","Júlia Gachido Schmidt",
"RA00321630","Kaiky Kenji Yasuhara Scudeler","RA00319703","Leonardo Fajardo Grupioni","RA00319421","Lucas Cassolino D Azevedo","RA00320062","Mateus Araujo de Melo Morais",
"RA00318954","Mateus Neves Erédia","RA00321605","Pedro Henrique da Costa Manso Saraiva","RA00320302","Rebecca Grazioli Garofalo Viola","RA00320178","Rodrigo Poinha Romero",
"RA00227265","Steven She Cheng Wang","RA00320481","Thaiza Vitória Silva Mello","RA00319415","Victoria Isabell Ferrarese de Lima","RA00320255","Vitor Assuncao Silva"};
				
    printf("\n\n");
	for(i=0;i<=64;i=i+2){
    	chave = LISTA[i]; nome = LISTA[i+1];  printf(" %11s - %11s \n",chave,nome); 	
    }
  
	chave = LISTA[0];
	codigo = hash(chave);  printf(" \n  chave = %s  hashcode = %d  ",chave,codigo);  
	
	printf("\n\n");
	inicializarDic(Aluno);
	mostrarDic(Aluno);
  
	printf("\n fim\n");   
    return 0;
}

unsigned char hash(char* P){
	unsigned char hcode;
	hcode = 99;
	return hcode;
}

void inicializarDic(TabelaH Aluno){
	for(int i = 0; i < maxH; i++){
		Aluno[i].OCC = FALSE;
	}
}

void mostrarDic(TabelaH Aluno){
	for(int i = 0; i < maxH; i++){
		printf("%d: %d\n", i, Aluno[i].OCC);
	}
}