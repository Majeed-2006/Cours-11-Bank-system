#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include "clsInputValidate.h"
#include "clsTransactionScreen.h"

class clsDepositScreen  : protected clsScreen
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
	static void ShowDepositScreen()
	{
        _DrawScreenHeader("\tDeposit Screen");

        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one";
            AccountNumber = clsInputValidate::ReadString();
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
            Client.Deposit(Amount);
            cout << "\nAmount Deposit succesffuly \n";
            cout << "\nNew Balance Is " << Client.AccountBalance;
        }
        else
        {
            cout << "\nDeposition Was Cancelled \n";
        }


	}
};

