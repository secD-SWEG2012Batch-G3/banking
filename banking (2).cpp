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
bool accNum_checker(int,int);
bool accMoney_checker(int);
void deposit();
void withdraw();
void tranfer();
void modify();
void showInfo(info client);
void deleteAcc();

int counter = 0;
info *client[10];

int main()
{
    system ("color 3E");
    int choice;
    bool isDone = true;
    while (isDone)
    {
        choice:
        cout << "\n------------------Menu------------------------\n";
        cout << "Enter 1 to create new account.\n";
        cout << "Enter 2 to deposit money on your account.\n";
        cout << "Enter 3 to withdraw money from your account.\n";
        cout << "Enter 4 to transfer money.\n";
        cout << "Enter 5 to modify your personal information.\n";
        cout << "Enter 6 to see your information.\n";
        cout << "Enter 7 to delete your account.\n";
        cout << "Enter 0 to exit.\n";
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
            tranfer();
            break;
        case 5:
            modify();
            break;
        case 6:
            break;
        case 7:
            deleteAcc();
            break;
        case 0:
            isDone = false;
            break;
        default:
            cout<<"Wrong entry. Please select the correct choice.";
            goto choice;
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

    client[counter]->accountNum = 1000 + counter;
    cout << "\nYou have successfully created an account.\n";
    cout << "Your account number is: " << client[counter]->accountNum;
    cout << "\nEnter the amount of money you want to deposit: ";
    cin >> client[counter]->amount;
    //showInfo(client[]);

    counter++;
}
bool accNum_checker(int accountNum,int *index)
{
    bool exist;
    for(int i=0;i<counter;i++){
        if(accountNum=client[i]->accountNum)
        {
            *index=i;
            exist=true;
        }
        else
            exist=false;
    }
    return exist;
}
void deposit()
{
    int index=0;
    bool check;
    int money;
    int accountNum;
    cout << "Enter our account number: ";
    cin >> accountNum;
    check=accNum_checker(accountNum,&index);

    if(check==true){

            cout << "Enter the amount of money you want to deposit: ";
            cin >> money;
            client[index]->amount += money;
            cout << "You have deposited " << money << "birr\n";
            cout << "Your current account balance is " << client[index]->amount << endl;
        }
        else
            cout << "There is no account with this account number.";
    }
bool accMoney_checker(int money)
{
    bool exist;
    for(int i=0;i<counter;i++){
       if((client[counter]->amount-money)>0)
           exist=true;
        else
            exist=false;
    }
    return exist;
}
void withdraw()
{
    int index=0;
    bool check;
    bool checkMoney;
    int money;
    int accountNum;
    cout << "Enter our account number: ";
    cin >> accountNum;
    check=accNum_checker(accountNum,&index);

    if(check==true){

            cout << "Enter the amount of money you want to withdraw: ";
            cin >> money;
            checkMoney=accMoney_checker(money);
            if(checkMoney==true){
            client[index]->amount -= money;
            cout << "You have withdraw " << money << "birr\n";
            cout << "Your current account balance is " << client[index]->amount << endl;
            }
            else
                cout<<"Sorry you can not withdraw with your current balance.";
        }
        else
            cout << "There is no account with this name and account number.";
    }

void tranfer()
{
}
void modify()
{
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
void deleteAcc()
{
}
