#include <stdio.h>
#include <stdlib.h>
#include "tads/lista.h"
#include "logger/logger.c"

typedef struct{
	char *nome;
	Lista listaCompras;
	char *revista;
}Cliente;

Logger logger; //logger precisa ser global

#define TIPO Cliente
#include "tads/fila.h"
#undef TIPO

#define TAM_MAX	2000
#include "tads/pilha.h"
#undef TAM_MAX

void adicionarCliente(Fila *fila);


void main(){
	startLogger(&logger, "log.txt");

	puts("Bem vindo ao Supermercado Algoritmico!\n");
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
			puts("AVISO: opcao invalida.");
		}
	}while(opcao != 0);
	endLogger(&logger);
	return;
}

void adicionarCliente(Fila *fila){
	char *nome;
	puts("Qual o nome do cliente?");
	scanf("%s", &nome);
	Cliente cliente;
	cliente.nome = nome;

	enfileira(cliente, fila);

	char *a = "Foi adicionado na fila o cliente: ";
	char *msg = (char *) malloc( 1 + strlen(a) + strlen(&cliente.nome));
	strcpy(msg, a);
	strcat(msg, &cliente.nome);
	logMessage(&logger, msg);
	free(msg);
}
