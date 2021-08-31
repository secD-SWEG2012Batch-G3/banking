#include<iostream>
#include<string>
using namespace std;
struct bank
{
    string name;
    string kebele;
    string wereda;
    string branch_name;
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
void book();
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
        case 6:book();break;
       // case 7:close();break;
        case 8:checker = false;break;
        
        default:
            break;
        }
    }
    return 0;
    
//    void close(){
//    	
//    	
//	}
}
void book(){
	int i;
	cout<<"################################################"<<endl;
	cout<<"***your bank acount is :***"<<endl;
cout<<"***your name :"<<user[counter].name<<endl; 
 cout<<"***your address:"<<user[counter].address<<endl;  
 cout<<"***your wereda :"<<user[counter].wereda<<endl; 
  cout<<"***your kebele:"<<user[counter].kebele<<endl; 
 cout<<"***the branch you open the book :"<< user[counter].branch_name<<endl; 
  cout<<"***the balance:"<< user[counter].balance<<endl;
  cout<<"***account number:"<<accnum++<<endl;
  	cout<<"################################################"<<endl;
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
    cout<<"6.bank book"<<endl;
    cout<<"7.exit"<<endl;
}
void get()
{
    cout<<	"enter your name please"<<endl;
    cin>>user[counter].name;
    cout<<"enter your address please"<<endl;
    cin>>user[counter].address;
    cout<<"please enter wereda :"<<endl;
    cin>>user[counter].wereda;
    cout<<"enter kebele please :"<<endl;
    cin>>user[counter].kebele;
    cout<<" enter the branch name please"<<endl;
    cin>>user[counter].branch_name;
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

