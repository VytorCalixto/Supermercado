typedef struct{
    FILE *file; //Arquivo do log
}Logger;

Logger logger;

//Salva uma mensagem de texto no arquivo
void logMessage(char *logMsg);

//Inicia o logger abrindo o arquivo e colocando as informações iniciais.
void startLogger(char *path);

void endLogger();

void logMessage(char *logMsg){
  if(logger.file != NULL){
    fprintf(logger.file, "%s\n", logMsg);
  }else{
    startLogger("log.txt");
  }
}

void startLogger(char *path){
  printf("%s\n", path);
  logger.file = fopen(path, "w");
  logMessage("=================================================");
  logMessage("Inicio da execucao: Supermercado Algoritmico");
  logMessage("Israel Barreto Sant'Anna, Vytor dos Santos Bezerra Calixto.");
  logMessage("=================================================");
}

//Termina o logger desalocando da memória
void endLogger(){
  logMessage("=================================================");
  logMessage("Fim da execucao");
  free(logger.file);
}
