#include <stdio.h>
#include <stdlib.h>
#include "tads/lista.c"

typedef struct{
	char *nome;
	Lista listaCompras;
	char *revista;
}Cliente;

int main(){
	puts("Bem vindo ao Supermercado Algorítmico!\n");
	int opcao;
	do{
		puts("O que você gostaria de fazer:\n");
		scanf("1. Adicionar Cliente\n2. Criar nova Lista de Compras\n3. Ir para a fila\n0. Sair\n",&opcao);
	}while(opcao != 0);
	return 0;
}
