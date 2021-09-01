//banking management system
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string.h>
#include <string>
#include <cmath>
#include <cstdlib>
#include "banking_link.h"

using namespace std;

//function that are used in this program
void welcome();
int task_choice();
void create_account();
void deposit();
void withdrawl();
void check_balance();
void credit(client_info *[]);
void modify(client_info *[]);

void transfer_money(client_info *[]);
void print_user_info(client_info *[]);
void close_account(client_info *[]);
bool account_checker(int accno, int *user_check);
void account_type_choice();
void exit();

//functions used for adminstrators access
void admin();
void total_transaction();
void customer_list(client_info[]);
void multi_stati(client_info *[]);

int main()
{
    int choice;
    bool isDone = true;
    while (isDone)
    {
        system("cls");
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
            print_user_info(user);
            break;
        case 8:
            modify(user);
            break;
        case 9:
            credit(user);
            break;
        case 10:
            admin();
            break;
        case 11:
            isDone = false;
            break;
        }
    }
    return 0;
}
