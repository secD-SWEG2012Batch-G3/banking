#include <iostream>
using namespace std;
#include<string.h>
#include <cstdlib>

struct Address{
    char city[20];
    char woreda[20];
    char house_num[20];
};

struct BOD{
    int date;
    int month;
    int year;
};

struct info{
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
info account[10];
int n=3;

void create_acc(info &client);
void deposit();
void withdraw();
void tranfer();
void modify();
void showInfo(info client);
void deleteAcc();

info client[100];

int main()
{
    system ("color 3E");

    char choice;
    client[0].accountNum=1000;
    for (int i=0; i<100; i++){

    char choice;

    option:
    cout<<"\n------------------Menu------------------------\n";
    cout<<"Enter 1 to create new account.\n";
    cout<<"Enter 2 to deposit money on your account.\n";
    cout<<"Enter 3 to withdraw money from your account.\n";
    cout<<"Enter 4 to transfer money.\n";
    cout<<"Enter 5 to modify your personal information.\n";
    cout<<"Enter 6 to see your information.\n";
    cout<<"Enter 7 to delete your account.\n";

    cin>>choice;

    switch(choice)
    {
        case '1':
            create_acc(client[i]);
            break;
        case '2':
            deposit();
            break;
        case '3':
            withdraw();
            break;
        case '4':
            tranfer();
            break;
        case '5':
            modify();
            break;
        case '6':
            showInfo(client[i]);
            break;
        case '7':
            deleteAcc();
            break;
        default:
            cout<<"Please enter the correct choice.\n";
            goto option;
    }
    client[i+1].accountNum=client[i].accountNum;
    }
    return 0;
}

void create_acc(info &client)
{
    cout<<"Enter your full name: ";
    cin>>client.name;
    cin.ignore();
    cout<<"\nEnter your address: ";
    cout<<"\nCity: ";
    cin.ignore();
    cin.getline(client.addr.city,20);
    cout<<"\nWoreda: ";
    cin.getline(client.addr.woreda,20);
    cout<<"\nHouse number: ";
    cin.getline(client.addr.house_num,20);
    cout<<"\nEnter your date of birth: ";
    cout<<"\nDate: ";
    cin>>client.birth.date;
    cout<<"\nMonth: ";
    cin>>client.birth.month;
    cout<<"\nYear: ";
    cin>>client.birth.year;
    cout<<"Enter government ID or passport number or driving licence: ";
    cin.ignore();
    cin.getline(client.id,20);
    cout<<"\nYou have successfully created an account.\n";
    cout<<"Your account number is: "<<client.accountNum;
    cout<<"\nEnter the amount of money you want to deposit: ";
    cin>>client.amount;
    showInfo(client);
    client.accountNum++;

    main();
}

void deposit()
{
    int money;
    string name;
    int accountNum;
    cout<<"\nEnter your full name: ";
    cin>>name;
    cout<<"Enter our account number: ";
    cin>>accountNum;

    for (int i=0; i<100; i++){

    if ((name==client[i].name)&&(accountNum==client[i].accountNum)){
            cout<<"Enter the amount of money you want to deposit: ";
            cin>>money;
            client[i].amount+=money;
            cout<<"You have deposited "<<money<<"birr\n";
            cout<<"Your current account balance is "<<client[i].amount<<endl;
    }
     else
        cout<<"There is no account with this name and account number.";
    }
        main();
}
void withdraw()
{
    int money;
    string name;
    int accountNum;
    cout<<"\nEnter your full name: ";
    cin>>name;
    cout<<"Enter our account number: ";
    cin>>accountNum;

    for (int i=0; i<100; i++){

    if ((name==client[i].name)&&(accountNum==client[i].accountNum)){

            cout<<"Enter the amount of money you want to withdraw: ";
            cin>>money;
            client[i].amount-=money;
            cout<<"You withdraw "<<money<<"birr\n";
            cout<<"Your current account balance is "<<client[i].amount<<endl;
    }

    else
        cout<<"There is no account with this name and account number.";
    }
    main();

}
void tranfer()
{

}
void modify()
{



}
void showInfo(info client)
{
    cout<<"\nName: "<<client.name;
    cout<<"  Address ";
    cout<<"\nCity: "<<client.addr.city;
    cout<<"\nWoreda: "<<client.addr.woreda;
    cout<<"\nHouse number: "<<client.addr.house_num;
    cout<<"\nYour date of birth: ";
    cout<<"\nDay: "<<client.birth.date;
    cout<<"\nMonth: "<<client.birth.month;
    cout<<"\nYear: "<<client.birth.year;
    cout<<"\nGovernment ID or passport number or driving licence: "<<client.id,20;
    cout<<"\nAccount number: "<<client.accountNum;
    cout<<"\nCurrent amount of money : "<<client.amount;

}
void deleteAcc()
{

}

