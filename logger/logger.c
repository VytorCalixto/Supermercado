typedef struct{
    FILE *file; //Arquivo do log
}Logger;

//Salva uma mensagem de texto no arquivo
void logMessage(Logger *logger, char *logMsg){
  fprintf(logger->file, "%s\n", logMsg);
}

//Inicia o logger abrindo o arquivo e colocando as informações iniciais.
void startLogger(Logger *logger, char *path){
  logger->file = fopen(path, "w");
  logMessage(logger, "=================================================");
  logMessage(logger, "Inicio da execucao: Supermercado Algoritmico");
  logMessage(logger, "Israel Barreto Sant'Anna, Vytor dos Santos Bezerra Calixto.");
  logMessage(logger, "=================================================");
}

//Termina o logger desalocando da memória
void endLogger(Logger *logger){
  logMessage(logger, "=================================================");
  logMessage(logger, "Fim da execucao");
  free(logger->file);
}
