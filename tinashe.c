#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct clients{
    int accountNumber;
    char name[10];
    char type[10];
    int age;
    int dateOfBirth;
}c;

void store();
void search();
void print();
//nt
int main()
{

    printf("\n1.Add \n2.Search \n3.Print Clients \n Choose from the above:");
   int choice;
   scanf("%d", &choice);

   switch(choice) {

   case 1:
            store();
            break;
   case 2:search();break;
   case 3:print();break;

   default:printf("\a\a Invalid\a\a");
   }
}

void store()
{
    srand(time(0));
    c.accountNumber = rand();

    printf("Enter details for Account Number:%d\n ", c.accountNumber);

    printf("\n1.Name: ");
    scanf("%s",c.name);

    printf("\n2.Type: ");
    scanf("%s",c.type);

    printf("\n3.Age: ");
    scanf("%d",&c.age);

    printf("\n4.Birth Date in format ddmmyyyy without slashes: ");
    scanf("%d",&c.dateOfBirth);

    FILE *kuisaMuFaira;
    kuisaMuFaira = fopen("tinashe.doc", "a+");
    if(kuisaMuFaira == NULL)
    {
    printf("Failed to open File");
    }
    else{
    fprintf(kuisaMuFaira, "\n\n\nAccount Number: %d", c.accountNumber);
    fprintf(kuisaMuFaira, "\nName: %s", c.name);
    fprintf(kuisaMuFaira, "\nType: %s", c.type);
    fprintf(kuisaMuFaira, "\nAge: %d", c.age);
    fprintf(kuisaMuFaira, "\nDate of Birth: %d", c.dateOfBirth);

    }
}

void search()
{
    char search[10];

    printf("Enter search query:");
    scanf("%s",search);

    FILE *fp=fopen("tinashe.doc","r");
    char tmp[256]={0x0};
    while(fp && fgets(tmp, sizeof(tmp), fp))
    {
        int decision;
        char replace[10];
            if (strstr(tmp, search)){
            printf("%s found\n", search);
            printf("%s", tmp);
            printf("Do you like to edit 1-Yes 0-No");

            scanf("%d", &decision);
            if(decision == 1)
            {
            printf("Replace with: ");

            scanf("%s", replace);
            if(strcpy(tmp, replace))
                {printf("%s is replaced by %s\n", tmp, replace);}
            }
            }
    }
}

void print()
{
    printf("Details in file\n");
    char str;

    FILE *kuburitsaMuFaira;
    kuburitsaMuFaira = fopen("tinashe.doc", "r");

    if(kuburitsaMuFaira == NULL){
    printf("File not found or File empty\n");
    }

    else{

    while((str= fgetc(kuburitsaMuFaira))!=EOF){
    printf("%c", str);
    }
    }
}
