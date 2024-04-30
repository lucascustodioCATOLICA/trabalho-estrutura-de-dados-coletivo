#include <stdio.h>
#include <locale.h>

#include "filesystem.h"
#include "operations.h"

int main ()
{
    setlocale(LC_ALL, "C.UTF-8");
    Artist* artists = (Artist*) malloc(sizeof(Artist) * MAX_LENGTH);
    int size = readFile(artists);
    if(size == -1) {
        return 1;
    }

    int input = 0;
    do {
        printf("TRABALHO DE ESTRUTURA DE DADOS!!! \n\n");
        printf("1 - Inserção ordenada (por nome) de novos artistas \n");
        printf("2 - Remoção de um artista \n");
        printf("3 - Edição de um artista \n");
        printf("4 - Busca binária por um artista \n");
        printf("5 - Busca sequencial por um álbum \n");
        printf("9 - Sair \n");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            size = insertArtist(artists, size);
            break;
        case 2:
            size = removeArtist(artists, size);
            break;
        case 3:
            editArtist(artists, size);
            break;
        case 4:
            binarySearchByName(artists, size);
            break;
        case 5:
            SequencialSearchByAlbum(artists, size);
            break;
        default:
            break;
        }
       
    } while(input != 9);

    return 0;
}