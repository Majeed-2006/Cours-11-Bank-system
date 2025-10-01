#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include "clsInputValidate.h"

class clsDeletClientScreen : protected clsScreen
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
public:
	static void ShowDeletClientScreen()
	{

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
            return;

        _DrawScreenHeader("\tDelet Client Screen");

        string AccountNumber;   
        cout << "\n Enter Account number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nAre you sure you want to delete this client y/n ?";
        char Ans;
        cin >> Ans;
        if (Ans == 'y' || Ans == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nClient Deleted Succesfully :-)\n";
                _PrintClient(Client);
            }
            else
            {
                cout << "\nError, Client Was Not Deleted";
            }
        }

	}


};

