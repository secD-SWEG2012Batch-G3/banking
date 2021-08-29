#include<iostream>
#include<string>
using namespace std;
struct bank
{
    string name;
    string dob;
    char address[20];
    float balance;
    int accnum;

};

bank user[1000];
int counter = 0;
int accnum=10000;

void menu();
int accountNumberCheck();
void deposit();
void withdraw();
void checkBalance();
void transfer();
void get();

int main()
{

    int choice;
    bool checker = true;

    while(checker)
    {
        menu();
        cout<<"enter choice "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:get();break;
        case 2:withdraw();break;
        case 3:deposit();break;
        case 4:checkBalance();break;
        case 5:transfer();break;
        case 6:checker = false;break;
        default:
            break;
        }
    }
    return 0;
}
void menu()
{
    cout<<"****************************************************************"<<endl;
    cout<<"***********************BANK************************************"<<endl;
    cout<<"**************************************************************"<<endl;

    cout<<"enter number 1-6"<<endl;
    cout<<"1.creat bank account "<<endl;
    cout<<"2.withdraw"<<endl;
    cout<<"3.Deposit"<<endl;
    cout<<"4.check balance"<<endl;
    cout<<"5.transfer"<<endl;
    cout<<"6.exit"<<endl;
}
void get()
{
    cout<<	"enter your name please"<<endl;
    cin>>user[counter].name;
    cout<<"enter your address please"<<endl;
    cin>>user[counter].address;
    cout<<"enter the initial deposite ..the min amount of money u can deposite is 50 birr"<<endl;
    cin>>user[counter].balance;
    while(user[counter].balance < 50)
    {
        cout<<"sorry,the min amout is 50 birr"<<endl;
        cin >> user[counter].balance;
    };
    user[counter].accnum = 10000 + counter;
    counter++;
}
void transfer()
{
    system("cls");

    int accountFrom, accountTo;
    float transferredMoney;
    cout << "Sender ";
    accountFrom = accountNumberCheck();
    cout << "Reciever ";
    accountTo = accountNumberCheck();
    cout << "Amount of money to be transferred \n";
    cin >> transferredMoney;
    if(user[accountFrom].balance > transferredMoney) {
            user[accountTo].balance += transferredMoney;
            user[accountFrom].balance -= transferredMoney;
        }
    else
        cout << "Insufficient balance \n";
}
int accountNumberCheck() {
    int accountNum;
    cout << "Account Number: ";
    cin >> accountNum;
    for(int i = 0; i < counter; i++){
        if( user[i].accnum == accountNum){
                   return i;
        }
    }
}
void deposit()
{
    int num = accountNumberCheck();
    cout << "Enter deposit Money: \n";
    int depositMoney;
    cin >> depositMoney;
    user[num].balance += depositMoney;
}
void withdraw()
{
    int num = accountNumberCheck();
    cout << "Enter deposit Money: \n";
    int depositMoney;
    cin >> depositMoney;
    user[num].balance -= depositMoney;
}
void checkBalance() {
    system("cls");
    int accountBalanceCheck = accountNumberCheck();
    cout <<"Balance: " <<  user[accountBalanceCheck].balance << endl;
}
