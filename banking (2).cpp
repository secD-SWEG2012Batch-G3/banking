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
    char name[20];
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
bool accMoney_checker(int, int);
void deposit();
void withdraw();
void tranfer();
void checkBalance();
void modify();
void showInfo();
void deleteAcc();

int counter = 0;
info *client[10];

int main()
{
    system ("color 3E");
    cout << "\n    WELCOME TO ONLINE BANKING SYSTEM!!!\n";
    int choice;
    bool isDone = true;

    while (isDone)
    {
        choice:
        cout << "\n  ****************Menu**************************\n";
        cout << "    Enter 1 to create new account.\n";
        cout << "    Enter 2 to deposit money on your account.\n";
        cout << "    Enter 3 to withdraw money from your account.\n";
        cout << "    Enter 4 to transfer money.\n";
        cout << "    Enter 5 to check your balance.\n";
        cout << "    Enter 6 to see your information.\n";
        cout << "    Enter 7 to modify your personal information.\n";
        cout << "    Enter 8 to delete your account.\n";
        cout << "    Enter 0 to exit.\n";
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
            checkBalance();
            break;
        case 6:
            showInfo();
            break;
        case 7:
            modify();
            break;
        case 8:
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
    cin.ignore();
    cin.getline(client[counter]->name,20);
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
bool accMoney_checker(int money, int index)
{
    bool exist;
    for(int i=0;i<counter;i++){
       if((client[index]->amount-money)>0)
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
            checkMoney=accMoney_checker(money,index);
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
    int senderIndex=0;
    int recieverIndex=0;
    bool checkSender;
    bool checkReciever;
    bool checkMoney;
    int money;
    int senderAccountNum;
    int recieverAccountNum;
    cout << "Enter our account number: ";
    cin >> senderAccountNum;
    checkSender=accNum_checker(senderAccountNum,&senderIndex);

    if(checkSender==true){
            cout << "Enter the account number you want to transfer money to: ";
            cin >> recieverAccountNum;
            checkReciever=accNum_checker(recieverAccountNum,&recieverIndex);

            if(checkReciever==true){
                cout << "Enter the amount of money you want to transfer: ";
                cin >> money;

            checkMoney=accMoney_checker(money,senderIndex);
            if(checkMoney==true){
            client[senderIndex]->amount -= money;
            client[recieverIndex]->amount += money;
            cout << "You have successfully transfer " << money << "birr to the account number "<<recieverAccountNum;
            cout << "\nYour current account balance is " << client[senderIndex]->amount << endl;

            }
            else
                cout<<"Sorry you can not transfer with your current balance.";


            }
    else
        cout << "There is no account with this account number.";

    }
    else
        cout << "There is no account with this account number.";

}
void checkBalance()
{
    int index=0;
    bool check;
    int accountNum;
    cout << "Enter our account number: ";
    cin >> accountNum;
    check=accNum_checker(accountNum,&index);

    if(check==true){
            cout << "Your current account balance is " << client[index]->amount << endl;
        }

}
void modify()
{
}
void showInfo()
{
    int accountNum;
    cout << "Enter our account number: ";
    cin >> accountNum;
     for(int i=0;i<counter;i++){
        if(accountNum=client[i]->accountNum)
        {
    cout << "\nName: " << client[i]->name;
    cout << " \n Address ";
    cout << "\nCity: " << client[i]->addr.city;
    cout << "\nWoreda: " << client[i]->addr.woreda;
    cout << "\nHouse number: " << client[i]->addr.house_num;
    cout << "\nYour date of birth: ";
    cout << "\nDay: " << client[i]->birth.date;
    cout << "\nMonth: " << client[i]->birth.month;
    cout << "\nYear: " << client[i]->birth.year;
    cout << "\nGovernment ID or passport number or driving licence: " << client[i]->id, 20;
    cout << "\nAccount number: " << client[i]->accountNum;
    cout << "\nCurrent amount of money : " << client[i]->amount;
        }
     }
}

void deleteAcc()
{
}
