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
        usleep(milliseconds * 1000);
        printf("\r");
    }
    printf("\n\n");
}