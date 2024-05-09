#include "filesystem.h"

enum LINE_STATUS {NAME, GENDER, AGE, ROOM_ID} typedef LINE_STATUS;

int readFile (Guest* guest)
{   
    FILE* file = fopen("dados.txt", "r");
    if (file == NULL) {
        system("cls");
        printf("\a");
        printf("\n                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
        printf("\n                                      *** Arquivo inválido, não foi possível acessar ***");
        printf("\n                                 \033[1;31m============================================================\033[0m");
        return -1;
    }

    char line[256];
    LINE_STATUS lineStatus = NAME;
    int index = 0;
    while(fgets(line, sizeof(line), file) != NULL) { 
        removeNewlineCh(line);
        switch (lineStatus)
        {
            case NAME:
                strcpy((guest + index)->name, line);
                lineStatus = GENDER;
                break;
            case GENDER:
                (guest + index)->gender = (char) line[0];
                lineStatus = AGE;
                break;
            case AGE:
                (guest + index)->age = atoi(line);
                lineStatus = ROOM_ID;
                break;
            case ROOM_ID:
                (guest + index)->roomId = (char) line[0];
                lineStatus = NAME;
                index++;
                fgets(line, sizeof(line), file); // skips '====' line
                break;
        }
    }

    fclose(file);

    return index;
}

void writeFile (Guest* guests, int size)
{
    FILE* file = fopen("dados.txt", "w");
    if (file == NULL) {
        system("cls");
        printf("\a");
        printf("\n                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
        printf("\n                                      *** Arquivo inválido, não foi possível acessar ***");
        printf("\n                                 \033[1;31m============================================================\033[0m");
        return;
    }

    for(int i=0; i<size; i++) {
        fprintf(file, "%s\n", guests[i].name);
        fprintf(file, "%c\n", guests[i].gender);
        fprintf(file, "%d\n", guests[i].age);
        fprintf(file, "%c\n", guests[i].roomId);
        fprintf(file, "==========\n");
    }

    fclose(file);
    system("cls");
    printf("\n\n\n\n                                          \033[92m==================================================\033[0m\n");
    printf("                                           \033[92mMENSAGEM: Dados do arquivo salvo com sucesso!\033[0m\n");
    printf("                                          \033[92m==================================================\033[0m\n\n");
    Sleep(1500);
    system("cls");
    return;
}