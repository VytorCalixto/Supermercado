typedef struct{
    FILE *file; //Arquivo do log
}Logger;

//Salva uma mensagem de texto no arquivo
void logFile(Logger *logger, char *logMessage){
  fprintf(logger->file, "%s\n", logMessage);
}

//Inicia o logger abrindo o arquivo e colocando as informações iniciais.
void startLogger(Logger *logger, char *path){
  logger->file = fopen(path, "w");
  logFile(logger, "=================================================");
  logFile(logger, "Inicio da execucao: Supermercado Algoritmico");
  logFile(logger, "Israel Barreto Sant'Anna, Vytor dos Santos Bezerra Calixto.");
  logFile(logger, "=================================================");
}

//Termina o logger desalocando da memória
void endLogger(Logger *logger){
  logFile(logger, "=================================================");
  logFile(logger, "Fim da execucao");
  free(logger->file);
}
