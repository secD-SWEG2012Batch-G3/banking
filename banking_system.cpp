#include <iostream>
#include <cctype>
#include <iomanip>
#include <string.h>
#include <cmath>

using namespace std;

struct client_info
{
    string fname,mname, lname,full_name, account_type,official_id;
    string account_type_country,country_reside;
    int age;
    char sex;
    float balance;
    float acc_interest;
};

//global variable and constatnts for the program
client_info user[100];
int counter=0;

//function that are used in this program
void welcome();
int task_choice();
void create_account();
void deposit();
void withdrawl();
void check_balance();
void customer_list();
void transfer_money();
void close_account();
void account_checker();
void account_type_chocie();
void print_user_info();
void exit();

int main()
{
    int choice;
    welcome();
    
    choice = task_choice();
    switch (choice)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    }
    return 0;
}
void welcome()
{
    cout << "****************************************************************";
    cout << "***************AASTU BANKING SYSTEM*****************************";
    cout << "****************************************************************";
}
int task_choice()
{
    int task;
    cout << "choose the service you would like to perform: ";
    cout << " [1] to create account \n"
         << " [2] To deposit \n"
         << " [3] To withdraw \n"
         << " [4] To check balance \n"
         << " [5] To close account \n"
         << " [6] To Transfer money \n"
         << " [7] To access bank statement \n"
         << " [8] Administrator Access \n"
         << " [9] To exit \n";
    cin >> task;
    return task;
}
void create_account()
{
    cout << "what is your first name: ";cin >> user[counter].fname;
    cout << "what is your middle name: ";cin >> user[counter].mname;
    cout << "what is your last name: ";cin >> user[counter].lname;
    cout << "what is your age: ";cin >> user[counter].age;
    cout << "what is your gender: ";cin >> user[counter].sex;
    cout << "what is your country of residence: ";cin >> user[counter].country_reside;
    cout << "what is your preferred account type: (interset free,with interest) ";cin >> user[counter].account_type;
    cout << "what is your first name: ";cin >> user[counter].fname;
    counter++;
}
