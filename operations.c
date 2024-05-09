#include "operations.h"
#include "commands.h"
#include <windows.h>

int insertGuests(Guest* guests, int size)
{
    system("cls");

    int returnOption = 0;
    char addOneMoreGuest;
    int line = 0;

    secondaryMenu1:
    do{ 
        printf("\n\n------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                   [1] Inserir hóspedes em um quarto vazio\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        printf("--> Digite o numero desejado: ");
        scanf("%d",&returnOption);

        if(returnOption != 1 && returnOption != 0){
            system("cls");
            printf("\a");
            printf("\n                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
            printf("\n                                      *** Opçaõ inválida, digite o numero '1' ou '0' ***");
            printf("\n                                 \033[1;31m============================================================\033[0m");
        }
    }while(returnOption != 1 && returnOption != 0);

    if(returnOption == 1){
        system("cls");
        printf("\n\n------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                 \033[1;34m->[1] Inserir hóspedes em um quarto vazio\033[0m\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        sort(guests, size);

        Guest new;
        Guest hasGuestInSameRoom;

        do{
            printf("--> Insira código do quarto (A-Z): ");
            fflush(stdin);
            scanf("%c", &new.roomId);
            new.roomId = toupper(new.roomId);
            hasGuestInSameRoom = searchByRoomId(guests, new.roomId, size);
            if(strcmp(hasGuestInSameRoom.name, "NULL") != 0) {
                line = 1;
                removeLine(line);
                printf("\n                                 \033[1;31m============================================================\033[0m");
                printf("\n                                       *** Ops! Quarto ocupado, Tente outro quarto. ***");
                printf("\n                                 \033[1;31m============================================================\033[0m\n\n");
                Sleep(1500);
                line = 5;
                removeLine(line);
            }
        } while (strcmp(hasGuestInSameRoom.name, "NULL") != 0);

        system("cls");
        printf("\n\n                             ---------------------  Quarto %c \033[92m(Adicionando)\033[0m --------------------",new.roomId);

        do{
            printf("\n                                 ============================================================\n"); 
            printf("                                  -> Nome: ");
            fflush(stdin);
            fgets(new.name, sizeof(new.name), stdin);
            removeNewlineCh(new.name);
            printf("                                  -> Idade: ");
            fflush(stdin);
            scanf("%d", &new.age);

            do
            {
                printf("                                  -> Gênero(M/F): ");
                fflush(stdin);
                scanf("%c", &new.gender);
                new.gender = toupper(new.gender);
            } while (new.gender != 'F' && new.gender != 'M');
            printf("                                 ============================================================\n");
            printf("                             --------------------------------------------------------------------\n");

            printf("\nDeseja adicionar mais um Hóspede para este quarto(s/n)? ");
            fflush(stdin);
            scanf("%c", &addOneMoreGuest);
            addOneMoreGuest = toupper(addOneMoreGuest);

            if(addOneMoreGuest == 'S'){
                int line = 3;
                removeLine(line);
            }

            guests[size] = new;
            size++;
        } while (addOneMoreGuest == 'S');

        line = 3;
        removeLine(line);
        printf("                             --------------------------------------------------------------------\n");
        printf("\n\033[1;34mMENSAGEM:\033[0m Adicionando na lista, por favor aguarde.\n");
        loading(100, "Carregando");
        system("cls");
        printf("\n\n\n\n                                          \033[92m============================================\033[0m\n");
        printf("                                           \033[92mMENSAGEM: Hóspede adicionado com sucesso!\033[0m\n");
        printf("                                          \033[92m============================================\033[0m\n\n");
        Sleep(1500);
        system("cls");
        return size;
    }
    if(returnOption == 0){
        system("cls");
    }    
}

void listGuests(Guest* guests, int size)
{
    system("cls");
    sort(guests, size);

    printf("\n------------------------------------------------- Lista por ordem alfabética --------------------------------------------------\n");
    for(int i = 0; i<size; i++){
        Sleep(200);
        printf("\n          ============================================================================================================\n");
        Sleep(150);
        printf("          \033[1m Nome:\033[0m %s \n", guests[i].name);
        Sleep(150);
        printf("          \033[1m Idade:\033[0m %d \n", guests[i].age);
        Sleep(150);
        if(guests[i].gender == 'M'){
            printf("          \033[1m Genero:\033[0m Masculino \n");
        } else if(guests[i].gender == 'F'){
            printf("          \033[1m Genero:\033[0m Feminino \n");
        }
        Sleep(150);
        printf("          \033[1m ID do quarto:\033[0m %c \n", guests[i].roomId);
        Sleep(150);
        printf("          ============================================================================================================\n");
    }
    printf("-------------------------------------------------------------------------------------------------------------------------------\n\n");

    for(int i = 10; i >= 0; i--){
        printf("\r\033[1;34mMENSAGEM:\033[0m Voltando para o menu principal em... %d ", i);
        sleep(1);
    }
    system("cls");
    return;
}

void getGuestByName(Guest* guests, int size)
{    
    system("cls");

    int returnOption = 0;
    int messageGuestNotFound = 0;
    secondaryMenu3:
    do{ 
        printf("\n\n------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                   [3] Buscar hóspede\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        printf("--> Digite o numero desejado: ");
        scanf("%d",&returnOption);

        if(returnOption != 3 && returnOption != 0){
            if(messageGuestNotFound == 0){
                system("cls");
                messageGuestNotFound = 0;
            }else{
                int line = 9;
                removeLine(line);
            }
            printf("\a");
            printf("\n                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
            printf("\n                                      *** Opçaõ inválida, digite o numero '3' ou '0' ***");
            printf("\n                                 \033[1;31m============================================================\033[0m");
        }
    }while(returnOption != 3 && returnOption != 0);

    if(returnOption == 3){

        system("cls");
        char name[50];
        char firstName[20];

        printf("\n\n------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                 \033[1;34m->[3] Buscar hóspede\033[0m\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("--> Digite nome do hóspede que deseja encontrar: ");
        fflush (stdin);
        fgets (name, sizeof(name), stdin);
        removeNewlineCh(name);
        Guest guest = binarySearch(guests, name, 0, size);
         
        if (strcmp (guest.name, "NULL")  == 0) {

            system("cls");

            sscanf(name, "%s", firstName);
            int size = countString(firstName);

            printf("\n\n                                 \033[38;5;208m=================  HÓSPEDE NÃO ENCONTRADO  =================\033[0m");
                if(size >= 8){
                    printf("\n                                    \033[38;5;208m*** Hóspede %.6s... não foi encontrado na lista ***\033[0m", firstName);
                }else{
                    printf("\n                                      \033[38;5;208m*** Hóspede %s não foi encontrado na lista ***\033[0m", firstName);
                }
            printf("\n                                 \033[38;5;208m============================================================\033[0m\n");

            messageGuestNotFound ++;
            sleep(2);
            goto secondaryMenu3;
        }
    
        system("cls");
        printf("\n\033[1;34mMENSAGEM:\033[0m Buscando '%s' na lista, por favor aguarde.\n", name);
        loading(100, "Carregando");
        
        system("cls");

        printf("\n\n                              ----------------------- Resultado da busca -----------------------\n");
        printf("                                 ============================================================");
        Sleep(150);
        printf("\n                                  Nome: %s", guest.name);
        Sleep(150);
        printf("\n                                  Idade: %d", guest.age); 
        Sleep(150);
        if(guest.gender == 'M'){
            printf("\n                                  \033[1mGenero:\033[0m Masculino");
        } else if(guest.gender == 'F'){
            printf("\n                                  \033[1mGenero:\033[0m Feminino");
        } 
        Sleep(150);
        printf("\n                                  ID do Quarto: %c", guest.roomId); 
        Sleep(150);
        printf("\n                                 ============================================================"); 
        printf("\n                              ------------------------------------------------------------------\n\n");

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

void editGuest(Guest* guests, int size)
{    
    system("cls");

    int returnOption = 0;
    int messageGuestNotFound = 0;
    int line = 0;
    secondaryMenu4:
    do{
        printf("\n\n------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                   [4] Editar hóspede\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        printf("--> Digite o numero desejado: ");
        scanf("%d",&returnOption);

        if(returnOption != 4 && returnOption != 0){
            if(messageGuestNotFound == 0){
                system("cls");
                printf("\n");
                messageGuestNotFound = 0;
            }else{
                line = 9;
                removeLine(line);
            }
            printf("\a");
            printf("\n                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
            printf("\n                                      *** Opçaõ inválida, digite o numero '4' ou '0' ***");
            printf("\n                                 \033[1;31m============================================================\033[0m");
        }
    }while(returnOption != 4 && returnOption != 0);

    if(returnOption == 4){
        system("cls");
        
        Guest new;
        char firstName[20];
        char confirm;

        printf("\n\n------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                 \033[1;34m->[4] Editar hóspede \033[0m\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("--> Digite nome completo do hóspede que deseja editar: ");
        fflush (stdin);
        fgets (new.name, sizeof(new.name), stdin);
        removeNewlineCh(new.name);

        sort(guests, size);
        Guest *exists = binarySearchPtr(guests, new.name, 0, size);

        if(strcmp(exists->name, "NULL") == 0) {
            system("cls");

            sscanf(new.name, "%s", firstName);
            int size = countString(firstName);

            printf("\n\n                                 \033[38;5;208m=================  HÓSPEDE NÃO ENCONTRADO  =================\033[0m");
                if(size >= 8){
                    printf("\n                                    \033[38;5;208m*** Hóspede %.6s... não foi encontrado na lista ***\033[0m", firstName);
                }else{
                    printf("\n                                      \033[38;5;208m*** Hóspede %s não foi encontrado na lista ***\033[0m", firstName);
                }
            printf("\n                                 \033[38;5;208m============================================================\033[0m\n");

            messageGuestNotFound ++;
            sleep(2);
            goto secondaryMenu4;
        }

        Guest hasGuestInSameRoom;

        system("cls");
        printf("\n\033[31mATENÇÃO:\033[0m Por favor, insira os dados em cada campo abaixo para ser editado.\n");
        printf("\n%s \033[92m(Editar)\033[0m \n",new.name); 

        printf("  -> Novo nome: ");
        fflush(stdin);
        fgets(new.name, sizeof(new.name), stdin);
        removeNewlineCh(new.name);

        printf("  -> Idade: ");
        fflush(stdin);
        scanf("%d", &new.age);

        do
        {
            printf("  -> Genero(M/F): ");
            fflush(stdin);
            scanf("%c", &new.gender);
            new.gender = toupper(new.gender);
        } while (new.gender != 'F' && new.gender != 'M');

        do{
            printf("  ->ID do quarto(A-Z): ");
            fflush(stdin);
            scanf("%c", &new.roomId);
            new.roomId = toupper(new.roomId);
            hasGuestInSameRoom = searchByRoomId(guests, new.roomId, size);
            if(strcmp(hasGuestInSameRoom.name, "NULL") != 0 && exists->roomId != new.roomId) {
                line = 1;
                removeLine(line);
                printf("\n  \033[1;31m===========================================================\033[0m");
                printf("\n        *** Ops! Quarto ocupado, Tente outro quarto. ***");
                printf("\n  \033[1;31m===========================================================\033[0m\n\n");
                Sleep(1500);
                line = 5;
                removeLine(line);
            }
        } while (strcmp(hasGuestInSameRoom.name, "NULL") != 0 && exists->roomId != new.roomId);

        do
        {
            printf("\nDeseja confirmar alteração(s/n)? ");
            fflush(stdin);
            scanf("%c", &confirm);
            confirm = toupper(confirm);
        } while (confirm != 'S' && confirm != 'N');

        if(confirm == 'S' || confirm == 's') {
            strcpy(exists->name, new.name);
            exists->age = new.age;
            exists->gender = new.gender;
            exists->roomId = new.roomId;

            printf("\n\033[1;34mMENSAGEM:\033[0m Realizando alteração, por favor aguarde\n");
            loading(100, "Editando");
            system("cls");
        }
        if(confirm == 'N' || confirm == 'n'){
            printf("\n\033[1;34mMENSAGEM:\033[0m Por favor, aguarde enquanto desfazemos as alterações nos dados do hóspede.\n");
            loading(100, "Modificando");
            system("cls");
            goto secondaryMenu4;
        }
    }
    if(returnOption == 0){
        system("cls");
        return;
    }
    return;
}

int removeGuest(Guest* guests, int size) {
    system("cls");

    int returnOption = 0;
    do {
        printf("------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("  ============================================================\n");
        printf("  [5] Liberar um quarto\n");
        printf("  [0] Voltar para o menu principal\n");
        printf("  ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        printf("--> Digite o numero desejado: ");
        scanf("%d", &returnOption);

        if (returnOption != 5 && returnOption != 0) {
            system("cls");
            printf("\a");
            printf("  \033[1;31m==================  MENSAGEM DE ALERTA  ==================\033[0m");
            printf("\n *** Opção inválida, digite o numero '5' ou '0' ***");
            printf("\n \033[1;31m============================================================\033[0m\n\n");
        }
    } while (returnOption != 5 && returnOption != 0);

    if (returnOption == 5) {
        system("cls");

        printf("------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("  ============================================================\n");
        printf(" \033[1;34m->[5] Liberar um quarto \033[0m\n");
        printf(" [0] Voltar para o menu principal\n");
        printf("  ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("--> Digite o ID do quarto: ");
        char roomToFree;
        fflush(stdin);
        scanf("%c", &roomToFree);
        roomToFree = toupper(roomToFree);

        int i;
        for (i = 0; i < size; i++) {
            if (guests[i].roomId == roomToFree) {

                if (i == size) {
                    printf("\n\n \033[91m============================================\033[0m\n");
                    printf("  \033[91mMENSAGEM: Quarto não encontrado!\033[0m\n");
                    printf(" \033[91m============================================\033[0m\n\n");
                    sleep(2);
                    system("cls");
                    return size;
                }

                printf("\n ID do quarto: %c \033[31m(Liberar)\033[0m", guests[i].roomId);
                printf("\n-------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n============================================================");
                printf("\n Nome: %s", guests[i].name);
                printf("\n Idade: %d", guests[i].age);
                printf("\n ID: %c", guests[i].roomId);
                printf("\n============================================================\n");

                printf("\n\033[1;34mConfirmar liberação do quarto? [S/N]: \033[0m");
                char confirm;
                fflush(stdin);
                scanf("%c", &confirm);

                if (tolower(confirm) == 's') {
                    printf("\n\033[1;34mMENSAGEM:\033[0m Liberando quarto %c e removendo informações do hóspede, aguarde.\n", guests[i].roomId);

                    for (int j = i; j < size - 1; j++) {
                        guests[j] = guests[j + 1];
                    }

                    loading(100, "Carregando");

                    system("cls");
                    printf("\n\n \033[92m============================================\033[0m\n");
                    printf("  \033[92mMENSAGEM: Quarto liberado e informações do hóspede removidas com sucesso!\033[0m\n");
                    printf(" \033[92m============================================\033[0m\n\n");
                    sleep(2);

                    return size - 1; 
                } else {
                    printf("\n\n \033[93m============================================\033[0m\n");
                    printf("  \033[93mMENSAGEM: Liberação do quarto cancelada.\033[0m\n");
                    printf(" \033[93m============================================\033[0m\n\n");
                    sleep(2);

                    return size; 
                }
            }
        }


        printf("\n\n \033[91m============================================\033[0m\n");
        printf("  \033[91mMENSAGEM: Quarto não encontrado!\033[0m\n");
        printf(" \033[91m============================================\033[0m\n\n");
        sleep(2);

        return size;
    }

    // Voltar para o menu principal
    return 0;
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

        printf("\n-------------------------------------------------------------------------------------------------------------------------------");
        printf("\n|| T ||                                                QUARTOS DO HOTEL                                                 || T ||");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------");

        printf("\n|| 1 ||                                ");
        for(int i = 0; i < 13; i++){
            int found = 0;

            for(int j = 0; j < size; j++){
                if(guests[j].roomId == 'A'+ i){
                    found = 1;
                    break;
                }
            }
            if(found){
                printf("\033[31m| %c \033[0m", 'A'+ i);
                occupiedRoomsCount++;
            }else{
                printf("\033[32;1m| %c \033[0m", 'A'+ i);
                emptyRoomCount++;
            }
        }
        printf("                             || 1 ||\n");
        printf("|| 2 ||                                ");

        for(int i = 0; i < 13; i++){
            int found = 0;

            for(int j = 0; j < size; j++){
                if(guests[j].roomId == 'N'+ i){
                    found = 1;
                    break;
                }
            }
            if(found){
                printf("\033[31m| %c \033[0m", 'N'+ i);
                occupiedRoomsCount++;
            }else{
                printf("\033[32;1m| %c \033[0m", 'N'+ i);
                emptyRoomCount++;
            }
        }
        printf("                             || 2 ||");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------\n");

        printf("\n-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n                                          ============================================\n");
        printf("                                          || TOTAL DE QUARTOS:                   26 ||\n");
        printf("                                          ||----------------------------------------||\n");
        printf("                                          || \033[32;1mQUARTOS DISPONÍVEIS:                %.2d\033[0m ||\n", emptyRoomCount);
        printf("                                          ||----------------------------------------||\n");
        printf("                                          || \033[31mQUARTOS OCUPADOS:                   %.2d\033[0m ||\n", occupiedRoomsCount);
        printf("                                          ============================================\n");
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
