typedef struct ElementoFila{
	Cliente elemento;
	struct ElementoFila *prox;
}ElementoFila;

typedef struct{
	ElementoFila *frente,*final;
}Fila;

void iniciaFila(Fila *fila){
	fila->frente = (ElementoFila*)malloc(sizeof(ElementoFila));
	fila->final = fila->frente;
	fila->final->prox = NULL;
}

int vaziaFila(Fila fila){
	return (fila.frente == fila.final);
}

void enfileira(Cliente elemento, Fila *fila){
	fila->final->prox = (ElementoFila*)malloc(sizeof(ElementoFila));
	fila->final = fila->final->prox;
	fila->final->prox = NULL;
	fila->final->elemento = elemento;
}

Cliente desenfileira(Fila *fila){
	ElementoFila *aux;
	if(vaziaFila(*fila)){
		puts("ERRO: não é possível desenfileirar.\nMotivo: a fila está vazia.");
		return;
	}else{
		aux = fila->frente;
		fila->frente = fila->frente->prox;
		free(aux);
		return fila->frente->elemento;
	}
}

void imprimeFila(Fila fila){
	if(vaziaFila(fila)){
		puts("ERRO: não é possível imprimir a fila.\nMotivo: fila vazia");
	}else{
		ElementoFila *aux;
		printf("[ ");
		for(aux = fila.frente; aux->prox !=NULL; aux = aux->prox){
				printf("%s ", aux->elemento.nome);
		}
		printf("]");
	}
}