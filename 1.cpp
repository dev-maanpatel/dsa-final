#include <iostream>

using namespace std;

class BankAccount{
    
protected:
    string name;
    int accountNumber;
    int balance;

public:
    BankAccount(){
        this->accountNumber = 0;
        this->name = "";
        this->balance = 0;
    }

    void createAccount(int accountNumber, string name){
        this->accountNumber = accountNumber;
        this->name = name;
    }

    int getAccountNumber(){
        return accountNumber;
    }

    void deposit(int amount){
        if (amount > 0){
            this->balance += amount;
            cout << "Deposit successful! Current balance : " << this->balance << endl;
        }
        else{
            cout << " Invalid deposit amount!" << endl;
        }
    }
    void accountDetails(){
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Account Holder Name: " << this->name << endl;
        cout << "Current Balance: " << this->balance << endl;
    }
    void withdraw(int amount){
        if (amount > 0 && amount <= balance){
            this->balance -= amount;
            cout << "Withdrawal successful! Current balance: " << this->balance << endl;
        }else{
            cout << "Invalid Withdrawal Amount" << endl;
        }
    }
};

class SavingAccount : public BankAccount{
    
};

class FixedDeposite : public BankAccount{   
    protected:
        int fixedDeposite;
        int amount;
        int year;
    public :
        FixedDeposite(){
            this->fixedDeposite = 0;
            this->amount = 0;
            this->year = 0;
        }
        int calcInterest(int amount,int year){
            this->amount = amount;
            this->year = year;

            this->fixedDeposite = (this->amount * 8 * this->year)/100;
            cout << "Interest in Fixed Deposite : " << this->fixedDeposite << endl ;
        }
};

int main(){
    FixedDeposite fixedDeposite[5];
    SavingAccount amount[5]; 
    int account = 0;
    int choice;

    do{
        cout << "\n---------------------------------------------------\n";
        cout << "Press 1. For Create Account" << endl;
        cout << "Press 2. For Deposit" << endl;
        cout << "Press 3. For Withdraw" << endl;
        cout << "Press 4. For Account Details" << endl;
        cout << "Press 5. For Fixed Deposite" << endl;
        cout << "Press 6. For Exit" << endl;
        cout << "---------------------------------------------------\n\n";
        
        cout << "Enter Your Choice: ";
        cin >> choice;

    switch (choice){

        case 1:{
            int accountNumber;
            string name;

            cout << "Enter Account Number: ";
            cin >> accountNumber;

            cin.ignore();

            cout << "Enter Account Holder Name: ";
            getline(cin, name);

            amount[account].createAccount(accountNumber, name);
            account++;

            break;
        }

        case 2:{
            int accountNumber;

            cout << "Enter Your Account Number: ";
            cin >> accountNumber;

            bool flag = false;
            for (int i = 0; i < account; i++){
                if (amount[i].getAccountNumber() == accountNumber){
                    flag = true;
                        int amount2;
                        cout << "Enter amount to deposit: ";
                        cin >> amount2;
                        amount[i].deposit(amount2);
                }
            }
            break;
        }
        case 3: {
            int AccountNumber;
            cout << "Enter Account Number: ";
            cin >> AccountNumber;

            bool flag = false;
            for (int i = 0; i < account; i++)
            {
                if (amount[i].getAccountNumber() == AccountNumber)
                {
                    flag = true;
                        int amount3;
                        cout << "Enter amount to deposit: ";
                        cin >> amount3;
                        amount[i].withdraw(amount3);
                }
            }
            break;
        }

        case 4 :{
            int AccountNumber;
            cout << "Ener Account Number : ";
            cin >> AccountNumber;

            bool flag = false;
            for (int i = 0; i < account; i++){
                if (amount[i].getAccountNumber() == AccountNumber){
                    flag = true;
                       fixedDeposite[i].accountDetails();
                }
            }
            break;
        }

        case 5 : {
            int AccountNumber;
            double amount5,year;
            cout << "Ener Account Number : ";
            cin >> AccountNumber;

            bool found = false;
            for (int i = 0; i < account; i++)
            {
                if (amount[i].getAccountNumber() == AccountNumber)
                {
                    found = true;
                    cout << "Enter amount you want to deposite : ";
                    cin >> amount5;
                    cin.ignore();
                    cout << "Enetr no. of year for you want to deposite above amount : ";
                    cin >> year;
                    fixedDeposite[i].calcInterest(amount5,year);
                     
                }
            }
            break;
        }
        case 6 : {
            cout << "Thank You!!" << endl;
            cout << "       Visit Again....." << endl;
            break;
        }
        default:{
            cout << "Invalide Choice...";
        }
        
        }
    }
    while (choice != 6);

    return 0;
}