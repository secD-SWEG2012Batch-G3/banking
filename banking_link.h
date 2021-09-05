#include <iostream>
#include <cctype>
#include  <ctime>
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
struct tracker
{
    int counter = 0;
};
struct transaction
{
    string operation;
    float value;
    char *time;
    int id;
};
struct address
{
    string address_1;
    string address_2;
    int po_box;
};
struct client_info
{
    string account_type, official_id, account_choice;
    string account_type_country, country_reside;
    string branch_name;
    int age, acc_num;
    char sex;
    float balance, debt;
    bool loan;
    float acc_interest;
    client_name user_name;
    date d_bate;
    address location;
    transaction client_user[10];
    tracker check;
};
struct bank
{
    float capital;
};

//global variable and constatnts for the program
client_info *user[10];
int total_user = 0;       // counter total user both who an account and who close an account
int counter = 0;          // number of user counter as a for who have an active account
int tran_counter = 0;     //transaction counter
int interest_counter = 0; //a counter for the transaction of interest type account holders
int with_out_counter = 0; //a counter for thentransaction of without interest account holders
int acc_num = 1000;       // inital account number for users
string account_type_country[2] = {"ETHIOPIAN", "Foreigner"};
string acctype[2] = {"with interest", "without interest"};
string acc_choice[2] = {"checking", "saving"};
string process[4] = {"Deposited", "Withdrawl", "Received", "Transferred"};
float int_rate[2] = {0.25, 0.15}; //interest rate for saving account and checking account respectively
/*
    admin id        admin passsword
    1120            1000
    1121            1010
    1122            1122
    1123            1123

*/
int admin_id[10] = {1120, 1121, 1122, 1123};
int admin_pass[10] = {1000, 1010, 1122, 1123};

