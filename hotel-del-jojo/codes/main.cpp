#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "customer.h"

void menu();
int getInt();
void printExitMessage();

// struct Customer{
//     int customer_id;
//     char customer_name[255];
//     int customer_age;
//     char customer_cause_of_death[255];
//     char customer_resting_place[255];
//     int customer_died_year;
//     int room_type_id;
// };

// struct RoomType{
//     int room_type_id;
//     char room_type_name[255];
//     unsigned int room_type_price;
// };

Customer list[255];
RoomType type[10];
int guests;
int cid;
int types;

void import_data_from_file(){
    FILE* fp = fopen("../customer/customer_data.txt", "r");
    FILE* fpp = fopen("../room/room.txt", "r");
    while(!feof(fp)){
        fscanf(fp, "C%d,%[^,],%d,%[^,],%[^,],%d,R%d\n", 
        &list[guests].customer_id, list[guests].customer_name,&list[guests].customer_age, list[guests].customer_cause_of_death,
        list[guests].customer_resting_place, &list[guests].customer_died_year,
        &list[guests].room_type_id);
        cid = list[guests].customer_id;
        guests++;
    }
    fclose(fp);
    while(!feof(fpp)){
        fscanf(fpp, "R%d,%[^,],%lu\n", &type[types].room_type_id,
        type[types].room_type_name, &type[types].room_type_price);
        types++;
    }
    fclose(fpp);
}



int main(){
    import_data_from_file();
    int choose;
    do
    {   
        system("clear");
        menu();
        printf("Choice [1-5] >> ");
        choose = getInt();
        switch (choose)
        {
        case 1:
            create(&guests, &types, type, list, &cid);
            break;
        case 2:
            read(guests, list, type);
            printf("Press enter to continue");getchar();
            break;
        case 3:
            update(guests, types, list, type);
            break;
        case 4:
            deldata(guests, list, type);
            break;
        case 5:
            printExitMessage();
            exit(0);
            break;
        default:
            break;
        }
    } while (choose!=5);
    return 0;
}

void printExitMessage(){
    FILE* fp = fopen("asciiart.txt", "r");
    char c = fgetc(fp);
    while(c!=EOF){
        printf("%c", c);
        if(c=='\n')usleep(60000);
        c = fgetc(fp);
    }
    fclose(fp);
    puts("");
    printf("Goodbye!");getchar();
}

int getInt(){
    int a;
    scanf("%d", &a);getchar();
    return a;
}

void menu(){
    puts("Hotel del Jojo");
    puts("1. Add new customer");
    puts("2. Read data");
    puts("3. Update data");
    puts("4. Remove data");
    puts("5. Exit");
}