#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\n\n\t\t\t_______________________________________________________________\n\n\n";
    cout << "\t\t\t                    Welcome to the Login Page                   \n\n\n";
    cout << "\t\t\t____________________          MENU           ____________________\n\n";
    cout << "                                                                        \n\n";
    cout << "\t| Press 1 to LOGIN                       |" << endl;
    cout << "\t| Press 2 to REGISTER                    |" << endl;
    cout << "\t| Press 3 if you forgot your Password    |" << endl;
    cout << "\t| Press 4 to Exit                        |" << endl;

    cout << "\n\t\t\t Please Enter Your Choice :  ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\t\t\t Thank You!!!\n\n";
        exit(1);
        break;

    default:
        system("cls");
        cout << "\t\t\t Please Select from the options given below \n"
             << endl;
        main();
        break;
    }
    return 0;
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please Enter Username and Password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << " " << userId << "\n Your LOGIN is Successfull \n Thanks for logging in! \n";
        main();
    }

    else
    {
        cout << "\n LOGIN ERROR!! \n Please Check Credentials";
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter The Username: ";
    cin >> ruserId;
    cout << "\t\t\t Enter The Password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;

    system("cls");
    cout << "\n\t\t\t Registration is Successfull \n";

    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password?  No Worries \n";
    cout << "Press 1 To Search your Id by Username " << endl;
    cout << "Press 2 To Go Back to the Main Menu " << endl;
    cout << "\t\t\t Enter Your Choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "Enter the Username: ";
        cin >> suserId;

        ifstream f2("records.txt");

        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is found \n";
            cout << "\n\n Your Password is: " << spass << endl;
            main();
        }
        else
        {
            cout << "\n\t Sorry! Your account is not found!! \n";
            main();
        }
        break;
    }

    case 2:
        main();

    default:
        cout << "\t\t\t Wrong hoice!! Please Try Again!! " << endl;
        forgot();
    }
}
