//banking management system
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string.h>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

struct client_name
{
    string fname, mname, lname, full_name;
};
struct date
{
    int day, month, year;
};
struct address
{
    string address_1;
    string address_2;
    int po_box;
};
struct transaction{
    int id;
};
struct client_info
{
    string account_type, official_id;
    string account_type_country, country_reside;
    string branch_name;
    int age, acc_num;
    char sex;
    float balance;
    float acc_interest;
    client_name user_name;
    date d_bate;
    address location;
    //transaction *client_user[10];
};

//global variable and constatnts for the program
client_info *user[10];
int counter = 0;    // number of user counter as a whole
int tran_counter = 0;  //transaction counter
int acc_num = 1000;  // inital account number for users
string account_type_country[2] = {"ETHIOPIAN", "Foreigner"};
string acctype[2] = {"with interest", "without interest"};
float int_rate[2] = {0.25,0.15}; //interest rate for saving account and checking account respectively
int admin_id[10] = {1120,1121,1122,1123};
int admin_pass[10] = {1000,1010,1122,1123};

//function that are used in this program
void welcome();
int task_choice();
void create_account();
void deposit();
void withdrawl();
void check_balance();

void transfer_money(client_info *[]);
void print_user_info(client_info *[]);
void close_account(client_info *[]);
bool account_checker(int accno, int *user_check);
void account_type_choice();
void exit();

//functions used for adminstrators access
void admin();
void total_transaction();
void customer_list(client_info []);
void multi_stat(client_info *[]);


