#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

struct Address
{
    string city;
    string woreda;
    string house_num;
};
struct BOD
{
    int date;
    int month;
    int year;
};
struct info
{
    string name;
    int accountNum;
    int amount;
    Address addr;
    BOD birth;
    char id[20];
    char residence;
    int age;
    char sex;
    char emp_type;
};

void create_acc();
void deposit();
int withdraw();
void showInfo(info client);
int accountNumberCheck();


int counter = 0;
info *client[10];

int main()
{
    //system ("color 3E");
    int choice;
    bool isDone = true;
    while (isDone)
    {
        cout << "\n------------------Menu------------------------\n";
        cout << "Enter 1 to create new account.\n";
        cout << "Enter 2 to deposit money on your account.\n";
        cout << "Enter 3 to withdraw money from your account.\n";
        cout << "Enter 4 to transfer money.\n";
        cout << "Enter 5 to modify your personal information.\n";
        cout << "Enter 6 to see your information.\n";
        cout << "Enter 7 to delete your account.\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create_acc();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
       case 4:
            isDone = false;
            break;
        }
    }
    return 0;
}

void create_acc()
{
    client[counter] = new info;
    cout << "Enter your full name: ";
    cin >> client[counter]->name;
    cout << "\nEnter your address: ";
    cout << "\nCity: ";
    cin >> client[counter]->addr.city;
    cout << "\nWoreda: ";
    cin >> client[counter]->addr.woreda;
    cout << "\nHouse number: ";
    cin >> client[counter]->addr.house_num;
    cout << "\nEnter your date of birth: ";
    cout << "\nDate: ";
    cin >> client[counter]->birth.date;
    cout << "\nMonth: ";
    cin >> client[counter]->birth.month;
    cout << "\nYear: ";
    cin >> client[counter]->birth.year;
    cout << "Enter government ID or passport number or driving licence: ";
    cin >> client[counter]->id;
    cout << "\nYou have successfully created an account.\n";
    cout << "Your account number is: " << client[counter]->accountNum;
    cout << "\nEnter the amount of money you want to deposit: ";
    cin >> client[counter]->amount;
    //showInfo(client[]);
    client[counter]->accountNum = 1000 + counter;
    counter++;
}

void deposit()
{
    int money;
    string name;
    int accountNum;
    cout << "\nEnter your full name: ";
    cin >> name;
    cout << "Enter our account number: ";
    cin >> accountNum;

    for (int i = 0; i < counter; i++)
    {

        if ((name == client[i]->name) && (accountNum == client[i]->accountNum))
        {
            cout << "Enter the amount of money you want to deposit: ";
            cin >> money;
            client[i]->amount += money;
            cout << "You have deposited " << money << "birr\n";
            cout << "Your current account balance is " << client[i]->amount << endl;
        }
        else
            cout << "There is no account with this name and account number.";
    }
}

int accountNumberCheck() {
    int accountNum;
    cout << "Account Number: ";
    cin >> accountNum;
    for(int i = 0; i < counter; i++)
        if(accountNum==User[i]->accountNumber)   // does account number exist;
             if(User[i]->activeUser)             // is the account active;
                   return i;
}
int withDraw() {
    system("cls");
    int fromAccountIndex = accountNumberCheck();
    cout << "Many to withdraw \n";
    int withdrawMoney;
    cin >> withdrawMoney;

            User[fromAccountIndex]->balance -=withdrawMoney;
            cout << "Transaction completed \n";

    return 0;
}

void showInfo(info client)
{
    cout << "\nName: " << client.name;
    cout << "  Address ";
    cout << "\nCity: " << client.addr.city;
    cout << "\nWoreda: " << client.addr.woreda;
    cout << "\nHouse number: " << client.addr.house_num;
    cout << "\nYour date of birth: ";
    cout << "\nDay: " << client.birth.date;
    cout << "\nMonth: " << client.birth.month;
    cout << "\nYear: " << client.birth.year;
    cout << "\nGovernment ID or passport number or driving licence: " << client.id, 20;
    cout << "\nAccount number: " << client.accountNum;
    cout << "\nCurrent amount of money : " << client.amount;
}

