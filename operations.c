#include <unistd.h>
#include "operations.h"
#include "commands.h"

int insertGuests(Guest* guests, int size)
{

    printf("--- \n");
    printf("1 - Inserir hóspedes em um quarto vazio (um quarto pode ter mais de um hóspede) \n");
    printf("--- \n");

    sort(guests, size);

    Guest new;
    Guest hasGuestInSameRoom = binarySearchByRoomId(guests, new.roomId, 0, size);
    do
    {
        printf("Digite o Codigo do quarto: \n");
        printf("(A - Z) \n");
        printf("9 - Voltar \n");
        fflush(stdin);
        scanf("%c", &new.roomId);
        new.roomId = toupper(new.roomId);
        if(new.roomId == '9') return size;
        if(strcmp(hasGuestInSameRoom.name, "NULL") != 0) {
            printf("Quarto ja esta em uso! Tente outro quarto. \n\n");
        }
    } while (strcmp(hasGuestInSameRoom.name, "NULL") != 0);

    char addOneMoreGuest;
    do
    {
        
        printf("Digite o Nome do Hóspede: \n");
        printf("9 - Voltar \n");
        fflush(stdin);
        fgets(new.name, sizeof(new.name), stdin);
        removeNewlineCh(new.name);
        if(new.name[0] == '9') return size;

        printf("Digite a Idade do Hóspede: \n");
        fflush(stdin);
        scanf("%d", &new.age);

        do
        {
            printf("Digite o Genero do Hóspede: \n");
            printf("M = Masculino \n");
            printf("F = Feminino \n");
            printf("9 - Voltar \n");
            fflush(stdin);
            scanf("%c", &new.gender);
            new.gender = toupper(new.gender);
            if(new.gender == '9') return size;
        } while (new.gender != 'F' && new.gender != 'M');

        printf("Deseja adicionar mais um Hóspede para este quarto? \n");
        printf("S = Sim \n");
        printf("N = Nao \n");
        printf("9 - Cancelar \n");
        fflush(stdin);
        scanf("%c", &addOneMoreGuest);
        addOneMoreGuest = toupper(addOneMoreGuest);
        if(addOneMoreGuest == '9') return size;

        guests[size] = new;
        size++;
    } while (addOneMoreGuest == 'S');
    
    return size;
}

void listGuests(Guest* guests, int size)
{
    return;
}

void getGuestByName(Guest* guests, int size)
{
    return;
}

void editGuest(Guest* guests, int size)
{
    return;
}

int removeGuest(Guest* guests, int size)
{

}

void countEmptyRooms(Guest* guests, int size)
{   
    system("cls");

    int returnOption = 0;
    do{

        printf("------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                   [6] Mostrar os números dos quartos vazios\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        printf("--> Digite o numero desejado: ");
        scanf("%d",&returnOption);
        if(returnOption != 6 && returnOption != 0){
            system("cls");
            printf("\a");
            printf("                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
            printf("\n                                      *** Opçaõ inválida, digite o numero '6' ou '0' ***");
            printf("\n                                 \033[1;31m============================================================\033[0m\n\n");
        }
    }while(returnOption != 6 && returnOption != 0);

    if(returnOption == 6){

        system("cls");

        printf("\n\033[1;34mMENSAGEM:\033[0m Analisando os dados dos hospedes, por favor aguarde.\n");
        loading(100, "Carregando");
        system("cls");

        char option;
        int emptyRoomCount = 0;
        int occupiedRoomsCount = 0;

        printf("\n------------------------------------------------------- QUARTOS DO HOTEL ------------------------------------------------------\n");

        printf("           ");
        for (int i = 0; i < 26; i++) {
            int found = 0;
            for (int j = 0; j < size; j++) {
                if (guests[j].roomId == 'A'+ i) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                printf("\033[31;1m| %c \033[0m", 'A'+ i);
                occupiedRoomsCount++;
            }else{
                printf("\033[32;1m");printf("\033[32;1m| %c \033[0m", 'A'+ i);
                emptyRoomCount++;
            }
        }

        printf("\n-------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\n  ============================================\n");
        printf("  || TOTAL DE QUARTOS:                   26 ||\n");
        printf("  ||----------------------------------------||\n");
        printf("  || QUARTOS OCUPADOS:                   \033[31;1m%.2d\033[0m ||\n", occupiedRoomsCount);
        printf("  ||----------------------------------------||\n");
        printf("  || QUARTOS DISPONÍVEIS:                \033[32;1m%.2d\033[0m ||\n", emptyRoomCount);
        printf("  ============================================\n");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------\n\n");
        for(int i = 10; i >= 0; i--){
            printf("\r\033[1;34mMENSAGEM:\033[0m Voltando para o menu principal em... %d ", i);
            sleep(1);
        }
        system("cls");
    }
    if(returnOption == 0){
        system("cls");
        return;
    }
    return;
}

void saveFile(Guest* guests, int size)
{
    sort(guests, size);
    writeFile(guests, size);
    return;
}