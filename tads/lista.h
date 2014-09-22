typedef struct{
	char *nome;
	int quantidade;
}Produto;

// Lista duplamente encadeada
typedef struct ElementoLista{
	Produto produto; //Para escrever strings
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
void insereLista(Lista *lista, Produto *elemento){
	lista->anterior->proximo = (Lista *) malloc(sizeof(Lista));
	lista->anterior->proximo->proximo = lista;
	lista->anterior->proximo->anterior = lista->anterior;
	lista->anterior = lista->anterior->proximo;
	lista->anterior->produto = *elemento;
}

Produto* removeLista(Lista *lista, ElementoLista *posicao){
	if(vaziaLista(lista)){
		puts("ERRO: não é possível remover.\nMotivo: a lista está vazia.");
		return 0;
	}else if(posicao == lista){
		puts("ERRO: não é possível remover.\nMotivo: parâmetro posição aponta para nodo cabeça.");
		return 0;
	}else{
		posicao->anterior->proximo = posicao->proximo;
		posicao->proximo->anterior = posicao->anterior;
		Produto elemento = posicao->produto;
		free(posicao);
		return &elemento;
	}
}

void imprimeLista(Lista *lista){
	if(vaziaLista(lista)){
		puts("ERRO: impossível imprimir lista.\nMotivo: a lista está vazia.");
	}else{
		ElementoLista *aux = lista->proximo;
		int valor = 1;
		while(aux != lista){
			printf("%s x%d", aux->produto.nome, aux->produto.quantidade);
			aux = aux->proximo;
			valor++;
		}
	}
}
