typedef struct{
    FILE *file;
}Logger;

void logFile(Logger *logger, char *logMessage){
  fprintf(logger->file, "%s\n", logMessage);
}

void startLogger(Logger *logger, char *path){
  logger->file = fopen(path, "w");
  logFile(logger, "=================================================");
  logFile(logger, "Inicio da execucao: Supermercado Algoritmico");
  logFile(logger, "Israel Barreto Sant'Anna, Vytor dos Santos Bezerra Calixto.");
  logFile(logger, "=================================================");
}

void endLogger(Logger *logger){
  logFile(logger, "=================================================");
  logFile(logger, "Fim da execucao");
  free(logger->file);
}
