#include <stdio.h>
#include <stdlib.h>
#include "tads/lista.h"
#include "tads/pilha.c"
#include "logger/logger.c"

typedef struct{
	char *nome;
	Lista listaCompras;
	char *revista;
}Cliente;

#define TIPO Cliente
#include "tads/fila.h"
#undef TIPO

void adicionarCliente(Fila *fila);

void main(){
	Logger logger;
	startLogger(&logger, "log.txt");

	puts("Bem vindo ao Supermercado Algorítmico!\n");
	int opcao;

	Fila filaClientes;
	iniciaFila(&filaClientes);
	Pilha pilhaRevistas;
	//iniciarPilha(&pilhaRevistas);

	do{
		puts("O que você gostaria de fazer:");
		puts("1. Adicionar Cliente a fila\n2. Criar nova Lista de Compras\n3. Ir para a fila\n0. Sair");
		scanf("%d",&opcao);

		if(opcao == 1){
			adicionarCliente(&filaClientes);
		}else if(opcao == 2){

		}else if(opcao == 3){

		}else if(opcao == 4){

		}else if(opcao != 0){
			puts("ERRO: opcao invalida.");
		}
	}while(opcao != 0);
	endLogger(&logger);
	return;
}

void adicionarCliente(Fila *fila){
	char *nome;
	puts("Qual o nome do cliente?");
	//FIXME: Nome do cliente ñ tah salvando, print retorna null (Segmentation Fault)
	scanf("%s", &nome);
	printf("%s\n",&nome);
	Cliente cliente;
	cliente.nome = nome;

	enfileira(cliente, fila);
}
