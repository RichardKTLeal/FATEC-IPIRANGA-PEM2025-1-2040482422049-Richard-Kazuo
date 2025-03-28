#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void listarDiretorios(const char *caminho, int nivel) {
    struct dirent *entrada;
    DIR *diretorio = opendir(caminho);

    if (diretorio == NULL) {
        printf("Erro ao abrir diretório: %s\n", caminho);
        return;
    }

    while ((entrada = readdir(diretorio)) != NULL) {
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0) {
            continue;
        }

        for (int i = 0; i < nivel; i++) {
            printf("  ");
        }
        
        printf("|-- %s\n", entrada->d_name);

        char caminhoCompleto[1024];
        snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/%s", caminho, entrada->d_name);

        struct stat info;
        if (stat(caminhoCompleto, &info) == 0 && S_ISDIR(info.st_mode)) {
            listarDiretorios(caminhoCompleto, nivel + 1);
        }
    }

    closedir(diretorio);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <caminho do diretório>\n", argv[0]);
        return 1;
    }

    printf("Explorando diretório: %s\n", argv[1]);
    listarDiretorios(argv[1], 0);
    
    return 0;
}
