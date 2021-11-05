#include <iostream>
#include <fstream>
#include <string.h>
#include<conio.h>
#include "vaccine_inventory.h"
using namespace std;

class vaccine_next : public vaccine
{
public:
    void user_input();
    void get_next_date(int);
    void second_dose();
};
int convertToInt(char a[])
{
    int i = 0;
    int num = 0;
    while (a[i] != 0)
    {
        num = (a[i] - '0') + (num * 10);
        i++;
    }
    return num;
}
void vaccine_next::get_next_date(int ne)
{
    int month, year, day;
    int d, m, y;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    y = 1900 + local_time->tm_year;
    m = 1 + local_time->tm_mon;
    d = local_time->tm_mday;
    string strid = to_string(d);
    string strim = to_string(m);
    string strio = to_string(y);
    string symbol("/");
    string currentdate = strid + symbol + strim + symbol + strio;
    char temp_date1[10];
    for (int i = 0; i < currentdate.length(); i++)
    {
        temp_date1[i] = currentdate[i];
    }
    strcpy(first_dose_date, temp_date1);
    int m2[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, k = 0, p, a;
    for (i = 0; i < m; i++)
        k = k + m2[i];
    k = k + d + ne;
    if (k <= 365)
    {
        for (i = 0; i < 13; i++)
        {
            p = k - m2[i];
            if (p <= m2[i + 1])
            {
                a = i + 1;
                break;
            }
            else
                k = p;
        }
        string strip = to_string(p);
        string stria = to_string(a);
        string striy = to_string(y);
        string symbol("/");
        string newdate = strip + symbol + stria + symbol + striy;
        char temp_date2[10];
        for (int i = 0; i < newdate.length(); i++)
        {
            temp_date2[i] = newdate[i];
        }
        strcpy(date_next, temp_date2);
    }
    else
    {
        k = k - 365;
        for (i = 0; i < 13; i++)
        {
            p = k - m2[i];
            if (p <= m2[i + 1])
            {
                a = i + 1;
                break;
            }
            else
                k = p;
        }
        string strip = to_string(p);
        string stria = to_string(a);
        string striy = to_string(y + 1);
        string symbol("/");
        string newdate = strip + symbol + stria + symbol + striy;
        char temp_date2[10];
        for (int i = 0; i < newdate.length(); i++)
        {
            temp_date2[i] = newdate[i];
        }
        strcpy(date_next, temp_date2);
        cout << endl
             << "Enter to continue.....";
        getch();
    }
}
void vaccine_next::user_input()
{
    ofstream fout("vaccinationdata.txt", ios::app);
    fflush(stdin);
    goto_xy(1, center);
    cout << "Vaccine Dose Registration ";
    goto_xy(2, center);
    cout << "Enter your name :-  ";
    gets(name);
    goto_xy(1, center);
    cout << "Enter your aadhar :-  ";
    gets(aadhar);
    fflush(stdin);
    goto_xy(1, center);
    cout << "Enter your gender (M|F) :-  ";
    cin >> gender;
    goto_xy(1, center);
    cout << "Enter your age:- ";
    cin >> age;
    fflush(stdin);
    goto_xy(1, center);
    cout << "Enter your profession :-  ";
    gets(profession);
    fflush(stdin);
    goto_xy(1, center);
    cout << "Enter your B.P. :-  ";
    cin >> blood_pressure;
    goto_xy(1, center);
    cout << "Enter your Body temperature:-  ";
    cin >> temperature;
    fflush(stdin);
    goto_xy(1, center);
    cout << "Enter your permanent address :-  ";
    gets(address);
    goto_xy(1, center);
    cout << "Enter your Mobile number :- ";
    gets(mobile_number);
    ref_id = convertToInt(aadhar) + convertToInt(mobile_number);
    if (ref_id < 0)
        ref_id = 0 - ref_id;
    goto_xy(1, center);
    cout << "Your ref id is : " << ref_id;
    getch();
    goto_xy(1, center);
    show_available_vaccine();
    int v_code, gap, flag = 0;
    goto_xy(1, center);
    cout << "Enter the vaccine code which you want to take : ";
    cin >> v_code;
    FILE *fp;
    fp = fopen("vaccine.txt", "r+");
    record r;
    while (fread(&r, sizeof(r), 1, fp))
    {
        if (v_code == r.vaccine_code)
        {
            if (r.quantity > 0)
            {
                strcpy(vaccine_name,r.name_of_vaccine);
                strcpy(first_dose_status, "DONE");
                strcpy(second_dose_status, "Pending");
                gap = r.gap_bw_dose;
                r.quantity = r.quantity - 1;
                fseek(fp, -(long)sizeof(r), 1);//--------------
                fwrite(&r, sizeof(r), 1, fp);
                get_next_date(gap);
                fout.write((char *)this, sizeof(vaccine_next));
                goto_xy(1, center);
                cout << "You have successfully registered for your first dose of vaccine ";
                flag=1;
                goto_xy(1, center);
                cout << "Name : " << name;
                goto_xy(1, center);
                cout << "Your Reference id : " << ref_id;
                goto_xy(1, center);
                cout << "Aadhar number : " << aadhar;
                goto_xy(1, center);
                cout << "Mobile_number : " << mobile_number;
                goto_xy(1, center);
                cout << "Vaccine Name : " << vaccine_name;
                goto_xy(1, center);
                cout << "2nd Dose Date : " << date_next;
                goto_xy(1, center);
                cout << "Please Remember this reference id for 2nd dose registration";
                goto_xy(1, center);
                cout << endl
                     << "Enter to continue...";
                getch();
                break;
            }
            else
            {
                goto_xy(1, center);
                cout << "You don't have sufficient quantity of " << r.name_of_vaccine;
                fflush(stdin);
                cout << endl
                     << "Enter to continue...";
                getch();
            }
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        goto_xy(1, center);
        cout << "wrong vaccine code";
        cout << endl
             << "Enter to continue.......";
        getch();
    }
    fclose(fp);
    fout.close();
}
void vaccine_management()
{
    system("cls");
    vaccine_next v;
    v.user_input();
}

void showdata()
{
    vaccine_next v1;
    ifstream fin("vaccinationdata.txt");
    while (fin.read((char *)&v1, sizeof((v1))))
    {
        cout << "Reference id : " << v1.ref_id << endl;
        cout << "name: " << v1.name << endl;
        cout << "Aadhar number " << v1.aadhar << endl;
        cout << "Gender : " << v1.gender << endl;
        cout << "Age: " << v1.age << endl;
        cout << "Profession : " << v1.profession << endl;
        cout << "Blood Pressure : " << v1.blood_pressure << endl;
        cout << "Temperature : " << v1.temperature << endl;
        cout << "Address : " << v1.address << endl;
        cout << "Mobile number : " << v1.mobile_number << endl;
        cout << "Vaccine name : " << v1.vaccine_name << endl;
        cout << "first dose status " << v1.first_dose_status << endl;
        cout << "second dose status : " << v1.second_dose_status << endl;
        cout << "first dose date : " << v1.first_dose_date << endl;
        cout << "second dose date : " << v1.date_next << endl;
    }
    fin.close();
}
void vaccine_next::second_dose()
{
    system("cls");
    goto_xy(1, center);
    cout << "SECOND DOSE STATUS";
    long long int ref_num;
    int flag = 0;
    goto_xy(5, center);
    cout << "Enter reference number: ";
    cin >> ref_num;
    fstream fin("vaccinationdata.txt", ios::in | ios::ate | ios::out);
    fin.seekg(0);
    fin.read((char *)this, sizeof(vaccine_next));
    while (!fin.eof())
    {
        if (ref_id == ref_num)
        {
            strcpy(second_dose_status, " DONE ");
            flag = 1;
            long long position = fin.tellp();
            fin.seekp(position - sizeof(vaccine_next));
            fin.write((char *)this, sizeof(vaccine_next));
            goto_xy(1, center);
            cout << "Congratulations ! You have successfully done your second dose of vaccination";
            goto_xy(1, center);
            cout << "But still you have to follow these rules and regulations : ";
            goto_xy(1, center);
            cout << "1. Wear mask properly ";
            goto_xy(1, center);
            cout << "2. Maintain social distancing of at least 1 meter";
            goto_xy(1, center);
            cout << "3.  Stay away from crowded areas ";
            cout << endl
                 << "Enter to continue.......";
            getch();
            break;
        }
        fin.read((char *)this, sizeof(vaccine_next));
    }
    if (flag == 0)
    {
        goto_xy(1, center);
        cout << "Incorrect reference id";
        goto_xy(1, center);
        cout << "Please enter again ";
        getch();
    }
    fin.close();
    system("cls");
}
int get_second_dose()
{

    vaccine_next v;
    v.second_dose();
    return 0;
}
