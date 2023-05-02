#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 500
int ID = 0;

struct Info {
    bool flag;
    char id[5];
    char name[100];
    char phoneNumber[20];
    char email[100];
    char paymentMethod[10];
    char transactionId[20];
} info[SIZE];

void entryAPass();

void printAPass(int id);

void editAPass(int id);

void deleteAPass(int id);

int main() {
    int choice;

    while (1) {
        printf("\n\n"
               "=====Iftar Party Entry Pass: Admin Panel=====\n"
               "  1. Entry a Pass.\n"
               "  2. Print a Pass.\n"
               "  3. Edit a Pass.\n"
               "  4. Delete a Pass.\n"
               "  0. Exit\n"
               "Enter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            entryAPass();
        } else if (choice == 2) {
            int id;
            printf("\n\n"
                   "Enter Id for Print a Pass: ");
            scanf("%d", &id);
            getchar();
            printAPass(id);
        } else if (choice == 3) {
            int id;
            printf("\n\n"
                   "Enter Id for Edit a Pass: ");
            scanf("%d", &id);
            getchar();
            editAPass(id);
        } else if (choice == 4) {
            int id;
            printf("\n\n"
                   "Enter Id for Delete a Pass: ");
            scanf("%d", &id);
            getchar();
            deleteAPass(id);
        }
    }

    return 0;
}

void entryAPass() {
    printf("\n\n");

    info[ID].flag = true;

    char x[5];
    if (ID >= 0 && ID <= 9) {
        sprintf(x, "%d", ID);
        strcpy(info[ID].id, "000");
        strcat(info[ID].id, x);
    } else if (ID >= 10 && ID <= 99) {
        sprintf(x, "%d", ID);
        strcpy(info[ID].id, "00");
        strcat(info[ID].id, x);
    } else if (ID >= 100 && ID <= 999) {
        sprintf(x, "%d", ID);
        strcpy(info[ID].id, "0");
        strcat(info[ID].id, x);
    } else if (ID >= 1000 && ID <= 9999) {
        sprintf(x, "%d", ID);
        strcat(info[ID].id, x);
    }

    printf("Name: ");
    scanf(" %[^\n]", info[ID].name);

    printf("Phone Number: ");
    scanf(" %[^\n]", info[ID].phoneNumber);

    printf("Email: ");
    scanf(" %[^\n]", info[ID].email);

    int paymentMethod;
    printf("Payment Method:\n"
           "  1. bKash\n"
           "  2. Nagad\n"
           "  3. Rocket\n"
           "  4. Cash\n"
           "Enter Your Choice: ");
    scanf("%d", &paymentMethod);
    getchar();
    if (paymentMethod == 1) {
        strcpy(info[ID].paymentMethod, "bKash");
    } else if (paymentMethod == 2) {
        strcpy(info[ID].paymentMethod, "Nagad");
    } else if (paymentMethod == 3) {
        strcpy(info[ID].paymentMethod, "Rocket");
    } else if (paymentMethod == 4) {
        strcpy(info[ID].paymentMethod, "Cash");
    }

    if (paymentMethod == 1 || paymentMethod == 2 || paymentMethod == 3) {
        printf("Transaction Id: ");
        scanf(" %[^\n]", info[ID].transactionId);
    } else if (paymentMethod == 4) {
        strcpy(info[ID].transactionId, "");
    }

    printAPass(ID);

    ID++;
}

void printAPass(int id) {
    printf("\n\n");

    if (info[id].flag) {
        printf("=============================================================\n");
        printf("== %27s %-28s==\n", "Ifter Party", "Entry Pass");
        printf("== %27s %-28s==\n", "", "");
        printf("==  %-20s%-35s==\n", "ID:", info[id].id);
        printf("==  %-20s%-35s==\n", "Name:", info[id].name);
        printf("==  %-20s%-35s==\n", "Phone Number:", info[id].phoneNumber);
        printf("==  %-20s%-35s==\n", "Email:", info[id].email);
        printf("==  %-20s%-35s==\n", "Payment Method:", info[id].paymentMethod);

        if (strcmp(info[id].paymentMethod, "Cash") == 0)
            printf("==  %-20s%-35s==\n", "Transaction Id:", "NaN");
        else
            printf("==  %-20s%-35s==\n", "Transaction Id:", info[id].transactionId);

        printf("=============================================================\n");

        char fileName[10];
        strcpy(fileName, info[id].id);
        strcat(fileName, ".txt");

        FILE *file = fopen(fileName, "w");

        fprintf(file, "=============================================================\n");
        fprintf(file, "== %27s %-28s==\n", "Ifter Party", "Entry Pass");
        fprintf(file, "== %27s %-28s==\n", "", "");
        fprintf(file, "==  %-20s%-35s==\n", "ID:", info[id].id);
        fprintf(file, "==  %-20s%-35s==\n", "Name:", info[id].name);
        fprintf(file, "==  %-20s%-35s==\n", "Phone Number:", info[id].phoneNumber);
        fprintf(file, "==  %-20s%-35s==\n", "Email:", info[id].email);
        fprintf(file, "==  %-20s%-35s==\n", "Payment Method:", info[id].paymentMethod);

        if (strcmp(info[id].paymentMethod, "Cash") == 0)
            fprintf(file, "==  %-20s%-35s==\n", "Transaction Id:", "NaN");
        else
            fprintf(file, "==  %-20s%-35s==\n", "Transaction Id:", info[id].transactionId);

        fprintf(file, "=============================================================\n");

        fclose(file);
    } else {
        printf("Information Does Not Exist\n");
    }
}

void editAPass(int id) {
    printf("\n\n");

    if (info[id].flag) {
        int choice;

        printf("What Do You Want to Edit:\n"
               " 1. Name\n"
               " 2. Phone Number\n"
               " 3. Email\n"
               "Enter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Name: ");
            scanf(" %[^\n]", info[id].name);
        } else if (choice == 2) {
            printf("Phone Number: ");
            scanf(" %[^\n]", info[id].phoneNumber);
        } else if (choice == 3) {
            printf("Email: ");
            scanf(" %[^\n]", info[id].email);
        }

        printf("Information Edited Successfully!\n");
    } else {
        printf("Information Does Not Exist\n");
    }
}

void deleteAPass(int id) {
    printf("\n\n");

    info[id].flag = false;

    printf("Information Deleted Successfully!\n");
}
