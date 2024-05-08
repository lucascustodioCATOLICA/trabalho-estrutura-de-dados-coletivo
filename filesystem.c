#include "filesystem.h"

enum LINE_STATUS {NAME, GENDER, AGE, ROOM_ID} typedef LINE_STATUS;

int readFile (Guest* guest)
{   
    FILE* file = fopen("dados.txt", "r");
    if (file == NULL) {
        printf("Arquivo nao pode ser aberto\n");
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
        printf("Arquivo nao pode ser aberto\n");
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

    printf("Dados salvos com sucesso! \n");
    return;
}