
#include <iostream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "vaccine_dose_registration.h"
using namespace std;

void menu();
void choice();
void vaccination();
void manage_record();
void menu()
{
    system("cls");
    goto_xy(5, center);
    cout<<"***********************************************";
    goto_xy(1, center);
    cout<<"***********************************************";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**          COVID                            **";
    goto_xy(1, center);
    cout<<"**          VACCINE                          **";
    goto_xy(1, center);
    cout<<"**          MANAGEMENT                       **";
    goto_xy(1, center);
    cout<<"**          SYSTEM                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"***********************************************";
    goto_xy(1, center);
    cout<<"***********************************************";
    goto_xy(1, center);
    cout << "1. GET VACCINE" << endl;
    goto_xy(1, center);
    cout << "2. VACCINATION RECORDS " << endl;
    goto_xy(1, center);
    cout << "3. EXIT" << endl;
    choice();
}
void choice()
{

    cout << "ENTER THE OPERATION YOU WANT TO PERFORM : ";
    int n;
    cin >> n;
    system("cls");
    goto_xy(5, center);
    switch (n)
    {
    case 1:
        vaccination();
        break;
    case 2:
        first_menu();
        break;
    case 3:
        goto_xy(36, center - 10);
        cout << "Thank You For Using Vaccine Management System........Press enter to exit";
        getch();
        exit(0);
        break;
    default :
        break;
    }
    menu();
}
int main()
{
    goto_xy(5, center);
    menu();
    return 0;
}
void vaccination()
{
    system("cls");
    goto_xy(5,center-10);
    cout<<"1. GET 1ST DOSE ";
    goto_xy(1,center-10);
    cout<<"2. GET 2ND DOSE ";
    goto_xy(1,center-10);
    cout<<"3. MENU "<<endl<<endl;
    cout << "ENTER THE OPERATION YOU WANT TO PERFORM : ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        rapid_covid_test();
        break;
    case 2:
        get_second_dose();
        break;
    case 3:
        menu();
        break;
    default :
        break;
    }
}
