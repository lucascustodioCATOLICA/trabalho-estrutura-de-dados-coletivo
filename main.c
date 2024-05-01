#include <stdio.h>
#include <locale.h>

#include "filesystem.h"
#include "operations.h"

int main ()
{
    setlocale(LC_ALL, "C.UTF-8");
    Guest* guests = (Guest*) malloc(sizeof(Guest) * MAX_LENGTH);
    int size = readFile(guests);
    if(size == -1) {
        return 1;
    }

    int input = 0;
    do {
        printf("TRABALHO DE ESTRUTURA DE DADOS!!! \n\n");
        printf("1 - Inserir hóspedes em um quarto vazio (um quarto pode ter mais de um hóspede) \n");
        printf("2 - Listar hóspedes por ordem alfabética \n");
        printf("3 - Buscar hóspede \n");
        printf("4 - Editar hóspede \n");
        printf("5 - Liberar um quarto \n");
        printf("6 - Mostrar os números dos quartos vazios \n");
        printf("7 - Salvar lista de hóspedes com respectivos quartos em arquivo \n");
        printf("9 - Sair \n");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            size = insertGuests(guests, size);
            break;
        case 2:
            listGuests(guests, size);
            break;
        case 3:
            getGuestByName(guests, size);
            break;
        case 4:
            editGuest(guests, size);
            break;
        case 5:
            removeGuest(guests, size);
            break;
        case 6:
            countEmptyRooms(guests, size);
            break;
        case 7:
            saveFile(guests, size);
            break;
        default:
            break;
        }
       
    } while(input != 9);

    return 0;
}