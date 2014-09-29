#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void adicionarItensLista(Lista *lista);
void removerProdutoLista(Lista *listaCompras);
void adicionarCliente(Fila *fila);
void empilharRevistas(Pilha *pilha);
void entregarRevistas(Pilha *pilha, Fila *fila);
char* lerString();
void limparBufferEntrada();

void main(){
	startLogger("log.txt");

	puts("Bem vindo ao Supermercado Algorítmico!");
	int opcao;

	Fila filaClientes;
	iniciaFila(&filaClientes);
	Pilha pilhaRevistas;
	Lista listaCompras;
	iniciaLista(&listaCompras);
	iniciaPilha(&pilhaRevistas);

	do{
        //limparBufferEntrada();
		puts("\nO que você gostaria de fazer:");
		puts("1. Adicionar item à Lista de Compras\n2. Visualizar a Lista de Compras\n3. Remover item da Lista de Compras");
		puts("4. Adicionar Cliente à Fila\n5. Visualizar a Fila de Clientes\n6. Entregar as Revistas aos Clientes");
		puts("0. Sair");
		scanf("%d",&opcao);
        printf("\n");

		if(opcao == 1){
			adicionarItensLista(&listaCompras);
		}else if(opcao == 2){
			imprimeLista(&listaCompras);
		}else if(opcao == 3){
           removerProdutoLista(&listaCompras);
		}else if(opcao == 4){
			adicionarCliente(&filaClientes);
		}else if(opcao == 5){
			imprimeFila(filaClientes);
		}else if(opcao == 6){
            empilharRevistas(&pilhaRevistas);
            entregarRevistas(&pilhaRevistas, &filaClientes);
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

    logMessage("Foi adicionado na fila o cliente: ");
    logMessage(cliente.nome);
    logFila(*fila);
}

void adicionarItensLista(Lista *lista){
	Produto produto;
	puts("Qual o nome do produto?");
	produto.nome = lerString();
	puts("Qual a quantidade do produto?");
	scanf("%d",&produto.quantidade);
	insereLista(lista,produto);

    logMessage("Foi adicionado na lista de compras: ");
    logMessage(produto.nome);
    logMessage(" x ");
    char qtd[1000];
    snprintf(qtd, sizeof(qtd), "%d", produto.quantidade);
    logMessage(qtd);
    logMessage("\n");
}

void removerProdutoLista(Lista *listaCompras){
    int index;
    imprimeLista(listaCompras);
    puts("Entre com o índice referente ao item que você quer remover:");
    scanf("%d", &index);
    removeLista(listaCompras,index-1);
}

void empilharRevistas(Pilha *pilha){
    srand(time(NULL));
    char *revistas[8] = {"Mundo Estranho", "info", "Super Interessante", "Caras", "Tititi", "Isto É", "Carta Capital", "Veja"};

    int tam = rand() % 50; //Pode ficar muito grande além disso
    int i;
    for(i = 0; i <= 2; i++){
        Revista revista;
        revista.nome = revistas[rand() % 8];
        revista.edicao = rand() % 36;
        push(pilha, revista);

        logMessage("Empilhada a revista: ");
        logMessage(revista.nome);
        logMessage("\n");
    }
    logPilha(pilha);
}

//TODO: logs
void entregarRevistas(Pilha *pilha, Fila *fila){
    while(!vaziaPilha(pilha) && !vaziaFila(*fila)){
        Cliente cliente = desenfileira(fila);
        cliente.revista = pop(pilha);
        printf("Cliente %s recebeu a revista %s, %dª edição.\n", cliente.nome, cliente.revista.nome, cliente.revista.edicao);
    }
    while(!vaziaFila(*fila)){
        printf("Cliente %s não recebeu revista.\n", desenfileira(fila).nome);
    }
}

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
