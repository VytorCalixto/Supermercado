#include <stdio.h>
#include <stdlib.h>
#include "tads/lista.c"
#include "tads/fila.c"
#include "tads/pilha.c"
#include "logger/logger.c"

typedef struct{
	char *nome;
	Lista listaCompras;
	char *revista;
}Cliente;

void adicionarCliente(Fila *fila);

void main(){
	Logger logger;
	startLogger(&logger, "log.txt");

	puts("Bem vindo ao Supermercado Algorítmico!\n");
	int opcao;

	Fila filaClientes;
	//iniciarFila(&filaClientes);
	Pilha pilhaRevistas;
	//iniciarPilha(&pilhaRevistas);

	do{
		puts("O que você gostaria de fazer:\n");
		puts("1. Adicionar Cliente a fila\n2. Criar nova Lista de Compras\n3. Ir para a fila\n0. Sair\n");
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
	scanf("%s", nome);
	Cliente cliente = {nome};
	//enfileira(fila, cliente);
}
