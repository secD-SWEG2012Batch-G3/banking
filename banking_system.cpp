#include <iostream>
#include <cctype>
#include <iomanip>
#include <string.h>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

struct client_name{
    string fname,mname, lname,full_name;
};
struct date{
    int day,month,year;
};
struct address{
    string address_1;
    string address_2;
    int po_box;
};
struct client_info
{
    string account_type,official_id;
    string account_type_country,country_reside;
    string branch_name;
    int age,acc_num;
    char sex;
    float balance;
    float acc_interest;
    client_name user_name;
    date d_bate;
    address location;
};

//global variable and constatnts for the program
client_info user[2];
int counter=0;
int acc_num = 1000;
string account_type_country[2] = {"ETHIOPIAN" , "Foreigner"};

//function that are used in this program
void welcome();
int task_choice();
void create_account();
void deposit();
void withdrawl();
void check_balance();
void customer_list(client_info []);
void transfer_money(client_info []);
void close_account();
bool account_checker(int accno,int &user_check);
void account_type_choice();
void print_user_info(client_info []);
void exit();

int main()
{
    int choice;
    welcome();

    choice = task_choice();
    switch (choice)
    {
    case 1:create_account();break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:break;
    }
    return 0;
}
void welcome()
{
    cout << "****************************************************************"<<endl;
    cout << "****************** AASTU BANKING SYSTEM ************************"<<endl;
    cout << "****************************************************************"<<endl;
}
int task_choice()
{
    int task;
    cout << "choose the service you would like to perform: \n";
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
    cout << "what is your first name: ";cin >> user[counter].user_name.fname;
    cout << "what is your middle name: ";cin >> user[counter].user_name.mname;
    cout << "what is your last name: ";cin >> user[counter].user_name.lname;
    cout << "what is your age: ";cin >> user[counter].age;
    cout << "what is your gender: ";cin >> user[counter].sex;
    cout << "what is your date of birth: [day] ";cin >> user[counter].d_bate.day;
    cout << "what is your date of birth: [month] ";cin >> user[counter].d_bate.month;
    cout << "what is your date of birth: [year] ";cin >> user[counter].d_bate.year;
    cout << "what is your address 1: "; cin >> user[counter].location.address_1;
    cout << "what is your address 2: "; cin >> user[counter].location.address_2;
    cout << "what is your postal code: "; cin >> user[counter].location.po_box;
    cout << "what is your passport number or official id number: "; cin >> user[counter].official_id;
    cout << "what is your country of residence: ";cin >> user[counter].country_reside;
//    user[counter].country_reside = toupper((user[counter].country_reside));

    if(user[counter].country_reside == account_type_country[1]){
        user[counter].account_type_country = account_type_country[1];
    }
    else
        user[counter].account_type_country = account_type_country[2];
    cout << "what is your preferred account type: (interset free,with interest) ";cin>> user[counter].account_type;
    cout << "what is the branch: ";cin >> user[counter].branch_name;
    bal:
    cout << "minimum deposit: ";cin >> user[counter].balance;
    if(user[counter].balance < 100){
        cout << "the minimum allowed initial deposit is 100: ";
        goto bal;
    }
    user[counter].acc_num = 1000 + counter;
    counter++;
}
//a function to check the existence of the account in the database(array)
bool account_checker(int accnumber,int &ran)
{

    for(int i=0;i<counter;i++)
        if(accnumber == user[i].acc_num){
            ran = i;
            return true;
        }
        else
            return false;

}
//a function to deposit an amount to account holder(user)
void deposit()
{
    system("cls");
    int accNo,ran=0;
    float depo;
    bool check;
    no:
    cout << "please enter account number : "; cin >> accNo;
    check = account_checker(accNo,ran);
    if(check == true){
        cout << "please the amount you would like to deposit: ";
        cin >> depo;
        user[ran].balance += depo;
        cout << "operation successful";

    }
    else
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             <<  "please enter the account number correctly!"; goto no;
}
//a function to withdraw an amount from the user account
void withdrawl()
{
    system("cls");
    int accNo,ran=0;
    float wdraw;
    bool check;
    no:
    cout << "please enter account number : "; cin >> accNo;
    check = account_checker(accNo,ran);
    if(check == true){
        cout << "please the amount you would like to withdraw: ";
        cin >> wdraw;
        user[ran].balance -= wdraw;
        cout << "operation successful";
    }
    else
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             <<  "please enter the account number correctly!"; goto no;
}
//a function to check the remaining amount of balance for the user
void check_balance()
{
    int accNo,ran=0;
    bool check;
    no:
    cout << "please enter account number : "; cin >> accNo;
    check = account_checker(accNo,ran);
    if(check == true){
        cout << "your account balance is: "<< user[ran].balance << "birr\n";
        cout << "operation successful";
    }
    else
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             <<  "please enter the account number correctly!"; goto no;
}
