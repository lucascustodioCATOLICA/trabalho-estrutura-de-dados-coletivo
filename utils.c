#include "utils.h"

void removeNewlineCh(char *line)
{
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
    if (line[new_line-1] == ' ')
        line[new_line-1] = '\0';
}