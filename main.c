#include <stdio.h>
#include <unistd.h>
#include <locale.h>

#include "filesystem.h"
#include "operations.h"
#include "commands.h"

int main ()
{
    setlocale(LC_ALL, "C.UTF-8");
    Guest* guests = (Guest*) malloc(sizeof(Guest) * MAX_GUESTS_LENGTH);
    int size = readFile(guests);
    if(size == -1) {
        return 1;
    }
    system("cls");
    printf("\n");
    loading(200," Inicializando programa");
    Sleep(200);
    system("cls");

    printf("...............................................................................................................................\n");
    Sleep(50);
    printf("...............................................................................................................................\n");
    Sleep(50);
    printf(".........................................  ______ _____ _____ _____ _____ __    _____ _____  ..................................\n");
    Sleep(50);
    printf("........................................  |_    _| __  |  _  | __  |  _  |  |  |  |  |     |  .................................\n");
    Sleep(50);
    printf("..........................................  |  | |    -|     | __ -|     |  |__|     |  |  |  .................................\n");
    Sleep(50);
    printf("..........................................  |__| |__|__|__|__|_____|__|__|_____|__|__|_____|  .................................\n");
    Sleep(50);
    printf("..........  _____ _____ ______ _____ _____ ______ _____ _____ _____    ____  _____    ____  _____ ____  _____ _____  ..........\n");
    Sleep(50);
    printf(".........  |   __|   __|_    _| __  |  |  |_    _|  |  | __  |  _  |  |    \\|   __|  |    \\|  _  |    \\|     |   __|  .........\n");
    Sleep(50);
    printf(".........  |   __|__   | |  | |    -|  |  | |  | |  |  |    -|     |  |  |  |   __|  |  |  |     |  |  |  |  |__   |  .........\n");
    Sleep(50);
    printf(".........  |_____|_____| |__| |__|__|_____| |__| |_____|__|__|__|__|  |____/|_____|  |____/|__|__|____/|_____|_____|  .........\n");
    Sleep(50);
    printf("...............................................................................................................................\n");
    Sleep(50);
    printf("...............................................................................................................................\n\n");

    int input = 0;
    do {
        printf("\n-------------------------------------------------------------- MENU -----------------------------------------------------------\n");
        printf("                             ======================================================================\n");
        printf("                              [1] Inserir hóspedes em um quarto vazio\n");
        printf("                              [2] Listar hóspedes por ordem alfabética\n");
        printf("                              [3] Buscar hóspede\n");
        printf("                              [4] Editar hóspede\n");
        printf("                              [5] Liberar um quarto\n");
        printf("                              [6] Mostrar os números dos quartos vazios\n");
        printf("                              [7] Salvar lista de hóspedes com respectivos quartos em arquivo\n");
        printf("                              [8] Sair do programa\n");
        printf("                             ======================================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("--> Digite a opcao desejada: ");
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
        case 8:
            system("cls");

            printf("\n\033[1;34mMENSAGEM:\033[0m Saindo do programa, por favor aguarde.\n");
            loading(150, "Salvando informações");

            system("cls");

            printf("\n\033[1;32m==============================================\033[0m\n");
            printf(" \033[1;32mMENSAGEM: Programa finalizado com sucesso!\033[0m\n");
            printf("\033[1;32m==============================================\033[0m\n\n");
            exit(0);
            break;
        default:
                system("cls");
                printf("\a");
                printf("\n\n                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m\n");
                printf("                                       *** Opção inválida, digite um numero de 1 a 8 ***\n");
                printf("                                 \033[1;31m============================================================\033[0m\n\n");
            break;
        }
       
    } while(input != 8);

    return 0;
}