#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char category[5][10] = {"Laptop", "PC", "Printer", "Modem", "Router"};
struct node
{
    char cust_name[100];
    char number[100];
    char type[100];
    char model[100];
    time_t current;
    char estimate[100];
    int bill;
    char warranty;
    struct node *next;
};
struct node *head = NULL;
void inward()
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp = NULL;
    int choice;
    printf("Customer Name:");
    fflush(stdin);
    gets(new->cust_name);
    printf("Customer Number:");
    fflush(stdin);
    gets(new->number);
    printf("Select the category from the options below:\n");
    printf("1.Laptop\n");
    printf("2.PC\n");
    printf("3.Printer\n");
    printf("4.Modem\n");
    printf("5.Router\n");
    printf("-->");
    scanf("%d", &choice);
    strcpy(new->type, category[choice - 1]);
    printf("Model:");
    fflush(stdin);
    gets(new->model);
    time(&new->current);
    printf("Date of entry: %s\n", ctime(&new->current));
    printf("Estimated date of completion:");
    fflush(stdin);
    gets(new->estimate);
    printf("Is product under warranty(y/n):");
    scanf("%c", &new->warranty);
    if (new->warranty == 'y')
    {
        new->bill = 0;
    }
    else
    {
        printf("Enter the Billing Amount including GST:");
        scanf("%d", &new->bill);
    }
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
    printf("DATA SUCCESSFULLY UPDATED !!!\n\n");
}
void outward()
{
    struct node *temp1 = NULL;
    struct node *temp2 = NULL;
    char name[100];
    char number[100];
    char model[100];
    char op;
    temp1 = head;
    if (head == NULL)
    {
        printf("No Outwards Remaining\n\n");
    }
    else
    {
        printf("Name of the customer:");
        fflush(stdin);
        gets(name);
        printf("Mobile number:");
        fflush(stdin);
        gets(number);
        printf("Model of the item:");
        fflush(stdin);
        gets(model);
        if (strcmp(head->cust_name, name) == 0 && strcmp(head->number, number) == 0 &&
            strcmp(head->model, model) == 0)
        {
            printf("Customer Name:%s\n", head->cust_name);
            printf("Customer Mobile Number:%s\n", head->number);
            printf("Category:%s\n", head->type);
            printf("Model:%s\n", head->model);
            printf("Time of Registration:%s\n", ctime(&head->current));
            printf("Billing Amount:%d\n", head->bill);
            printf("Is the outward final?(y/n):");
            scanf("%c", &op);
            if (op == 'y')
            {
                head = head->next;
                free(temp1);
                printf("Successful ! \n\n");
            }
            else
            {
                printf("Outward Cancelled\n\n");
            }
        }
        else
        {
            while (strcmp(temp1->cust_name, name) != 0 &&
                   strcmp(temp1->number, number) != 0 && strcmp(temp1->model, model) != 0)
            {
                if (strcmp(temp1->next->cust_name, name) == 0 &&
                    strcmp(temp1->next->number, number) == 0 &&
                    strcmp(temp1->next->model, model) == 0)
                {
                    temp2 = temp1;
                }
                temp1 = temp1->next;
            }
            printf("Customer Name:%s\n", temp1->cust_name);
            printf("Customer Mobile Number:%s\n", temp1->number);
            printf("Category:%s\n", temp1->type);
            printf("Model:%s\n", temp1->model);
            printf("Time of Registration:%s\n", ctime(&temp1->current));
            printf("Billing Amount:%d\n", temp1->bill);
            printf("Is the outward final?(y/n):");
            scanf("%c", &op);
            if (op == 'y')
            {
                temp2->next = temp1->next;
                free(temp1);
                printf("Successful ! \n\n");
            }
            else
            {
                printf("Outward Cancelled\n\n");
            }
        }
    }
}
void display()
{
    struct node *temp3 = NULL;
    int i = 1;
    temp3 = head;
    if (head == NULL)
    {
        printf("No Outwards Remain !\n");
    }
    else
    {
        while (temp3 != NULL)
        {
            printf("%d)\n", i);
            printf("\tCustomer Name:%s\n", temp3->cust_name);
            printf("\tCustomer Mobile Number:%s\n", temp3->number);
            printf("\tCategory:%s\n", temp3->type);
            printf("\tModel:%s\n", temp3->model);
            printf("\tTime of Registration:%s\n", ctime(&temp3->current));
            printf("\tEstimated Time of Completion:%s\n", temp3->estimate);
            printf("\tWarranty Status:%c\n", temp3->warranty);
            printf("\tBilling Amount:%d\n", temp3->bill);
            printf("\n\n");
            temp3 = temp3->next;
            i++;
        }
    }
}
void search()
{
    struct node *temp = NULL;
    char name[100];
    char number[100];
    temp = head;
    if (head == NULL)
    {
        printf("No Outwards remaining.\n");
    }
    else
    {
        printf("Name of the customer:");
        fflush(stdin);
        gets(name);
        printf("Mobile number of the customer:");
        fflush(stdin);
        gets(number);
        if (strcmp(head->cust_name, name) == 0 && strcmp(head->number, number) == 0)
        {
            printf("Customer Name:%s\n", head->cust_name);
            printf("Customer Mobile Number:%s\n", head->number);
            printf("Category:%s\n", head->type);
            printf("Model:%s\n", head->model);
            printf("Time of Registration:%s\n", ctime(&head->current));
        }
        else
        {
            while (temp != NULL)
            {
                if (strcmp(temp->cust_name, name) == 0 &&
                    strcmp(temp->number, number) == 0)
                {
                    printf("Customer Name:%s\n", temp->cust_name);
                    printf("Customer Mobile Number:%s\n", temp->number);
                    printf("Category:%s\n", temp->type);
                    printf("Model:%s\n", temp->model);
                    printf("Time of Registration:%s\n", ctime(&temp->current));
                    break;
                }
                temp = temp->next;
            }
        }
    }
}
void update()
{
    struct node *temp = NULL;
    char name[100];
    char number[100];
    temp = head;
    int op = 0;
    int choice;
    if (head == NULL)
    {
        printf("No Outwards remaining.\n");
    }
    else
    {
        printf("Name of the customer:");
        fflush(stdin);
        gets(name);
        printf("Mobile number of the customer:");
        fflush(stdin);
        gets(number);
        if (strcmp(head->cust_name, name) == 0 && strcmp(head->number, number) == 0)
        {
            printf("Customer Name:%s\n", head->cust_name);
            printf("Update Name ?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            printf("-->");
            scanf("%d", &op);
            if (op == 1)
            {
                printf("Enter new name:");
                fflush(stdin);
                gets(head->cust_name);
            }
            printf("Customer Mobile Number:%s\n", head->number);
            printf("Update Number?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            scanf("-->");
            scanf("%d", &op);
            if (op == 1)
            {
                printf("Enter new number:");
                fflush(stdin);
                gets(head->number);
            }
            printf("Category:%s\n", head->type);
            printf("Update Category?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            scanf("-->");
            scanf("%d", &op);
            if (op == 1)
            {
                printf("Select the category from the options below:\n");
                printf("1.Laptop\n");
                printf("2.PC\n");
                printf("3.Printer\n");
                printf("4.Modem\n");
                printf("5.Router\n");
                printf("-->");
                scanf("%d", &choice);
                strcpy(head->type, category[choice - 1]);
            }
            printf("Model:%s\n", head->model);
            printf("Update Model?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            printf("-->");
            scanf("%d", &op);
            if (op == 1)
            {
                printf("Enter new Model:");
                fflush(stdin);
                gets(head->model);
            }
            printf("Estimated Time of Completion:%s\n", head->estimate);
            printf("Update Estimated Time ?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            printf("-->");
            scanf("%d", &op);
            if (op == 1)
            {
                printf("Enter new estimated time of completion:");
                fflush(stdin);
                gets(head->estimate);
            }
            printf("Warranty Status:%c\n", head->warranty);
            printf("Update Warranty Status ?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            printf("-->");
            scanf("%d", &op);
            if (op == 1)
            {
                if (head->warranty == 'y')
                {
                    head->warranty = 'n';
                }
                else
                {
                    head->warranty = 'y';
                }
            }
            printf("Billing Amount:%d\n", head->bill);
            printf("Update Bill?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            printf("-->");
            scanf("%d", &op);
            if (op == 1)
            {
                printf("Enter new Bill amount including GST:");
                scanf("%d", &head->bill);
            }
        }
        else
        {
            while (temp != NULL)
            {
                if (strcmp(temp->cust_name, name) == 0 &&
                    strcmp(temp->number, number) == 0)
                {
                    printf("Customer Name:%s\n", temp->cust_name);
                    printf("Update Name ?\n");
                    printf("1.Yes\n");
                    printf("2.No\n");
                    printf("-->");
                    scanf("%d", &op);
                    if (op == 1)
                    {
                        printf("Enter new name:");
                        fflush(stdin);
                        gets(temp->cust_name);
                    }
                    printf("Customer Mobile Number:%s\n", temp->number);
                    printf("Update Number?\n");
                    printf("1.Yes\n");
                    printf("2.No\n");
                    scanf("-->");
                    scanf("%d", &op);
                    if (op == 1)
                    {
                        printf("Enter new number:");
                        fflush(stdin);
                        gets(temp->number);
                    }
                    printf("Category:%s\n", temp->type);
                    printf("Update Category?\n");
                    printf("1.Yes\n");
                    printf("2.No\n");
                    scanf("-->");
                    scanf("%d", &op);
                    if (op == 1)
                    {
                        printf("Select the category from the options below:\n");
                        printf("1.Laptop\n");
                        printf("2.PC\n");
                        printf("3.Printer\n");
                        printf("4.Modem\n");
                        printf("5.Router\n");
                        printf("-->");
                        scanf("%d", &choice);
                        strcpy(temp->type, category[choice - 1]);
                    }
                    printf("Model:%s\n", temp->model);
                    printf("Update Model?\n");
                    printf("1.Yes\n");
                    printf("2.No\n");
                    printf("-->");
                    scanf("%d", &op);
                    if (op == 1)
                    {
                        printf("Enter new Model:");
                        fflush(stdin);
                        gets(temp->model);
                    }
                    printf("Estimated Time of Completion:%s\n", temp->estimate);
                    printf("Update Estimated Time ?\n");
                    printf("1.Yes\n");
                    printf("2.No\n");
                    printf("-->");
                    scanf("%d", &op);
                    if (op == 1)
                    {
                        printf("Enter new estimated time of completion:");
                        fflush(stdin);
                        gets(temp->estimate);
                    }
                    printf("Warranty Status:%c\n", temp->warranty);
                    printf("Update Warranty Status ?\n");
                    printf("1.Yes\n");
                    printf("2.No\n");
                    printf("-->");
                    scanf("%d", &op);
                    if (op == 1)
                    {
                        if (temp->warranty == 'y')
                        {
                            temp->warranty = 'n';
                        }
                        else
                        {
                            temp->warranty = 'y';
                        }
                    }
                    printf("Billing Amount:%d\n", temp->bill);
                    printf("Update Bill?\n");
                    printf("1.Yes\n");
                    printf("2.No\n");
                    printf("-->");
                    scanf("%d", &op);
                    if (op == 1)
                    {
                        printf("Enter new Bill amount including GST:");
                        scanf("%d", &temp->bill);
                    }
                }
                temp = temp->next;
            }
        }
    }
}
void main()
{
    int op = 1;
    while (op != 6)
    {
        printf("\\============ AIP XPERTS TECHNOLABS ============/\n\n");
        printf("\t\t1.New Inward\n");
        printf("\t\t2.New Outward\n");
        printf("\t\t3.Show all cases\n");
        printf("\t\t4.Search a case\n");
        printf("\t\t5.Update a case\n");
        printf("\t\t6.Exit\n");
        printf("\t\t-->");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            inward();
            break;
        case 2:
            outward();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            update();
            break;
        }
    }
}