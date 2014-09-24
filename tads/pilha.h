#ifndef TAM_MAX
#error Você deve definir o tamanho máximo
#endif

typedef struct{
  char *nome;
  int edicao;
}Revista;

typedef Revista ElementoPilha;

typedef struct{
  ElementoPilha pilha[TAM_MAX];
  int topo; //Topo aponta para a primeira posição livre
}Pilha;

void iniciaPilha(Pilha *pilha){
  pilha->topo = 0;
}

int vaziaPilha(Pilha *pilha){
  return (pilha->topo == 0);
}

int tamanhoPilha(Pilha *pilha){
  return (pilha->topo);
}

void push(Pilha *pilha, ElementoPilha elemento){
  if(tamanhoPilha(pilha) == TAM_MAX){
    puts("ERRO: não é possivel empilhar.\nMotivo: a pilha está cheia");
  }else{
    pilha->pilha[pilha->topo] = elemento;
    pilha->topo++;
  }
}

ElementoPilha pop(Pilha *pilha){
  if(vaziaPilha(pilha)){
    puts("ERRO: não é possível desempilhar.\nMotivo: a pilha está vazia.");
    return;
  }else{
    ElementoPilha elemento = pilha->pilha[pilha->topo-1];
    pilha->topo--;
    return elemento;
  }
}
