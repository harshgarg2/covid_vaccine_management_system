#include <iostream>
#include <fstream>
#include <iomanip>
#include "searching.h"
#include<conio.h>
#define center 50
using namespace std;
class record
{
public:
    int vaccine_code;
    char name_of_vaccine[40];
    long quantity;
    int gap_bw_dose;
};
int search_specific_vaccine(int);
int vaccine_inventory();
int first_menu()
{
    system("cls");
    goto_xy(1, center);
    printf(" *** VACCINATION RECORDS *** ");
    goto_xy(5, center);
    goto_xy(1, center);
    printf("1. CHECK RECORD OF VACCINATED PEOPLE");
    goto_xy(1, center);
    printf("2. Add New Vaccines");
    goto_xy(1, center);
    printf("3. Show Available Vaccines");
    goto_xy(1, center);
    printf("4. Search Vaccine");
    goto_xy(1, center);
    printf("5. Update Vaccine Quantity");
    goto_xy(1, center);
    printf("6. Back to previous menu");
    cout << endl<< "Choose the operation you wants to perform : ";
    getch();
    vaccine_inventory();

}
void add_new()
{
    system("cls");
    goto_xy(1, center);
    cout << "ADD NEW VACCINE TO INVENTORY";
    goto_xy(1, center);
    FILE *fp;
    record r;
    fp = fopen("vaccine.txt", "a");
    char c = 'y';
    while (c == 'y' || c == 'Y')
    {
        goto_xy(1, center);
        printf("Enter name of the vaccine:  ");
        fflush(stdin);
        cin>> r.name_of_vaccine;
        goto_xy(1, center);
        printf("Enter vaccine code:  ");
        cin >> r.vaccine_code;
        goto_xy(1, center);
        printf("Enter initial quantity of vaccine :  ");
        scanf("%ld", &r.quantity);
        goto_xy(1, center);
        printf("Enter gap between two dose of this vaccine : ");
        scanf("%d", &r.gap_bw_dose);
        fwrite(&r, sizeof(r), 1, fp);
        goto_xy(1, center);
        printf("Your data of vaccine is inserted");
        goto_xy(1, center);
        printf("Do you want to add more Y|N  :    ");
        cin >> c;
        fflush(stdin);
    }
    fclose(fp);
    goto_xy(1, center);
    cout << endl
         << "Enter to continue....";
    getch();
}
void show_available_vaccine()
{
    FILE *fp;
    record r;
    system("cls");
    fp = fopen("vaccine.txt", "r");
    goto_xy(1, center);
    printf("List of All Vaccines");
    if (fp == NULL)
    {
        goto_xy(1, center);
        printf("Data is not created yet");
    }
    else
    {
        goto_xy(1, center);
        printf("Vaccine name           Vaccine code        Available quantity");
        goto_xy(1, center);
        printf("---------------------------------------------------------------");
        int i = 10;
        while (fread(&r, sizeof(r), 1, fp))
        {
            goto_xy(1, center);
            cout << r.name_of_vaccine;
            goto_xy(0, 25 - strlen(r.name_of_vaccine));
            cout << r.vaccine_code;
            string e = to_string(r.vaccine_code);
            goto_xy(0,23 - e.size());
            cout << r.quantity;
           i++;
        }
    }
    fclose(fp);
    goto_xy(1, center);
    cout<<endl<<"Enter to continue......";
    getch();
}

void search()
{
    int c;
    int flag = 0;
    system("cls");
    goto_xy(2, center);
    cout << "VIEW VACCINE DETAILS BY VACCINE CODE";
    goto_xy(2, center);
    printf("Enter vaccine code to be searched:  ");
    scanf("%d", &c);
    flag = search_specific_vaccine(c);
    if (flag == 0)
    {
        goto_xy(2, center);
        printf("Vaccine code is not found please enter valid vaccine code...");
    }
    cout << endl
         << "Enter to continue.......";
    getch();
}
int search_specific_vaccine(int code)
{
    FILE *fp;
    record r;
    fp = fopen("vaccine.txt", "r");
    if (fp == NULL)
    {
        goto_xy(4, center);
        printf("Data is not created yet");
    }
    else
    {
        while (fread(&r, sizeof(r), 1, fp))
        {
            if (code == r.vaccine_code)
            {
                goto_xy(1, center);
                cout << "Vaccine Name : " << r.name_of_vaccine;
                goto_xy(1, center);
                cout << "Vaccine Code : " << r.vaccine_code;
                goto_xy(1, center);
                cout << "Available Quantity : " << r.quantity;
                goto_xy(1, center);
                cout << "Gap between dose : " << r.gap_bw_dose;
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}
void update_vaccine_quantity()
{
    FILE *fp;
    long q;
    int code;
    int flag = 0;
    system("cls");
    fp = fopen("vaccine.txt", "r+");
    record r;
    goto_xy(1, center);
    cout << "UPDATE VACCINE QUANTITY ";
    goto_xy(1, center);
    printf("Enter the vaccine code to update : ");
    scanf("%d", &code);
    while (fread(&r, sizeof(r), 1, fp))
    {
        if (code == r.vaccine_code)
        {
            goto_xy(1, center);
            printf("Enter quantity to be added: ");
            scanf("%ld", &q);
            r.quantity = q + r.quantity;
            fseek(fp, -(long)sizeof(r), 1);
            fwrite(&r, sizeof(r), 1, fp);
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        goto_xy(1, center);
        printf("New Quantity added");
    }
    else
    {
        goto_xy(1, center);
        printf("Vaccine code not found");
    }
    fclose(fp);
    cout<<endl<<"Enter to continue.....";
    getch();
}
int vaccine_inventory()
{
    int ch;
    cin>>ch;
    while (1)
    {
        switch (ch)
        {
        case 1:
            search_menu();
            break;
        case 2:
            add_new();
            break;
        case 3:
            show_available_vaccine();
            break;
        case 4:
            search();
            break;
        case 5:
            update_vaccine_quantity();
            break;
        case 6:
             return 0;
            break;
        }
        first_menu();

    }

}
