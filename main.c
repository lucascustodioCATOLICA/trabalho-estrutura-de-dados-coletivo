#include <stdio.h>
#include <unistd.h>
#include <locale.h>

#include "filesystem.h"
#include "operations.h"

int main ()
{
    setlocale(LC_ALL, "C.UTF-8");
    Guest* guests = (Guest*) malloc(sizeof(Guest) * MAX_GUESTS_LENGTH);
    int size = readFile(guests);
    if(size == -1) {
        return 1;
    }

    int input = 0;
    do {
        printf("-------------------------------------------------------------- MENU -----------------------------------------------------------\n");
        printf("                             ======================================================================\n");
        printf("                              [1] Inserir hóspedes em um quarto vazio\n");
        printf("                              [2] Listar hóspedes por ordem alfabética\n");
        printf("                              [3] Buscar hóspede\n");
        printf("                              [4] Editar hóspede\n");
        printf("                              [5] Liberar um quarto\n");
        printf("                              [6] Mostrar os números dos quartos vazios\n");
        printf("                              [7] Salvar lista de hóspedes com respectivos quartos em arquivo\n");
        printf("                              [8] Sair\n");
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
            int total = 20;
            char fullBar = '#';
            char emptyBar = '-';

            printf("\n\033[1;34mMENSAGEM:\033[0m Saindo do programa, por favor aguarde.\n");

            for (int i = 0; i <= total; ++i) {

                int percent = 0;

                printf("\r%s... [","Salvando informações");

                for (int j = 0; j < i; ++j) {
                    printf("%c", fullBar);
                    percent = i * 5;
                }
                
                for (int j = i; j < total; ++j) {
                    printf("%c", emptyBar);
                }    

                printf("] %d%% \r", percent);
                fflush(stdout);
                usleep(150 * 1000);
                printf("\r");
            }
            printf("\n\n");
            system("cls");

            printf("\n==============================================\n");
            printf(" MENSAGEM: Programa finalizado com \033[1;32msucesso!\033[0m\n");
            printf("==============================================\n\n");
            exit(0);
            break;
        default:
                system("cls");
                printf("\a");
                printf("                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m\n");
                printf("                                       *** Opção inválida, digite um numero de 1 a 8 ***\n");
                printf("                                 \033[1;31m============================================================\033[0m\n\n");
            break;
        }
       
    } while(input != 8);

    return 0;
}