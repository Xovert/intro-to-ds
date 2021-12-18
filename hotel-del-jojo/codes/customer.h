void menu();
int getInt();
void printExitMessage();
void create(Customer* list);
void read();
void update();
void remove();
// prototype functions

// input new customer
void create(Customer* list){
    char input[255] = {};
    bool islower = true;
    do{
        islower = true;
        printf("Name (lowercase letters): ");
        scanf("%[^\n]", input);getchar();
        for(int i = 0; i<strlen(input); i++){
            if(isupper(input[i])){
                islower = false;
                break;
            }
        }
    }while(!islower);
    int age;
    do{
        printf("Age (0 - 100): ");
        scanf("%d", &age);getchar();
    }while (age<0||age>100);
    char death[257] = {};
    do
    {
        printf("Cause of Death (max 255 letters): ");
        scanf("%[^\n]", death);getchar();
    } while (strlen(death)>255);
    char rest[257] = {};
    do
    {
        printf("Resting Place (max 255 letters): ");
        scanf("%[^\n]", rest);getchar();
    } while (strlen(rest)>255);
    int year = 0;
    printf("Input year of death (YYYY): ");
    scanf("%d", &year);getchar();
    char roomtype[255] = {};
    bool exist = true;
    do
    {
        roomtype[255] = {};
        exist = false;
        printf("Room Type (Pantai, Rooftop, Taman, Bar): ");
        scanf("%[^\n]", roomtype);getchar();
        if((strcmp(roomtype, "Pantai") == 0)||(strcmp(roomtype, "Rooftop") == 0)||(strcmp(roomtype, "Taman")==0)||(strcmp(roomtype, "Bar")==0)){
            exist = true;
        }
    } while (!exist);
    char rno[25] = {};
    for(int i = 0; i<(types); i++){
        if(strcmp(roomtype, type[i].room_type_name)==0){
            sprintf(rno,"R%.3d",type[i].room_type_id);
            list->room_type_id = type[i].room_type_id;
            break;
        }
    }
    strcpy(list->customer_name, input);
    list->customer_age = age;
    strcpy(list->customer_cause_of_death, death);
    strcpy(list->customer_resting_place, rest);
    list->customer_died_year = year;
    (cid)++;
    list->customer_id = (cid);
    (guests)++;
    FILE* fp = fopen("../customer/customer_data.txt", "a");
    fprintf(fp, "C%.3d,%s,%d,%s,%s,%d,%s\n", cid, input, age, death, rest, year, rno);
    fclose(fp);
    puts("");
    puts("Welcome to Hotel del Jojo!");getchar();
}

// display data
void read(){
    puts("|   | ID   | Name       | Age | Room     |");
    puts("|---|------|------------|-----|----------|");
    int no = 0;
    for(int i = 0; i<guests; i++){
        if(list[i].customer_id!=0){
            no++;
            printf("| %-2d| C%.3d | %-10s | %-3d | %-8s |\n", no, list[i].customer_id,
            list[i].customer_name, list[i].customer_age, type[(list[i].room_type_id)-1].room_type_name);
        }
    }
    puts("");
}

// update data
void update(){
    read();
    int id;
    int exist = 0;
    int idx = 0;
    do{
        exist = 0;
        printf("Enter ID: ");
        scanf("C%d", &id);getchar();
        for(int i = 0; i<guests; i++){
            if(id==list[i].customer_id){
                idx = i;
                exist = 1;
                break;
            }
        }
    }while (!exist);
    char roomtype[255] = {};
    do
    {
        roomtype[255] = {};
        exist = 0;
        printf("Insert New Room (Pantai, Rooftop, Taman, Bar): ");
        scanf("%[^\n]", roomtype);getchar();
        if((strcmp(roomtype, "Pantai") == 0)||(strcmp(roomtype, "Rooftop") == 0)||(strcmp(roomtype, "Taman")==0)||(strcmp(roomtype, "Bar")==0)){
            exist = 1;
        }
    } while (!exist);
    for(int i = 0; i<types; i++){
        if(strcmp(roomtype, type[i].room_type_name)==0){
            list[idx].room_type_id = type[i].room_type_id;
            break;
        }
    }
    FILE* fp = fopen("../customer/customer_data.txt", "w");
    for(int i = 0; i<guests; i++){
        if(list[i].customer_id!=0){
            fprintf(fp, "C%.3d,%s,%d,%s,%s,%d,R%.3d\n", 
            list[i].customer_id, list[i].customer_name, list[i].customer_age, list[i].customer_cause_of_death,
            list[i].customer_resting_place, list[i].customer_died_year,
            list[i].room_type_id);
        }
    }
    fclose(fp);
    puts("");
    printf("Data Updated for Customer ID C%.3d!\n", id);
    printf("Would you like to see the updated data? [Y/N]: ");
    char x = 0;
    do{
       x = 0;
       scanf("%c", &x);getchar(); 
       toupper(x);
    }while(!(x!='Y'||x!='N'));
    switch (x){
    case 'Y':
        system("clear");
        read();
        printf("Press Enter to Continue...");getchar();
        break;
    case 'N':
        return;
    }
}

// remove data
void remove(){
    read();
    int id;
    int exist = 0;
    int idx = 0;
    do{
        exist = 0;
        printf("Enter ID: ");
        scanf("C%d", &id);getchar();
        for(int i = 0; i<guests; i++){
            if(id==list[i].customer_id){
                idx = i;
                exist = 1;
                break;
            }
        }
    }while (!exist);
    list[idx].customer_id = 0;
    FILE* fp = fopen("../customer/customer_data.txt", "w");
    for(int i = 0; i<guests; i++){
        if(list[i].customer_id!=0){
            fprintf(fp, "C%.3d,%s,%d,%s,%s,%d,R%.3d\n", 
            list[i].customer_id, list[i].customer_name, list[i].customer_age, list[i].customer_cause_of_death,
            list[i].customer_resting_place, list[i].customer_died_year,
            list[i].room_type_id);
        }
    }
    fclose(fp);
    printf("Customer Data with ID C%.3d has been deleted!\n", id);
    printf("Would you like to see the updated data? [Y/N]: ");
    char x = 0;
    do{
       x = 0;
       scanf("%c", &x);getchar(); 
       toupper(x);
    }while(!(x!='Y'||x!='N'));
    switch (x){
    case 'Y':
        system("clear");
        read();
        printf("Press Enter to Continue...");getchar();
        break;
    case 'N':
        return;
    }
}

// getter Integer
int getInt(){
    int a;
    scanf("%d", &a);getchar();
    return a;
}
