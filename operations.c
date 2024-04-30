#include "operations.h"

int insertArtist(Artist* artists, int size)
{
    Artist new;
    int albums_index = 0;
    
    printf("Inserção ordenada (por nome) de novos artistas \n\n");
    printf("Digite o Nome do Artista: \n");
    printf("9 - Voltar \n");
    fflush(stdin);
    fgets(new.name, sizeof(new.name), stdin);
    removeNewlineCh(new.name);
    new.name[0] = toupper(new.name[0]);
    if(new.name[0] == '9') return size;

    printf("Digite o Genero Musical do Artista: \n");
    printf("9 - Voltar \n");
    fgets(new.gender, sizeof(new.gender), stdin);
    removeNewlineCh(new.gender);
    if(new.gender[0] == '9') return size;

    printf("Digite o Local de Surgimento do Artista: \n");
    printf("9 - Voltar \n");
    fgets(new.bornAt, sizeof(new.bornAt), stdin);
    removeNewlineCh(new.bornAt);
    if(new.bornAt[0] == '9') return size;

    do {
        printf("Adicionar Album: \n");
        printf("8 - Confirmar albums e Voltar \n");
        printf("9 - Voltar \n");
        fflush(stdin);
        fgets(new.albums[albums_index].name, sizeof(new.albums[albums_index].name), stdin);
        removeNewlineCh(new.albums[albums_index].name);
        if(new.albums[albums_index].name[0] == '9') return size;
        if(new.albums[albums_index].name[0] != '8') {
            albums_index++;
        }
    } while (new.albums[albums_index].name[0] != '8');

    new.albumsSize = albums_index;
    artists[size] = new;

    int newSize = size+1;

    sort(artists, newSize);
    writeFile(artists, newSize);
    return newSize;
}

int removeArtist(Artist* artists, int size)
{
    char nameToRemove[64];
    Artist* newArtists = (Artist*) malloc(sizeof(Artist) * MAX_LENGTH);

    printf("Remoção de um artista \n\n");
    printf("Digite o Nome do Artista: \n");
    fflush(stdin);
    fgets(nameToRemove, sizeof(nameToRemove), stdin);
    removeNewlineCh(nameToRemove);

    int newArtistsIndex = 0;
    for(int i=0; i<size; i++) {
        if(strcmp(nameToRemove, artists[i].name) != 0) {
            newArtists[newArtistsIndex] = artists[i];
            newArtistsIndex++;
        }
    }

    int newSize = size-1;
    artists = newArtists;
    writeFile(artists, newSize);
    return newSize; 
}

void editArtist(Artist* artists, int size)
{
    char nameToEdit[64];
    Artist new;
    int albums_index = 0;

    printf("Edição de um artista \n\n");
    printf("Digite o Nome do Artista: \n");
    fflush(stdin);
    fgets(nameToEdit, sizeof(nameToEdit), stdin);
    removeNewlineCh(nameToEdit);

    for(int i=0; i<size; i++) {
        if(strcmp(nameToEdit, artists[i].name) == 0) {
            printf("\nEdicao dos atributos do artista: %s \n\n", artists[i].name);

            printf("Digite o Nome do Artista: \n");
            printf("9 - Voltar \n");
            fflush(stdin);
            fgets(new.name, sizeof(new.name), stdin);
            removeNewlineCh(new.name);
            new.name[0] = toupper(new.name[0]);
            if(new.name[0] == '9') return;

            printf("Digite o Genero Musical do Artista: \n");
            printf("9 - Voltar \n");
            fgets(new.gender, sizeof(new.gender), stdin);
            removeNewlineCh(new.gender);
            if(new.gender[0] == '9') return;

            printf("Digite o Local de Surgimento do Artista: \n");
            printf("9 - Voltar \n");
            fgets(new.bornAt, sizeof(new.bornAt), stdin);
            removeNewlineCh(new.bornAt);
            if(new.bornAt[0] == '9') return;

            do {
                printf("Adicionar Album: \n");
                printf("8 - Confirmar albums e Voltar \n");
                printf("9 - Voltar \n");
                fflush(stdin);
                fgets(new.albums[albums_index].name, sizeof(new.albums[albums_index].name), stdin);
                removeNewlineCh(new.albums[albums_index].name);
                if(new.albums[albums_index].name[0] == '9') return;
                if(new.albums[albums_index].name[0] != '8') {
                    albums_index++;
                }
            } while (new.albums[albums_index].name[0] != '8');

            new.albumsSize = albums_index;
            artists[i] = new;

            sort(artists, size);
            writeFile(artists, size);
            return;
        }
    }

    printf("Artista nao encontrado!! \n\n");
    return; 
}

void binarySearchByName(Artist* artists, int size)
{
    sort(artists, size);

    char nameToSearch[64];
    printf("Busca binária por um artista \n\n");
    printf("Digite o Nome do Artista: \n");
    fflush(stdin);
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    removeNewlineCh(nameToSearch);

    Artist artist = binarySearch(artists, nameToSearch, 0, size);
    if(strcmp(artist.name, "NULL") == 0) {
        printf("Artista nao encontrado!! \n\n");
        return;
    }

    printf("--- \n");
    printf("Nome: %s \n", artist.name);
    printf("Genero musical: %s \n", artist.gender);
    printf("Local de surgimento: %s \n", artist.bornAt);
    printf("Albuns: \n");
    for(int i=0; i<artist.albumsSize; i++) {
        printf("  %s \n", artist.albums[i].name);
    }
    printf("--- \n");
    
    return; 
}

void SequencialSearchByAlbum(Artist* artists, int size)
{
    char albumToSeach[64];
    printf("Busca sequencial por um álbum \n\n");
    printf("Digite o Nome do Album: \n");
    fflush(stdin);
    fgets(albumToSeach, sizeof(albumToSeach), stdin);
    removeNewlineCh(albumToSeach);

    for(int i=0; i<size; i++) {
        for(int j=0; j<artists[i].albumsSize; j++) {
            removeNewlineCh(artists[i].albums[j].name);
            if(strcmp(artists[i].albums[j].name, albumToSeach) == 0) {
                printf("--- \n");
                printf("Nome: %s \n", artists[i].name);
                printf("Genero musical: %s \n", artists[i].gender);
                printf("Local de surgimento: %s \n", artists[i].bornAt);
                printf("Albuns: \n");
                for(int k=0; k<artists[i].albumsSize; k++) {
                    printf("  %s \n", artists[i].albums[k].name);
                }
                printf("--- \n");
                return;
            }
        }
    }

    printf("Album nao encontrado!! \n\n");
    return;
}