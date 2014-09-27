#include <stdio.h>
#include <stdlib.h>
#include "logger/logger.c"

typedef struct{
  char *nome;
  int edicao;
}Revista;

typedef struct{
	char *nome;
	Revista revista;
}Cliente;

typedef struct{
	char *nome;
	int quantidade;
}Produto;

#include "tads/fila.h"
#include "tads/lista.h"

#define TAM_MAX	2000
#include "tads/pilha.h"
#undef TAM_MAX

void adicionarCliente(Fila *fila);
void adicionarItensLista(Lista *lista);
char* lerString();
void limparBufferEntrada();


void main(){
	startLogger("log.txt");

	puts("Bem vindo ao Supermercado Algorítmico!\n");
	int opcao;

	Fila filaClientes;
	iniciaFila(&filaClientes);
	Pilha pilhaRevistas;
	Lista listaCompras;
	iniciaLista(&listaCompras);
	//iniciarPilha(&pilhaRevistas);

	do{
		puts("O que você gostaria de fazer:");
		puts("1. Adicionar itens à Lista de Compras\n2. Visualizar a Lista de Compras\n3. Editar a Lista de Compras");
		puts("4. Adicionar Cliente à Fila\n5. Visualizar a Fila de Clientes\n6. Entregar as Revistas aos Clientes");
		puts("0. Sair");
		scanf("%d",&opcao);

		if(opcao == 1){
			adicionarItensLista(&listaCompras);
		}else if(opcao == 2){
			imprimeLista(&listaCompras);
		}else if(opcao == 3){
			
		}else if(opcao == 4){
			adicionarCliente(&filaClientes);
		}else if(opcao == 5){
			imprimeFila(filaClientes);
		}else if(opcao == 6){
			
		}else if(opcao != 0){
			puts("AVISO: opção inválida.");
		}
	}while(opcao != 0);
	endLogger();
	return;
}

void adicionarCliente(Fila *fila){
	Cliente cliente;
	puts("Qual o nome do cliente?");
	cliente.nome = lerString();

	enfileira(cliente, fila);

	char *a = "Foi adicionado na fila o cliente: ";
	char *msg = (char *) malloc( 1 + strlen(a) + strlen(&cliente.nome));
	strcpy(msg, a);
	strcat(msg, &cliente.nome);
	logMessage(msg);
	free(msg);
}

void adicionarItensLista(Lista *lista){
	//TODO: Mensagens de log
	char continuar;
	do{
		Produto produto;
		puts("Qual o nome do produto?");
		produto.nome = lerString(); 
		puts("Qual a quantidade do produto?");
		scanf("%d",&produto.quantidade);
		insereLista(lista,produto);

		puts("Deseja inserir um novo produto?(s/n)");
		scanf(" %c",&continuar);
	}while(continuar == 's');
}

/*Tive que criar essa função pq scanf não lê espaço, 
  então fiquei puto pq ia ter q fazer uma função só p/ poder ler espaço 
  e resolvi alocar a string dinamicamente tbm.
  (btw, todo mundo parece odiar o scanf e recomendam não usá-lo, entrei p/ essa lista de pessoas tbm -.-
   http://c-faq.com/stdio/scanfprobs.html)
*/
char* lerString(){
	limparBufferEntrada();

	char *str, *aux;
    int c, tam=1, i=0;
    str = (char *) malloc(sizeof(char));
    c = getchar();
    while(c != EOF && c != '\n'){
        str[i++]=c;
        if(i==tam){
            aux = realloc(str, sizeof(char)*(++tam));
            if(aux){
            	str = aux;
            }else{
            	puts("Erro na alocação da string.");
            	return str;
            }
        }
        c = getchar();
    }
    str[i]='\0';

    return str;
}

void limparBufferEntrada(){
	int c = getchar();
	while (c != EOF && c != '\n')
		c = getchar();
}