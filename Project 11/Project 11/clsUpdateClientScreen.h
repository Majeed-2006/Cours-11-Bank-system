#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter a First Name :";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter a Last Name :";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email :";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone :";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode :";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance :";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }
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

	static void ShowUpdateClientScreen()
	{

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
            return;

        _DrawScreenHeader("\tUpdate Client Screen");
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
            cout << "\n\nUpdate Client Info : " << "\n_______________________\n";
            _ReadClientInfo(Client);

            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
                cout << "\nAccount Updated Successfully ;-)";
                _PrintClient(Client);
                break;
            case clsBankClient::enSaveResults::svFaildEmptyOpject:
                cout << "\nError , account was not saved because it`s empty";
                break;
            }
        }
	}
};

