#include "commands.h"

void loading(int milliseconds, char *text){
    int total = 20;
    char fullBar = '#';
    char emptyBar = '-';
    
    for (int i = 0; i <= total; ++i) {

        int percent = 0;

        printf("\r%s... [",text);
        for (int j = 0; j < i; ++j) {
            printf("%c", fullBar);
            percent = i * 5;
        }
        for (int j = i; j < total; ++j) {
            printf("%c", emptyBar);
        }        
        printf("] %d%% \r", percent);
        fflush(stdout);
        Sleep(milliseconds);
        printf("\r");
    }
    printf("\n\n");
}

void removeLine(int value){
    for(int i = 0; i < value; i++){
        printf("\033[A\033[K");
    }
}

int countString(char *string){
    int count = 0;
    while (string[count] != '\0') {
        count++;
    }
    return count;
}