//===============================================================================================================&
void welcome()
{
    cout << setw(100) << "****************************************************************************************************" << endl;
    cout << setw(100) << "********************************* AASTU BANKING SYSTEM *********************************************" << endl;
    cout << setw(100) << "****************************************************************************************************" << endl;
}
// a function to give the user a display for the different operation done by the bank
int task_choice()
{
    int task;
    cout << setw(60) << "choose the service you would like to perform: \n";
    cout << "\t\t\t"
         << " [1] to create account \n"
         << "\t\t\t"
         << " [2] To deposit \n"
         << "\t\t\t"
         << " [3] To withdraw \n"
         << "\t\t\t"
         << " [4] To check balance \n"
         << "\t\t\t"
         << " [5] To close account \n"
         << "\t\t\t"
         << " [6] To Transfer money \n"
         << "\t\t\t"
         << " [7] To access bank statement \n"
         << "\t\t\t"
         << " [8] To modify user account \n"
         << "\t\t\t"
         << " [9] To borrow money from bank \n"
         << "\t\t\t"
         << " [10] Administrator Access \n"
         << "\t\t\t"
         << " [11] To exit \n";
    cin >> task;
    return task;
}
//a function to create a new user account information
void create_account()
{
    user[counter] = new client_info;
    cout << "what is your first name: ";
    cin >> user[counter]->user_name.fname;
    cout << "what is your middle name: ";
    cin >> user[counter]->user_name.mname;
    cout << "what is your last name: ";
    cin >> user[counter]->user_name.lname;
    user[counter]->user_name.full_name = user[counter]->user_name.fname + " " +
                                         user[counter]->user_name.mname + " " +
                                         user[counter]->user_name.lname;
    /*
    cout << "what is your age: ";cin >> user[account_user_index]->age;
    cout << "what is your gender: ";cin >> user[account_user_index]->sex;
    cout << "what is your date of birth: [day] ";cin >> user[account_user_index]->d_bate.day;
    cout << "what is your date of birth: [month] ";cin >> user[account_user_index]->d_bate.month;
    cout << "what is your date of birth: [year] ";cin >> user[account_user_index]->d_bate.year;
    cout << "what is your address 1: "; cin >> user[account_user_index]->location.address_1;
    cout << "what is your address 2: "; cin >> user[account_user_index]->location.address_2;
    cout << "what is your postal code: "; cin >> user[account_user_index]->location.po_box;
    cout << "what is your passport number or official id number: "; cin >> user[counter].official_id;*/
    cout << "what is your country of residence: ";cin >> user[counter]->country_reside;
    //user[counter]->country_reside = toupper((user[counter]->country_reside));

    if(user[counter]->country_reside == account_type_country[1]){
        user[counter]->account_type_country = account_type_country[1];
    }
    else
        {user[counter]->account_type_country = account_type_country[2];}
    cout << "what is your preferred account type based on interest: ([y]with interest,[n]interest free) ";
    char answer;
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        user[counter]->account_type = acctype[0];
    }
    else
    {
        user[counter]->account_type = acctype[1];
    }
    cout << "what is your preferred account type based on type: ([C]checking,[S]saving) ";
    char ans;
    cin >> ans;
    if (ans == 'C' || ans == 'c')
    {
        user[counter]->acc_interest = int_rate[1];
        user[counter]->account_choice = acc_choice[0];
    }
    else
    {
        user[counter]->acc_interest = int_rate[0];
        user[counter]->account_choice = acc_choice[1];
    }
    //cout << "what is the branch: ";cin >> user[counter].branch_name;
    cout << "minimum deposit: ";
    cin >> user[counter]->balance;
    while (user[counter]->balance < 100)
    {
        cout << "the minimum allowed initial deposit is 100: ";
        cin >> user[counter]->balance;
    }
    user[counter]->debt = 0;
    user[counter]->acc_num = 1000 + counter;
    cout << "\n########################################################################\n";
    cout << "\t\t"
         << "your account number is:   " << user[counter]->acc_num << endl;
    cout << "#########################################################################\n";
    counter++;
    total_user++;

    system("pause");
}
//a function to check the existence of the account in the database(array)
//recives aaccount number and returns a bool value and returns the user index by reference value
bool account_checker(int accnumber, int *ran)
{
    bool does_exist = false;
    for (int i = 0; i < counter; i++)
    {
        if (accnumber == user[i]->acc_num)
        {
            *ran = i;
            does_exist = true;
        }
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
    cout << "######################################################################################\n";
    cout << "\t\t"
         << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    if (check == true)
    {
        cout << "\t\t"
             << "please the amount you would like to deposit: ";
        cin >> depo;
        user[account_user_index]->balance += depo;
        time_t curr_time = time(NULL;
        if (user[account_user_index]->account_type == acctype[0])
        {
            interest_counter++;
        }
        else
        {
            with_out_counter++;
        }
        user[account_user_index]->client_user[user[account_user_index]->check.counter].id = 8000 + tran_counter;
        user[account_user_index]->client_user[user[account_user_index]->check.counter].operation = process[0];
        user[account_user_index]->client_user[user[account_user_index]->check.counter].value = depo;
        user[account_user_index]->client_user[user[account_user_index]->check.counter].time = ctime(&curr_time);
        user[account_user_index]->check.counter++;
        tran_counter++;

        cout << "\t\t\t"
             << "operation successful\n";
        cout << "############################################################################################\n";
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
    cout << "######################################################################################\n";
    cout << "\t\t"
         << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    if (check == true)
    {
        cout << "\t\t"
             << "please the amount you would like to withdraw: ";
        cin >> wdraw;
        while (wdraw > 100000)
        {
            cout << "you cannot withdraw money above 100,000 birr";
            cin >> wdraw;
        }
        user[account_user_index]->balance -= wdraw;
        time_t curr_time;
	    curr_time = time(NULL);
        if (user[account_user_index]->account_type == acctype[0])
        {
            interest_counter++;
        }
        else
        {
            with_out_counter++;
        }
        user[account_user_index]->client_user[user[account_user_index]->check.counter].id = 8000 + tran_counter;
        user[account_user_index]->client_user[user[account_user_index]->check.counter].operation = process[1];
        user[account_user_index]->client_user[user[account_user_index]->check.counter].value = wdraw;
        user[account_user_index]->client_user[user[account_user_index]->check.counter].time = ctime(&curr_time);
        user[account_user_index]->check.counter++;
        tran_counter++;
        cout << "\t\t\t"
             << "operation successful\n";
        cout << "############################################################################################\n";
        system("pause");
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
    system("cls");
    int accNo, account_user_index = 0;
    bool check;
no:
    cout << "*****************************************************************************************\n";
    cout << "\t\t"
         << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    if (check)
    {
        cout << "************************************************************************************\n";
        cout << "\t\t\t"
             << "your account balance is: " << user[account_user_index]->balance << " birr\n";
        cout << "\t\t\t"
             << "your debt is: " << user[account_user_index]->debt << " birr\n";
        cout << "\t\t\t"
             << "operation successful" << endl;
        cout << "************************************************************************************\n";
        system("pause");
    }
    else
    {
        cout << "the account number you entered doesn't match any account holder in the database:"
             << "please enter the account number correctly!\n";
        goto no;
    }
}
//a function to list out every customers list with their balance
void customer_list(client_info *user[])
{
    cout << "*************************************************************************\n";
    cout << "\t\taccount holder name\taccount number\tbalance" << endl;
    for (int i = 0; i < counter; i++)
    {
        cout << setw(25) << user[i]->user_name.full_name << setw(25)
             << user[i]->acc_num << setw(13)
             << user[i]->balance << endl;
    }
    cout << "*************************************************************************\n";
    system("pause");
}
//a function to transfer money from one user to another
void transfer_money(client_info *user[])
{
    system("cls");
    int accountFrom, accountTo;
    int account_sender_index = 0, account_receiver_index = 0;
    float amount;
    bool from_checker, to_checker;
    cout << "######################################################################################\n";

    cout << "\t\t" << "account number of the receiver: ";
to:
    cin >> accountTo;
    to_checker = account_checker(accountTo, &account_receiver_index);
    if (to_checker == false)
    {
        cout << "\twrong account number!!please try again!\t";
        goto to;
    }
    cout << "\t\t" << "account number of the sender: ";
from:
    cin >> accountFrom;
    from_checker = account_checker(accountFrom, &account_sender_index);
    if (from_checker == false)
    {
        cout << "\twrong account number!!please try again!\t";
        goto from;
    }
trans:
    cout << "\t\t"
         << "please enter the amount you would like to transfer: ";
    cin >> amount;
    if (from_checker == true && to_checker == true && user[account_sender_index]->balance > amount)
    {
        user[account_sender_index]->balance -= amount;
        user[account_receiver_index]->balance += amount;
        time_t curr_time;
	    curr_time = time(NULL);
        if (user[account_sender_index]->account_type == acctype[0])
        {
            interest_counter++;
        }
        else
        {
            with_out_counter++;
        }
        //transaction id assignment for both sender and receiver
        user[account_sender_index]->client_user[user[account_sender_index]->check.counter].id = 8000 + tran_counter;
        user[account_receiver_index]->client_user[user[account_receiver_index]->check.counter].id = 8000 + tran_counter;
        //transaction history elements for both users like the operation and the value of transferred money
        user[account_receiver_index]->client_user[user[account_receiver_index]->check.counter].operation = process[2];
        user[account_receiver_index]->client_user[user[account_receiver_index]->check.counter].value = amount;
        user[account_receiver_index]->client_user[user[account_receiver_index]->check.counter].time = ctime(&curr_time);
        user[account_sender_index]->client_user[user[account_sender_index]->check.counter].operation = process[3];
        user[account_sender_index]->client_user[user[account_sender_index]->check.counter].value = amount;
        user[account_sender_index]->client_user[user[account_sender_index]->check.counter].time = ctime(&curr_time);
        user[account_sender_index]->check.counter++;
        user[account_receiver_index]->check.counter++;
        tran_counter++; // tranaction counter for all users
        cout << "\t\t\t"
             << "operation successful\n";
        cout << "############################################################################################\n";
        system("pause");
    }
    else
    {
        cout << " you have insufficient balalance!\n"
             << "please try again!";
        goto trans;
    }
}
// a function to deactivate user account information
void close_account(client_info *user[])
{
    system("cls");
    int accNo, account_user_index = 0;
    bool check;
no:
    cout << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    if (check)
    {
        cout << "total balance of your account: " << user[account_user_index]->balance << endl;
        //user[account_user_index]->balance = 0;
        for (int i = account_user_index; i < total_user; ++i)
        {
            user[i] = user[i + 1];
        }
        //delete user[total_user];
        total_user--;
        cout << "operation successful\n";
        system("pause");
    }
    else
    {
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             << "please enter the account number correctly!\n";
        goto no;
    }
}
// a function to modify a user information when the user want to change their account informaiton
void modify(client_info *user[])
{
    int accNo, account_user_index = 0;
    bool check;
no:
    cout << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    if (check == true)
    {
        cout << "what is your first name: ";
        cin >> user[account_user_index]->user_name.fname;
        cout << "what is your middle name: ";
        cin >> user[account_user_index]->user_name.mname;
        cout << "what is your last name: ";
        cin >> user[account_user_index]->user_name.lname;
        user[account_user_index]->user_name.full_name = user[account_user_index]->user_name.fname + " " +
                                                        user[account_user_index]->user_name.mname + " " +
                                                        user[account_user_index]->user_name.lname;
        cout << "what is your age: ";
        cin >> user[account_user_index]->age;
        cout << "what is your gender: ";
        cin >> user[account_user_index]->sex;
        cout << "what is your date of birth: [day] ";
        cin >> user[account_user_index]->d_bate.day;
        cout << "what is your date of birth: [month] ";
        cin >> user[account_user_index]->d_bate.month;
        cout << "what is your date of birth: [year] ";
        cin >> user[account_user_index]->d_bate.year;
        cout << "what is your address 1: ";
        cin >> user[account_user_index]->location.address_1;
        cout << "what is your address 2: ";
        cin >> user[account_user_index]->location.address_2;
        cout << "what is your postal code: ";
        cin >> user[account_user_index]->location.po_box;
    }
    else
    {
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             << "please enter the account number correctly!\n";
        goto no;
    }
}
//a function to out put bank statement for the user
void print_user_info(client_info *user[])
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
        cout << "************************************************************************************************\n";
        cout << "\t\t"
             << "\nName of the account holder: " << user[account_user_index]->user_name.full_name;
        cout << "\t\t"
             << "\nAccount number of the holder: " << user[account_user_index]->acc_num;
        cout << "\t\t"
             << "\nbalance of the account holder: " << user[account_user_index]->balance << endl;
        cout << "*************************************************************************************************\n";
        cout << "************************************BANK RECORD**************************************************\n";
        cout << "*************************************************************************************************\n";
        cout << "\t Transaction ID \t Amount \t operation \t time\n";
        for (int i = 0; i < user[account_user_index]->check.counter; ++i)
        {
            cout << "\t " << user[account_user_index]->client_user[i].id
                 << " \t\t\t" << user[account_user_index]->client_user[i].value
                 << " \t\t" << user[account_user_index]->client_user[i].operation
                 << "\t" << user[account_user_index]->client_user[i].time<< endl;
        }
        system("pause");
    }
    else
    {
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             << "please enter the account number correctly!\n";
        goto no;
    }
}
//a function to compute loan eligibility and give loans for customers
void credit(client_info *user[])
{
    system("cls");
    int accNo, choice, account_user_index = 0;
    float loan;
    bool check;
no:
    cout << "please enter account number : ";
    cin >> accNo;
    check = account_checker(accNo, &account_user_index);
    //checks the validity of the account number
    if (check)
    {
        //check whether the person has taken a loan before or not
        if (user[account_user_index]->loan == false)
        {
            if (user[account_user_index]->balance > 1000000000)
            {
                choice = 6;
            }
            else if (user[account_user_index]->balance > 10000000)
            {
                choice = 5;
            }
            else if (user[account_user_index]->balance > 1000000)
            {
                choice = 4;
            }
            else if (user[account_user_index]->balance > 100000)
            {
                choice = 3;
            }
            else if (user[account_user_index]->balance > 10000)
            {
                choice = 2;
            }
            else if (user[account_user_index]->balance > 1000)
            {
                choice = 1;
            }
            else
            {
                cout << "your are not eligible for loan!! come back another time!\n";
                system("pause");
            }
        }
        else
        {
            cout << "you have previously taken a loan! you cannot take a loan any more!\n";
            system("pause");
        }
        //depending on the balance it will give the user the appropriate choice
        switch (choice)
        {
        case 1:
        {
            cout << "the maximum amount of money you are allowed to borrow is [5000 birr]\n";
            cout << "how much money would you like to borrow: ";
            cin >> loan;
            user[account_user_index]->balance += loan;
            user[account_user_index]->debt += loan;
            user[account_user_index]->loan = true;
            cout << "operation successful\n";
            break;
        }
        case 2:
        {
            cout << "the maximum amount of money you are allowed to borrow is [50,000 birr]\n";
            cout << "how much money would you like to borrow: ";
            cin >> loan;
            user[account_user_index]->balance += loan;
            user[account_user_index]->debt += loan;
            user[account_user_index]->loan = true;
            cout << "operation successful\n";
            break;
        }
        case 3:
        {
            cout << "the maximum amount of money you are allowed to borrow is [500,000 birr]\n";
            cout << "how much money would you like to borrow: ";
            cin >> loan;
            user[account_user_index]->balance += loan;
            user[account_user_index]->debt += loan;
            user[account_user_index]->loan = true;
            cout << "operation successful\n";
            break;
        }
        case 4:
        {
            cout << "the maximum amount of money you are allowed to borrow is [5,000,000 birr]\n";
            cout << "how much money would you like to borrow: ";
            cin >> loan;
            user[account_user_index]->balance += loan;
            user[account_user_index]->debt += loan;
            user[account_user_index]->loan = true;
            cout << "operation successful\n";
            break;
        }
        case 5:
        {
            cout << "the maximum amount of money you are allowed to borrow is [50,000,000 birr]\n";
            cout << "how much money would you like to borrow: ";
            cin >> loan;
            user[account_user_index]->balance += loan;
            user[account_user_index]->debt += loan;
            user[account_user_index]->loan = true;
            cout << "operation successful\n";
            break;
        }
        case 6:
        {
            cout << "the maximum amount of money you are allowed to borrow is [500,000,000 birr]\n";
            cout << "how much money would you like to borrow: ";
            cin >> loan;
            user[account_user_index]->balance += loan;
            user[account_user_index]->debt += loan;
            user[account_user_index]->loan = true;
            cout << "operation successful\n";
            break;
        }
        default:
            break;
        }
    }
    else
    {
        cout << "the account number you entered doesnot match any account holder in the datatbase:"
             << "please enter the account number correctly!\n";
        system("pause");
        goto no;
    }
}
// customers statstical report for descion making by banks
void multi_stati(client_info *user[])
{
    int sum, below_checker = 0, above_checker = 0;
    int ch_checker = 0, sav_checker = 0, int_checker = 0, wout_checker = 0, comp_checker = 0, comp2_checker = 0;
    int comS_checker = 0, comC_checker = 0, intS_checker = 0, intC_checker = 0;
    cout << "==========================================================================================\n";
    cout << "\n\tnumber of clients: " << total_user;
    cout << "\n\ttotal capital: ";
    for (int i = 0; i < counter; ++i)
    {
        sum += user[i]->balance;
    }
    cout << sum;
    cout << "\n\tnumber of clients below 100,000 balance: ";
    for (int i = 0; i < counter; ++i)
    {
        if (user[i]->balance < 100000)
        {
            below_checker++;
        }
    }
    cout << below_checker;
    cout << "\n\tnumber of clients above 100,000 balance: ";
    for (int i = 0; i < counter; ++i)
    {
        if (user[i]->balance > 100000)
        {
            above_checker++;
        }
    }
    cout << above_checker;
    cout << "\n\tnumber of clients with checking account: ";
    for (int i = 0; i < counter; ++i)
    {
        if (user[i]->account_choice == acc_choice[0])
        {
            ch_checker++;
        }
    }
    cout << ch_checker;
    cout << "\n\tnumber of clients with saving account: ";
    for (int i = 0; i < counter; ++i)
    {
        if (user[i]->account_choice == acc_choice[1])
        {
            sav_checker++;
        }
    }
    cout << sav_checker;
    cout << "\n\tnumber of clients with saving account and with interest: ";
    for (int i = 0; i < counter; ++i)
    {
        if ((user[i]->account_choice == acc_choice[1]) && (user[i]->account_type == acctype[0]))
        {
            comS_checker++;
        }
    }
    cout << comS_checker;
    cout << "\n\tnumber of clients with checking account and with interest: ";
    for (int i = 0; i < counter; ++i)
    {
        if (user[i]->account_choice == acc_choice[0] && user[i]->account_type == acctype[0])
        {
            comC_checker++;
        }
    }
    cout << comC_checker;
    cout << "\n\tnumber of clients with checking account and without interest: ";
    for (int i = 0; i < counter; ++i)
    {
        if (user[i]->account_choice == acc_choice[0] && user[i]->account_type == acctype[1])
        {
            intC_checker++;
        }
    }
    cout << intC_checker;
    cout << "\n\tnumber of clients with Saving account and without interest: ";
    for (int i = 0; i < counter; ++i)
    {
        if (user[i]->account_choice == acc_choice[1] && user[i]->account_type == acctype[1])
        {
            intS_checker++;
        }
    }
    cout << intS_checker;
    cout << "\n\tnumber of tranaction by clients with interest account: " << interest_counter;
    cout << "\n\tnumber of tranaction by clients with out interest account: " << with_out_counter;
    cout << "\n\tnumber of tranaction by clients as a whole: " << tran_counter;

    cout << "\n==========================================================================================\n";
    system("pause");
}
//administrator access function for high level bank officials
void admin()
{
    int id, pass;
    bool check_id, check_pass;

    cout << setw(10) << "**************************************************\n";
again:
    cout << setw(25) << "enter your admin id ";
    cin >> id;
    for (int i = 0; i < 10; i++)
    {
        if (id == admin_id[i])
        {
            check_id = true;
        }
    }
    cout << setw(25) << "enter your password ";
    cin >> pass;
    for (int i = 0; i < 10; i++)
    {
        if (pass == admin_pass[i])
        {
            check_pass = true;
        }
    }

    if (check_id == true && check_pass == true)
    {
        bool isDone = true;
        while (isDone)
        {
            int choose;
            cout << "[1] for total customer list information\n"
                 << "[2] for general statstical report\n"
                 << "[3] to sign out!";
            cin >> choose;
            switch (choose)
            {
            case 1:
                customer_list(user);
                break;
            case 2:
                multi_stati(user);
                break;
            case 3:
                isDone = false;
                break;
            default:
                break;
            }
        }
    }
    else
    {
        cout << "wrong password or Admin id please enter you credential again!!\n";
        goto again;
    }
}