int main()
{
    int choice;
    bool isDone = true;
    while (isDone)
    {
        welcome();
        choice = task_choice();
        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdrawl();
            break;
        case 4:
            check_balance();
            break;
        case 5:
            close_account(user);
            break;
        case 6:
            transfer_money(user);
            break;
        case 7:
            //print_user_info(user);
            break;
        case 8:
            admin();
            break;
        case 9:
            isDone = false;
            break;
        }
    }
    return 0;
}
void welcome()
{
    cout << "****************************************************************" << endl;
    cout << "****************** AASTU BANKING SYSTEM ************************" << endl;
    cout << "****************************************************************" << endl;
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
    user[counter] = new client_info;
    cout << "what is your first name: ";
    cin >> user[counter]->user_name.fname;
    cout << "what is your middle name: ";
    cin >> user[counter]->user_name.mname;
    cout << "what is your last name: ";
    cin >> user[counter]->user_name.lname;
    user[counter]->user_name.full_name = user[counter]->user_name.fname + " " + user[counter]->user_name.mname +
                                         " "+user[counter]->user_name.lname;
    /*cout << "what is your age: ";cin >> user[counter].age;
    cout << "what is your gender: ";cin >> user[counter].sex;
    cout << "what is your date of birth: [day] ";cin >> user[counter].d_bate.day;
    cout << "what is your date of birth: [month] ";cin >> user[counter].d_bate.month;
    cout << "what is your date of birth: [year] ";cin >> user[counter].d_bate.year;
    cout << "what is your address 1: "; cin >> user[counter].location.address_1;
    cout << "what is your address 2: "; cin >> user[counter].location.address_2;
    cout << "what is your postal code: "; cin >> user[counter].location.po_box;
    cout << "what is your passport number or official id number: "; cin >> user[counter].official_id;
    cout << "what is your country of residence: ";cin >> user[counter].country_reside;
    user[counter].country_reside = toupper((user[counter].country_reside));

    if(user[counter].country_reside == account_type_country[1]){
        user[counter].account_type_country = account_type_country[1];
    }
    else
        user[counter].account_type_country = account_type_country[2];*/
    cout << "what is your preferred account type based on interest: ([y]with interest,[n]interest free) ";
    char answer;cin>>answer;
    if(answer == 'y' || answer == 'Y'){
        user[counter]->account_type = acctype[0];
    }
    else {
       user[counter]->account_type = acctype[1];
    }
    cout << "what is your preferred account type based on type: ([C]checking,[S]saving) ";
    char ans;cin>>ans;
    if(ans == 'C' || ans == 'c'){
        user[counter]->acc_interest = int_rate[1];
    }
    else {
       user[counter]->acc_interest = int_rate[0];
    }
//cout << "what is the branch: ";cin >> user[counter].branch_name;
    cout << "minimum deposit: ";
    cin >> user[counter]->balance;
    while (user[counter]->balance < 100) {
        cout << "the minimum allowed initial deposit is 100: ";cin >> user[counter]->balance;
    }
    user[counter]->acc_num = 1000 + counter;
    counter++;
}
//a function to check the existence of the account in the database(array)
//recives aaccount number and returns a bool value and returns the user index by reference value
bool account_checker(int accnumber, int *ran)
{
    bool does_exist;
    for (int i = 0; i < counter; i++)
    {
        if (accnumber == user[i]->acc_num)
        {
            *ran = i;
            does_exist = true;
        }
        else
            does_exist =  false;
    }

    return does_exist;
}
//a function to deposit an amount to account holder(user)
void deposit()
{
    system("cls");
    int accNo, account_user_index = 0;
    float depo;
    bool check;
no:
    cout << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    if (check == true)
    {
        cout << "please the amount you would like to deposit: ";
        cin >> depo;
        user[account_user_index]->balance += depo;

        cout << "operation successful\n";
    }
    else
    {
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             << "please enter the account number correctly!\n";
        goto no;
    }
}
//a function to withdraw an amount from the user account
void withdrawl()
{
    system("cls");
    int accNo, account_user_index = 0;
    float wdraw;
    bool check;
no:
    cout << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    if (check == true)
    {
        cout << "please the amount you would like to withdraw: ";
        cin >> wdraw;
        while(wdraw > 100000){
            cout << "you cannot withdraw money above 100,000 birr";cin>>wdraw;
        }
        user[account_user_index]->balance -= wdraw;
        cout << "operation successful"<<endl;
    }
    else
    {
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             << "please enter the account number correctly!";
        goto no;
    }
}
//a function to check the remaining amount of balance for the user
void check_balance()
{
    int accNo, account_user_index = 0;
    bool check;
no:
    cout << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    if (check)
    {
        cout << "your account balance is: " << user[account_user_index]->balance << "birr\n";
        cout << "operation successful"<<endl;
    }
    else
    {
        cout << "the account number you entered doesn't match any account holder in the database:"
             << "please enter the account number correctly!\n";
        goto no;
    }
}
void customer_list(client_info *user[])
{
    cout << "account holder name\taccount number\tbalance" << endl;
    for(int i=0;i<counter;i++)
    {
        cout << user[i]->user_name.fname << setw(25)
            << user[i]->acc_num << setw(13)
            << user[i]->balance << endl;
    }
}
void transfer_money(client_info *user[])
{
    system("cls");
    int accountFrom, accountTo;
    int account_sender_index=0, account_receiver_index=0;
    float amount;
    bool from_checker,to_checker;

    cout << "account number of the receiver: "; cin >> accountTo;
    to_checker = account_checker(accountTo,&account_receiver_index);
    cout << to_checker;
    cout << account_receiver_index;
    cin.ignore();
    cout << "account number of the sender: "; cin >> accountFrom;
    from_checker = account_checker(accountFrom,&account_sender_index);
    cout << from_checker;
    cout << account_sender_index;
    trans:
    cout << "please enter the amount you would like to transfer: ";cin>>amount;
    if(from_checker == true && to_checker == true )
    {
        user[account_sender_index]->balance -= amount;
        user[account_receiver_index]->balance += amount;
        cout << "operation successful"<<endl;
    }
    else
    {
        cout << " you have insufficient balalance!\n" << "please try again!";goto trans;
    }
}
void close_account(client_info *user[])
{
    system("cls");
    int accNo, account_user_index = 0;
    bool check;
no:
    cout << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    if (check == true)
    {
        cout << "total balance of your account: "<<user[account_user_index]->balance<<endl;
        user[account_user_index]->balance = 0;
        for (int i=account_user_index;i<counter;++i)
        {
            user[i] = user[i+1];
        }
        counter--;
        cout << "operation successful\n";
    }
    else
    {
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             << "please enter the account number correctly!\n";
        goto no;
    }
}
void admin()
{
    int id,pass;
    bool check_id,check_pass;
    cout << setw(10) << "**************************************************\n";
    cout << setw(25) << "enter your admin id ";
    //idnum:
    cin>>id;
    for(int i=0;i<10;i++){
        if(id == admin_id[i]){
            check_id=true;
        }
        //lse {"wrong if! please enter your id again:";goto idnum;}
    }
    cout << setw(25) << "enter your password ";
    //passnum:
        cin>>pass;
    for(int i=0;i<10;i++){
        if(pass == admin_pass[i]){
            check_pass = true;
        }
        //else {"wrong if! please enter your id again:";goto passnum;}
    }

    if(check_id == true && check_pass == true){
        int choose;
        cout << "[1] for total customer list information\n"
             << "[2] for total capital of the bank\n"
             << "[3] for total capital of the bank\n"
             << "[4] for total capital of the bank\n";cin>>choose;
        switch(choose){
            case 1:customer_list(user);break;
            case 2:break;
            case 3:break;
            case 4:break;
        }
    }
}
void multi_stat(client_info *[])
{
    int sum,below_checker = 0,above_checker = 0;
    int ch_checker =0,sav_checker= 0,int_checker=0,wout_checker=0,comp_checker=0,comp2_checker=0;
    cout << "==========================================================================================\n";
    cout << setw(25) << "number of clients: "<< counter;
    cout << setw(25) << "total capital: ";
    for(int i=0;i<counter;++i){
        sum += user[i].balance; 
    }
    cout <<sum;
    cout << setw(25) << "number of clients below 100,000 balance: ";
    for(int i=0;i<counter;++i){
        if(user[i].balacne < 100000){
            below_checker++;
        } 
    }
    cout << below_checker;
    cout << setw(25) << "number of clients above 100,000 balance: ";
    for(int i=0;i<counter;++i){
        if(user[i].balacne < 100000){
            above_checker++;
        } 
    }
    cout << above_checker;
    cout << setw(25) << "number of clients with checking account: ";
    for(int i=0;i<counter;++i){
        if(user[i]->acc_interest == int_rate[1]){
            ch_checker;
        } 
    }
    cout << ch_checker;
    cout << setw(25) << "number of clients with saving account: ";
    for(int i=0;i<counter;++i){
        if(user[i]->acc_interest == int_rate[0]){
            sav_checker++;
        } 
    }
    cout << sav_checker;

    //not done
    cout << setw(25) << "number of clients with interest account: ";
    for(int i=0;i<counter;++i){
        if(user[i].balacne < 100000){
            above_checker++;
        } 
    }
    cout << setw(25) << "number of clients with out interest account: ";
    for(int i=0;i<counter;++i){
        if(user[i].balacne < 100000){
            above_checker++;
        } 
    }
    cout << setw(25) << "number of clients with out interest account and with checking account: ";
    cout << "==========================================================================================\n";
}
void total_transaction();
