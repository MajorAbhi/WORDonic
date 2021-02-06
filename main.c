#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

//Functions declarations
void display(void);
void userDecide(void);
void write(void);
void read(void);
void deleteFile(void);
void quitORnot(void);
void exit(int code);

//Global variables
bool windowClose = false;
int userCommand;

int main(void)
{
    while(!windowClose)
    {
        display();
        userDecide();
    }

    printf("\n\nThanks for Using our services\n");
    return 0;
}

//Function definitions

void display(void)
{
    printf("\n                                            Welcome to WORDonic - A Digital Pocket diary\n");
    printf("\n\nEnter...\n\n          1 - Write\n\n          2 - Read\n\n          3 - Delete\n\n          4 - Quit\n\n");
    printf("\nChoose your options appropiately...\n");
    printf("\n-> ");
}

void userDecide(void)
{
    scanf("%d", &userCommand); //usercommand stores the user's choice of options

    switch(userCommand)
    {
        case 1:
            system("cls");
            write();
        case 2:
            system("cls");
            read();
        case 3:
            system("cls");
            deleteFile();
        case 4:
            system("cls");
            exit(0);
    }
}
void write(void)
{
    char name[20];
    printf("\nEnter your Name\n-> ");
    scanf("%s", name);

    char date[10];
    printf("\nEnter today's Date in DD-MM-YY format. For example - 18-02-21\n-> ");
    scanf("%s", date);

    char message[500];
    printf("\nEnter your message (Not more than 500 words)\n->");
    gets(message);
    gets(message);

    //Storing the filename along with .txt extension
    char filename[30];
    sprintf(filename,"%s.txt",date); //sprintf stores the name of our file in the buffer (array filename);

    //To store author's name
    char author[25];
    sprintf(author, "Author: %s\n\n", name);

    //Code to write on the file
    FILE *ptr;
    ptr = fopen(filename, "w");

    fputs(author, ptr);
    fputs(message, ptr);
    fclose(ptr);

    printf("\nYour message have been saved successfully.\n");
    quitORnot();
}

void read(void)
{
    printf("Enter the date of which you want to read the diary in the DD-MM-YY format. For example: 01-11-2021\n-> ");
    char userDate[10]; //stores the date in the string format
    scanf("%s", userDate);

    //Required variables
    char message;
    char fileName[20];
    sprintf(fileName, "%s.txt", userDate); //Stores the userdate as a filename with .txt extension.

    //Open the file in Read mode
    FILE *ptr;
    ptr = fopen(fileName, "r");

    if(ptr == NULL)
    {
        printf("\nNo file was found with this name\n");
        exit(0);
    }
    else
    {
        //Enter the code here to read the contents of the file.
        puts("\n");
        while((message = fgetc(ptr)) != EOF)
        {
            printf("%c", message);
        }
        fclose(ptr);
        puts("\n");
        quitORnot();
    }
}
void deleteFile(void)
{
    printf("\nEnter the date of which DIARY you want to delete, in the DD-MM-YY format. For e.g: 01-11-21\n");

    //Storing the file name
    char name[10];
    gets(name);
    gets(name);

    //Storing the file name along with .txt extension
    char fileName[20];
    sprintf(fileName, "%s.txt", name);

    //Delete the file
    int fileRemove;
    fileRemove = remove(fileName);

    if(fileRemove == 0)
    {
        printf("\nThe file has been deleted successfully.\n");
    }
    else
    {
        printf("\nNo such file found. Make sure you entered the correct file name.\n");
    }
    quitORnot();
}

// To ask the user whether to quit or continue.
void quitORnot(void)
{
    int decision;
    puts("\nPLease Enter..\n\n    1 - To Continue\n    2 - To Quit\n");
    scanf("%d", &decision);

    if(decision == 1)
    {
        system("cls");
        main();
    }
    else
    {
        exit(0);
    }
}
