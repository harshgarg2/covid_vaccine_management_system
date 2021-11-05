#include <iostream>
#include "enter_spaces.h"
using namespace std;
void vaccine_management();
void rapid_covid_test()
{
    system("cls");
    char a, b, c, d, e, f;
    string name;
    string state;
    int i, j = 1, age, x, count = 0, p;
    goto_xy(5, center);
    cout << "**** RAPID COVID TEST ****";
    goto_xy(5, center);
    printf("PLEASE ENTER YOUR BASIC INFORMATION");
    goto_xy(2, center);
    printf("NAME:- ");
    fflush(stdin);
    getline(cin, name);
    goto_xy(1, center);
    printf("AGE:- ");
    scanf("%d", &age);
    if (age <= 13 || age >= 50)
    {
        count += 1;
    }
    goto_xy(1, center);
    printf("STATE:- ");
    fflush(stdin);
    getline(cin, state);
    goto_xy(1, center);

    printf("PLEASE ANSWER THE FOLLOWING QUESTION CORRECTLY\n");
    goto_xy(1, center);
    printf("NOTE :- IF YOU ARE IN RED ZONE THEN YOU CANNOT GET VACCINATION");
    goto_xy(3, center);
    printf("Do you have any travel history across INDIA between jan to mar?(y/n)");
    goto_xy(1, center);
    printf("Ans :- ");
    fflush(stdin);
    scanf("%c", &a);
    if (a == 'y' || a == 'Y')
        count += 1;

    goto_xy(1, center);
    printf("Do you came in contact with any covid infected parson?(y/n)");
    goto_xy(1, center);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &b);
    if (b == 'y' || b == 'Y')
    {
        count += 1;
    }
    goto_xy(1, center);
    printf("Is there any covid patient in the range of 1 km?(y/n)");
    goto_xy(1, center);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        count += 1;
    }
    goto_xy(1, center);
    printf("Are you suffering of any kind of diseases like CANCER,DIABETES?(y/n)");
    goto_xy(1, center);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &d);
    if (d == 'y' || d == 'Y')
    {
        count += 1;
    }
    goto_xy(1, center);
    printf("Please let us know your body temperature(in C)");
    goto_xy(1, center);
    printf("Ans :-");
    scanf("%d", &x);
    if (x >= 38)
    {
        count += 1;
    }
    goto_xy(1, center);
    printf("If you are suffering from any one write (y\n)");
    goto_xy(1, center);
    printf("1) Dry cough");
    goto_xy(1, center);
    printf("2) Shortness of breath");
    goto_xy(1, center);
    printf("3) Headaches");
    goto_xy(1, center);
    printf("4) Aches and Pains");
    goto_xy(1, center);
    printf("5) Sore throat");
    goto_xy(1, center);
    printf("6) fatigue");
    goto_xy(1, center);
    printf("7) Diarrhea ");
    goto_xy(2, center);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &e);
    if (e == 'y' || e == 'Y')
    {
        count += 1;
    }
    goto_xy(1, center);
    printf("Are you suffering from bp or suger problem?(y/n) ");
    goto_xy(1, center);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &f);
    if (f == 'y' || f == 'Y')
    {
        count += 1;
    }
    goto_xy(1, center);
    printf("..................PLEASE WAIT WHILE WE ARE ANALYSING DATA ");
    int choice=1;
    system("cls");
        goto_xy(1, center);
        printf(" REPORT DETAILS");
        goto_xy(1, center);
        cout << "Name : " << name;
        goto_xy(1, center);
        cout << "Age : " << age;
        goto_xy(1, center);
        cout << "State : " << state;
        count = count * 10;
        goto_xy(2, center);
        printf("YOUR RATE OF BEING INFECTED IS %d percent ", count);
        if (count <= 20)
        {
            goto_xy(1, center);
            printf("CONGRATS! YOU ARE IN GREEN ZONE ");
            goto_xy(1, center);
            printf("STAY HOME STAY SAFE");
            goto_xy(1, center);
            cout << "CONGRATS YOU ARE ELIGIBLE FOR VACCINATION DRIVE ";
            goto_xy(1, center);
            cout << "1)  FOR VACCINATION   \t  2) MAIN MENU     ";

            goto_xy(1, center);
            cout << "PLEASE ENETR YOUR CHOICE :- ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                vaccine_management();
                break;
            case 2:
                break;
            default:
                goto_xy(1, center);
                cout << "Please insert valid choice ! ";
                goto_xy(1, center);


            }
        }

        else if (count >= 20 && count <= 40)
        {
            goto_xy(1, center);
            printf("YOU ARE IN ORANGE ZONE ");
            goto_xy(1, center);
            printf("STAY HOME STAY SAFE");
            goto_xy(1, center);
            cout << " CONGRATS YOU ARE ELIGIBLE FOR VACCINATION DRIVE  ";
            goto_xy(1, center);
            cout << "1)  FOR VACCINATION   \t  2) MAIN MENU  ";
            int choice;
            goto_xy(1, center);
            cout << "PLEASE ENTER YOUR CHOICE :- ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                vaccine_management();
                break;
            case 2:
                break;
            default:
                goto_xy(1, center);
                cout << "Please insert valid choice ! ";
                goto_xy(1, center);


            }
        }

        else
        {
            goto_xy(1, center);
            printf("ALERT! YOU ARE IN RED ZONE");
            goto_xy(1, center);
            printf("YOU ARE NOT ELIGIBLE FOR VACCINATION BECAUSE YOU ARE IN RED ZONE");
        }
        printf("\n\n\t\t\t STAY HOME STAY SAFE ........Enter to go main menu\n");
        getch();
        cout<<endl;
        system("clear");

}
