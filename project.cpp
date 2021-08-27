#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

class account
{
    int accno;
    char name[50];
    int deposite;
    char type;

public:
void create_account();
void show_account();
void modify();
void dep(int);
void draw(int);
void report() const;
int retaccno() const;
int retdeposite() const;
char rettype() const;
};


void account::create_account()
{
    cout<<"\nenter the account no. :";
    cin>>accno;
    cout<<"\nenter full name of the account holder: ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nenter the type the account(c/s): ";
    cin>>type;
    type=toupper(type);cout<<"\nenter the initial amount: ";
    cin>>deposite;
    cout<<"\n\nACCOUNT CREATED..";

}
void account::show_account()
{
    cout<<"\naccount no.: "<<accno;
    cout<<"\naccount holder name: "<<name;
    cout<<"\ntype of the account: "<<type;
    cout<<"\nbalance amount: "<<deposite;
}

void account::modify()
{
    cout<<"\naccount no. : ";
    cout<<"\nmodify the name of the account holder: ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nmodify the type the account(c/s): ";
    cin>>type;
    type=toupper(type);cout<<"\nenter the initial amount: ";
    cin>>deposite;
    cout<<"your account is succesfully ! ";

}
void account::dep(int x)
{
    deposite+=x;
}
void account::draw(int x)
{
    deposite-=x;
}

void account::report() const
{
    cout<<accno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposite<<endl;
}
int account::retaccno() const
{
    return accno;
}
int account::retdeposite() const
{
    return deposite;
}
char account::rettype() const
{
    return type;
}
void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposite_withdraw(int,int);
void intro();

int main()
{

char ch;
int num;
intro();
do
{
    system("cls");
    cout<<"\n\n\n\tMAIN MENU";
    cout<<"\n\n\t01. NEW ACCOUNT";
    cout<<"\n\n\t02. DEPOSITE AMOUNT";
    cout<<"\n\n\t03. WITHDRAW AMOUNT";
    cout<<"\n\n\t04. BALANCE ENQUIRY";
    cout<<"\n\n\t05. ALL ACOUNT HOLDER LIST";
    cout<<"\n\n\t06. CLOSE AN ACCOUNT";
    cout<<"\n\n\t07. MODIFY AN ACCOUNT";
    cout<<"\n\n\t08. EXIT";
    cout<<"\n\n\tSELECT YOUR OPTION(1-8)";
    cin>>ch;
    system("cls)");
    switch(ch)
    {
    case '1':
        write_account();
        break;
    case '2':
        cout<<"\n\n\tenter the account no.: ";
        cin>>num;
        deposite_withdraw(num,1);
        break;
     case '3':
    cout<<"\n\n\tenter the account no.: ";
    cin>>num;
    deposite_withdraw(num,2);
    break;
     case '4':
        cout<<"\n\n\tenter the account no.: ";
    cin>>num;
    display_sp(num);
    break;
     case '5':
        display_all();
        break;
     case '6':
        cout<<"\n\n\tenter the account no.: ";
    cin>>num;
    delete_account(num);
    break;
     case '7':
        cout<<"\n\n\tenter the account no.: ";
    cin>>num;
    modify_account(num);
    break;
     case '8':
        cout<<"\n\n\tTHANKS FOR USING THIS BANK MANAGEMENT SYSTEM";
        break;
    default :cout<<"\a";
    }
    cin.ignore();
    cin.get();

}while(ch!='8');

}
void write_account()
{
    account acc;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    acc.create_account();
    outFile.write(reinterpret_cast<char *>(&acc), sizeof(account));
    outFile.close();
}
void display_sp(int n)
{
    account acc;
    bool flag=false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"file could not be open!! pres any key...";
        return;
    }
    cout<<"\nBALANCE DETAILS\n";
    while(inFile.read(reinterpret_cast<char *>(&acc), sizeof(account)))
    {
        if(acc.retaccno()==n)
        {
            acc.show_account();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
    cout<<"\n\nthis account number does not exist!";
}
void modify_account(int n)
{
    bool found=false;
    account  acc;
    fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"file could not be open!! press any key..";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *>(&acc), sizeof(account));
        if(acc.retaccno()==n)
        {
            acc.show_account();
            cout<<"\n\nenter the new detail of the account"<<endl;
            acc.modify();
            int pos'(-1)'static_cast<int>(sizeof(account));
            File.seekp(pos,ios::cur);
            file.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout<<"\n\n\t RECORD UPDATED";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n RECORD NOT FOUND";
}
void delete_account(int n)
{
    account acc;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"file could not be open!! press any key..";
        return;
    }
    outFile.open("temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if(acc.retacno()!=n)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("temp.dat","account.dat");
    cout<<"\n\nn\t RECORD DELETED..";
}
void display_all()
{

    account acc;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"FILE COULD NOT OPEN!! PRESS ANY KEY..";
        RETURN;
    }

    cout<<"\n\n\t\tACCUNT HOLDER LIST\n\n";
    cout<<"===================================================================\n";
    cout<<"a/c no.               name            type    balance\n";
    cout<<"====================================================================\n";
    while(inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        acc.report();
    }
    inFile.close();
}
void deposite_withdra(int n,int option)
{
    int ant;
    bool found=false;
    accoun  acc;
    fastream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"file could not be open!! press any key..";
        return;
    }
    while(!File.eof() && found==false)
    {
        file.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if(acc.retacno()==n)
        {
            acc.show_account();
            if(option==1);
            {
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                cout<<"\n\nenter the amount to be deposited";
                cin>>ant;
                acc.dep(ant);
            }
            if(option==2)
            {
                cout<<"\n\n\tWITHDRAW  AMOUNT";
                cout<<"\n\nenter the amount to be withdraw";
                cin>>ant;
                int bal=acc.retdeposite()-ant;
                cout<<acc.draw(ant);
            }
            int pos'(-1)' static cast<int>(sizeof(ac));
            File.seekp(ppos,ios::our);
            file.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout<<"\n\n\t RECORD UPDATED";
            found==true;
      }
    }
    File.close();
    if(found==false)
        cout<<"\n\n RECORD NOT FOUND";
    }
    void intro()
    {
        cout<<"\n\n\t bank";
        cout<<"\n\n\t Management";
        cout<<"\n\n\t System";
        cout<<"\n\n\t MADE BY GROUP 3";

    }
