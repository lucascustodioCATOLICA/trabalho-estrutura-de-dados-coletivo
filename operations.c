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
    system("cls");

    int returnOption = 0;
    do{
        printf("\n\n------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                   [2] Listar hóspedes por ordem alfabética\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        printf("--> Digite o numero desejado: ");
        scanf("%d",&returnOption);
        
        if(returnOption != 2 && returnOption != 0){
            system("cls");
            printf("\a");
            printf("\n\n                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
            printf("\n                                      *** Opçaõ inválida, digite o numero '2' ou '0' ***");
            printf("\n                                 \033[1;31m============================================================\033[0m\n");
        }
    }while(returnOption != 2 && returnOption != 0);

    if(returnOption == 2){
        system("cls");
        printf("\n------------------------------------------------- Lista por ordem alfabética --------------------------------------------------\n");
        //for(int i = 0; Coloque as operações para o algoritmo executar o numero [2] ; i++){
            printf("\n          ============================================================================================================\n");
            printf("\n          \033[1m Nome:\033[0m %s"/*colocar a variavel do nome [i] do hospede da lista*/);
            printf("\n          \033[1m Idade:\033[0m %d"/*colocar a variavel do idade [i] do hospede da lsita*/);
            printf("\n          \033[1m ID do quarto:\033[0m %s \n"/*colocar a variavel do ID [i] do hospede da lsita*/);
            printf("\n          ============================================================================================================\n");
        //}
        printf("-------------------------------------------------------------------------------------------------------------------------------\n\n");

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

void getGuestByName(Guest* guests, int size)
{    
    system("cls");

    int returnOption = 0;
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
            system("cls");
            printf("\a");
            printf("\n\n                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
            printf("\n                                      *** Opçaõ inválida, digite o numero '3' ou '0' ***");
            printf("\n                                 \033[1;31m============================================================\033[0m");
        }
    }while(returnOption != 3 && returnOption != 0);

    if(returnOption == 3){
        system("cls");

        printf("\nDigite o nome do hóspede que deseja encontrar: ");
        //scanf....
        system("cls");
        //Coloque as operações para o algoritmo executar o numero [3]
        printf("\n\033[;34mMENSAGEM:\033[0m Buscando '%s' na lista, por favor aguarde.\n" /*colocar a variavel que guardou o nome do hospede a ser buscado*/);
        loading(150, "Carregando");
        
        //if(/*operação para o resultado encontrado*/){
            system("cls");
            printf("----------------------------------------------------- Resultado da busca ------------------------------------------------------\n");
            printf("\n                                 ============================================================");
            printf("\n                                 Nome:%s"/*colocar a variavel que encontrou o nome do hospede buscado*/);
            printf("\n                                 Idade:%d"/*colocar a variavel que encontrou a idade do hospede buscado*/);
            printf("\n                                 ID:%c"/*colocar a variavel que encontrou o ID do quarto do hospede buscado*/);
            printf("\n                                 ============================================================\n");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------\n\n");
        //}else{
            system("cls");
            printf("\a");
            printf("\n\n                                 \033[38;5;208m=================  HÓSPEDE NÃO ENCONTRADO  =================\033[0m");
            printf("\n                                     \033[38;5;208m*** Nome do hóspede não foi encontrado na lista ***\033[0m");
            printf("\n                                 \033[38;5;208m============================================================\033[0m\n\n\n");
            sleep(2);

            //colocar uma operação para voltar ao menu secundário
        //}
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
    do{
        printf("------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                   [4] Editar hóspede\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        printf("--> Digite o numero desejado: ");
        scanf("%d",&returnOption);

        if(returnOption != 4 && returnOption != 0){
            system("cls");
            printf("\a");
            printf("                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
            printf("\n                                      *** Opçaõ inválida, digite o numero '4' ou '0' ***");
            printf("\n                                 \033[1;31m============================================================\033[0m\n\n");
        }
    }while(returnOption != 4 && returnOption != 0);

    if(returnOption == 4){
        system("cls");

        printf("------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                 \033[1;34m->[4] Editar hóspede \033[0m\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("--> Digite o nome do hóspede que deseja editar: ");
        fflush(stdin);
        scanf("%s"/*completar*/);

        //Coloque as operações para o algoritmo executar o numero [4]

        system("cls");
        printf("\n\033[31mATENÇÃO:\033[0m Por favor, insira os dados em cada campo abaixo para ser editado.\n");
        //mude o nome 'pedro carneiro' para %s e a variavel que foi guardade no nome editado
        printf("\nPedro Carneiro \033[92m(Editar)\033[0m \n"); 
        printf("  -> Nome: ");
        scanf("%s"/*completar*/);
        printf("  -> Idade: ");
        scanf("%d"/*completar*/);
        printf("  -> ID do quarto: "); 
        scanf("%s"/*completar*/);
        system("cls");

        //modifique o 'x' para %s para imprimir o antigo nome do hospede e 'y' para %s para imprimer o novo nome do hospede
        printf("\n\033[1;34mMENSAGEM:\033[0m Editando x para y da lista, por favor aguarde.\n" /*colocar a variavel que guardou o nome do hospede escolhido para editar e outra variavel com nome já editado pelo usuario*/);
        loading(150, "Carregando");

        system("cls");

        printf("\n\n                                          \033[92m============================================\033[0m\n");
        printf("                                             \033[92mMENSAGEM: Hóspede editado com sucesso!\033[0m\n");
        printf("                                          \033[92m============================================\033[0m\n\n");
        sleep(1);
        printf("\n---------------------------------------------------- Atualização do hóspede ---------------------------------------------------");
        printf("\n                                 ============================================================");
        printf("\n                                  Nome: "/*colocar a variavel do novo nome do hospede*/);
        printf("\n                                  Idade: "/*colocar a variavel do novo idade do hospede*/);
        printf("\n                                  ID: "/*colocar a variavel do novo ID do quarto do hospede*/);
        printf("\n                                 ============================================================");
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

int removeGuest(Guest* guests, int size)
{
    system("cls");

    int returnOption = 0;
    do{
        printf("------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                   [5] Liberar um quarto\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        printf("--> Digite o numero desejado: ");
        scanf("%d",&returnOption);

        if(returnOption != 5 && returnOption != 0){
            system("cls");
            printf("\a");
            printf("                                 \033[1;31m==================   MENSAGEM DE ALERTA   ==================\033[0m");
            printf("\n                                      *** Opçaõ inválida, digite o numero '5' ou '0' ***");
            printf("\n                                 \033[1;31m============================================================\033[0m\n\n");
        }
    }while(returnOption != 5 && returnOption != 0);

    if(returnOption == 5){
        system("cls");

        printf("------------------------------------------------------- MENU SECUNDARIO -------------------------------------------------------\n");
        printf("                                 ============================================================\n");        
        printf("                                 \033[1;34m->[5] Liberar um quarto \033[0m\n");
        printf("                                   [0] Voltar para o menu principal\n");
        printf("                                 ============================================================\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("--> Digite o código do quarto: ");
        fflush(stdin);
        scanf("%s"/*completar*/);

        system("cls");
        //modifique o 'D' para %s para imprimir o ID do quarto digitado, claro, tambem coloque a variavel para imprimir o conteudo do %s
        printf("\n ID do quarto: D \033[31m(Liberar)\033[0m");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------\n");
        //for(int i = 0; Coloque as operações para o algoritmo executar e mostra as informações do quarto liberado ; i++){
            printf("\n============================================================");
            printf("\n Nome: "/*colocar a variavel do novo nome do hospede*/);
            printf("\n Idade: "/*colocar a variavel do novo idade do hospede*/);
            printf("\n ID: "/*colocar a variavel do novo ID do quarto do hospede*/);
            printf("\n============================================================\n");
        //}
        printf("\n-------------------------------------------------------------------------------------------------------------------------------\n");

        //Coloque as operações para o algoritmo executar o numero [5]
        printf("\033[1;34mMENSAGEM:\033[0m Liberando quarto %s da lista, por favor aguarde.\n" /*colocar a variavel que guardou o ID do quarto liberado*/);
        loading(150, "Carregando");

        system("cls");
        printf("\n\n                                          \033[92m============================================\033[0m\n");
        printf("                                             \033[92mMENSAGEM: Quarto liberado com sucesso!\033[0m\n");
        printf("                                          \033[92m============================================\033[0m\n\n");
        sleep(2);
        system("cls");
    }
    if(returnOption == 0){
        system("cls");
        return size;
    }
    return size-1;
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