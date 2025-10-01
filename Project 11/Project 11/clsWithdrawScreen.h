#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include "clsInputValidate.h"
#include "clsTransactionScreen.h"

class clsWithdrawScreen : protected clsScreen
{

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "Enter Account Number: ";
        getline(cin, AccountNumber);
        return AccountNumber;
    }

public :
    static void ShowWithdrawscreen()
    {
        _DrawScreenHeader("\tDeposit Screen");

        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient  With " << AccountNumber << " is not exist" << endl;
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease Enter Deposit Amount ? ";
        Amount = clsInputValidate::ReadDoubleNumber();

        char ans;
        cout << "\nAre You Sure You Want Perform This Transaction ? (y/n)";
        cin >> ans;

        if (toupper(ans) == 'Y')
        {
            if (Client.Withdraw(Amount))
            {

                cout << "\nAmount Withdraw succesffuly \n";
                cout << "\nNew Balance Is " << Client.AccountBalance;
            
            }
            else
            {
                cout << "\nCannot Withdraw, Insuffecient Balance!\n";
                cout << "\nAmount To Withdraw Is : " << Amount;
                cout << "\nYour Balance Is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\nDeposition Was Cancelled \n";
        }
        
       
    }
};

