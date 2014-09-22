// Lista duplamente encadeada
typedef struct ElementoLista{
	char *elemento; //Para escrever strings
	struct ElementoLista *proximo;
	struct ElementoLista *anterior;
}ElementoLista;

typedef ElementoLista Lista;

void iniciaLista(Lista *lista){
	lista = (Lista *) malloc(sizeof(Lista));
	lista->proximo = lista;
	lista->anterior = lista;
}

int vaziaLista(Lista *lista){
	return (lista->proximo == lista);
}

// FIXME: Copiei o que estava no caderno, precisa de revisão
void insereLista(Lista *lista, char *elemento){
	lista->anterior->proximo = (Lista *) malloc(sizeof(Lista));
	lista->anterior->proximo->proximo = lista;
	lista->anterior->proximo->anterior = lista->anterior;
	lista->anterior = lista->anterior->proximo;
	lista->anterior->elemento = elemento;
}

char* removeLista(Lista *lista, ElementoLista *posicao){
	if(vaziaLista(lista)){
		puts("ERRO: não é possível remover.\nMotivo: a lista está vazia.");
		return "";
	}else if(posicao == lista){
		puts("ERRO: não é possível remover.\nMotivo: parâmetro posição aponta para nodo cabeça.");
		return "";
	}else{
		posicao->anterior->proximo = posicao->proximo;
		posicao->proximo->anterior = posicao->anterior;
		char *elemento = posicao->elemento;
		free(posicao);
		return elemento;
	}
}

void imprimeLista(Lista *lista){
	if(vaziaLista(lista)){
		puts("ERRO: impossível imprimir lista.\nMotivo: a lista está vazia.");
	}else{
		ElementoLista *aux = lista->proximo;
		int valor = 1;
		while(aux != lista){
			printf("%d - %s", valor, aux->elemento);
			aux = aux->proximo;
			valor++;
		}
	}
}
