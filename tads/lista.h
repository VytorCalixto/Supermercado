typedef struct{
	Produto *vetor;
	int final;
}Lista;

void iniciaLista(Lista *lista){
	lista->vetor = (Produto *) malloc(sizeof(Produto));
	lista->final = 0;
}

int vaziaLista(Lista *lista){
	return (lista->final == 0);
}

void insereLista(Lista *lista, Produto elemento){
	Produto *aux = (Produto *) realloc(lista->vetor, sizeof(Produto)*(lista->final+1));
	if(aux){
		lista->vetor = aux;
		lista->vetor[lista->final] = elemento;
		lista->final++;
	}else{
		puts("ERRO: não é possível inserir.\nMotivo: erro na alocação do vetor.");
	}
}

Produto removeLista(Lista *lista, int posicao){
	if(vaziaLista(lista)){
		puts("ERRO: não é possível remover.\nMotivo: a lista está vazia.");
		return;
	}else if(posicao >= lista->final){
		puts("ERRO: não é possível remover.\nMotivo: posição maior do que o tamanho da lista.");
		return;
	}else{
		int i;
		Produto aux = lista->vetor[posicao];
		for(i=posicao; i+1 <= lista->final-1; i++){
			lista->vetor[i] = lista->vetor[i+1];
		}
		lista->final--;
		Produto *auxAlloc = (Produto *) realloc(lista->vetor, sizeof(Produto)*(lista->final)+1);
		if(auxAlloc)
			lista->vetor = auxAlloc;
		return aux;
	}
}

void imprimeLista(Lista *lista){
	if(vaziaLista(lista)){
		puts("ERRO: impossível imprimir lista.\nMotivo: a lista está vazia.");
	}else{
		int i;
		for(i=0;i<lista->final;i++){
			printf("%s x%d\n", lista->vetor[i].nome, lista->vetor[i].quantidade);
		}
	}
}
