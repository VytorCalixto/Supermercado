#include <stdio.h>
#include <stdlib.h>
#include "tads/lista.c"
#include "logger/logger.c"

typedef struct{
	char *nome;
	Lista listaCompras;
	char *revista;
}Cliente;

void main(){
	Logger logger;
	startLogger(&logger, "log.txt");
	puts("Bem vindo ao Supermercado Algorítmico!\n");
	int opcao;
	do{
		puts("O que você gostaria de fazer:\n");
		puts("1. Adicionar Cliente\n2. Criar nova Lista de Compras\n3. Ir para a fila\n0. Sair\n");
		scanf("%d",&opcao);
	}while(opcao != 0);
	endLogger(&logger);
	return;
}
