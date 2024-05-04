#include "operations.h"

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
    return;
}

void saveFile(Guest* guests, int size)
{
    sort(guests, size);
    writeFile(guests, size);
    return;
}