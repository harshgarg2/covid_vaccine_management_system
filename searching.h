#include <iostream>
#include <fstream>
#include "rapid_covid_test.h"
#define center 50
using namespace std;

int search_menu();
class vaccine
{
public:
    char name[30];
    char aadhar[12];
    int age;
    char gender;
    char profession[20];
    char address[60];
    char mobile_number[10];
    long long int ref_id;
    char vaccine_name[15];
    char first_dose_status[5];
    int blood_pressure;
    char second_dose_status[8];
    float temperature;
    char first_dose_date[10];
    char date_next[10];

    void user_input();
    void get_next_date(int);
    void showdata(int);
    void search_by_aadhar();
    void search_by_age();
    void search_by_profession();
    void search_by_gender();
    void show_list();
};
void vaccine::showdata(int i)
{
    goto_xy(1, center);
    cout << "Reference Id : " << ref_id;
    goto_xy(1, center);
    cout << "Name is: " << name;
    goto_xy(1, center);
    cout << "Aadhar number is: " << aadhar;
    goto_xy(1, center);
    cout << "Your age is " << age;
    goto_xy(1, center);
    cout << "Profession is : " << profession;
    goto_xy(1, center);
    cout << "Gender is : " << gender;
    goto_xy(1, center);
    cout << "Address is: " << address;
    goto_xy(1, center);
    cout << "Mobile number is: " << mobile_number;
    goto_xy(1, center);
    cout << "Vaccine Name : " << vaccine_name;
    goto_xy(1, center);
    cout << "First dose status: " << first_dose_status;
    goto_xy(1, center);
    char arr[11];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = first_dose_date[i];
    }
    arr[10] = '\0';
    cout << "First dose date: " << arr;
    goto_xy(1, center);
    cout << "Second dose status: " << second_dose_status;
    goto_xy(1, center);
    cout << "Second dose date: " << date_next;
    cout << endl
         << "Enter to continue.....";
    getch();
}
void vaccine::search_by_aadhar()
{
    system("cls");
    ifstream in("vaccinationdata.txt");
    int flag = 0;
    long long int ref_num;
    goto_xy(1, center);
    cout << "REFFERENCE NUMBER SEARCHING ";
    goto_xy(3, center);
    cout << "Enter your Reference Id :  ";
    fflush(stdin);
    cin >> ref_num;
    in.seekg(0);
    in.read((char *)this, sizeof(vaccine));
    int i = 9;
    while (!in.eof())
    {
        if (ref_num == ref_id)
        {
            showdata(i);
            flag = 1;
            break;
        }
        in.read((char *)this, sizeof(vaccine));
    }
    if (flag == 0)
    {
        goto_xy(1, center);
        cout << "REFERENCE ID not found......enter to continue ";
        getch();
    }
    in.close();
    system("cls");
}
void vaccine::search_by_gender()
{
    system("cls");
    fstream in("vaccinationdata.txt");
    int flag = 0;
    char g;
    int p = 0;
    goto_xy(5, center);
    cout << "SEARCH BY GENDER";
    goto_xy(5, center);
    cout << "Enter gender by which you want to search : ";
    cin >> g;
    in.read((char *)this, sizeof(vaccine));
    in.seekg(0);
    int i = 10;
    while (!in.eof())
    {
        if (toupper(g) == toupper(gender))
        {
            showdata(i);
            flag = 1;
            p++;
            i = i + 27;
        }
        in.read((char *)this, sizeof(vaccine));
    }
    goto_xy(5, center);
    if (flag == 0)
    {
        cout << "THERE IS NO PERSON VACCINATED FROM THIS GENDER....";
    }
    else
        cout << "NUMBER OF PEOPLE VACCINATED BY THIS GENDER: " << p;
    cout << endl
         << "Enter to continue....";
    getch();
    in.close();
}
void vaccine::search_by_age()
{
    system("cls");
    ifstream in("vaccinationdata.txt");
    int flag = 0;
    int a, p = 0;
    goto_xy(1, center);
    cout << "AGE SEARCHING ";
    goto_xy(1, center);
    goto_xy(1, center);
    cout << "enter Age by which you want to search : ";
    cin >> a;
    in.seekg(0);
    in.read((char *)this, sizeof(vaccine));
    int i = 10;
    while (!in.eof())
    {
        if (a == age)
        {
            showdata(i);
            flag = 1;
            p++;
            i = i + 27;
        }
        in.read((char *)this, sizeof(vaccine));
    }
    if (flag == 0)
    {
        goto_xy(1, center);
        cout << "Age you entered is not found";
    }
    goto_xy(1, center);
    cout << "No of people vaccinated  by this age " << p;
    cout << endl
         << "Enter to continue........";
    getch();
    in.close();
}
void vaccine::search_by_profession()
{
    system("cls");
    ifstream in("vaccinationdata.txt");
    int flag = 0;
    int p = 0;
    char prof[20];
    goto_xy(1, center);
    cout << "SEARCH BY PROFESSSION";
    goto_xy(1, center);
    goto_xy(1, center);
    cout << "Enter Profession by which you want to search : ";
    fflush(stdin);
    gets(prof);
    in.seekg(0);
    in.read((char *)this, sizeof(vaccine));
    int i = 10;
    while (!in.eof())
    {
        if (strcmp(prof, profession) == 0)
        {
            showdata(i);
            flag = 1;
            p++;
            i = i + 27;
        }
        in.read((char *)this, sizeof(vaccine));
    }
    if (flag == 0)
    {
        goto_xy(1, center);
        cout << "The profession you have Enter does not exist";
    }
    goto_xy(1, center);
    cout << "NO of people vaccinated by this profession " << p;
    cout << endl
         << "Enter to continue.......";
    getch();
    in.close();
}

void search_data()
{
    int n;
    cin >> n;
    vaccine i;
    {
        switch (n)
        {
        case 1:
            i.search_by_aadhar();
            break;
        case 2:
            i.search_by_age();
            break;
        case 3:
            i.search_by_profession();
            break;
        case 4:
            i.search_by_gender();
            break;
        case 5:
            break;
        }
    }
    goto_xy(5, center);
    fflush(stdin);
    cout << endl
         << "Wants to Search again (Y/N): ";

    char ch;
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
        { search_menu();}
}
int search_menu()
{
    system("cls");
    goto_xy(5, center);
    printf("1. Search by Reference Id");
    goto_xy(1, center);
    printf("2. Search by Age");
    goto_xy(1, center);
    printf("3. Search by Profession");
    goto_xy(1, center);
    printf("4. Search by Gender");
    goto_xy(1, center);
    printf("5. Main Menu");
    goto_xy(5, center);
    cout << "ENTER THE TYPE OF SEARCH YOU WANT TO PERFORM : ";
    search_data();
    getch();
    return 0;
}
