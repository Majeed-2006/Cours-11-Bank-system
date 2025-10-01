#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h";
class clsAddNewClientScreen :protected clsScreen
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
		cout << "\nFirstName   : " <<Client.FirstName;
		cout << "\nLastName    : " <<Client.LastName;
		cout << "\nFull Name   : " <<Client.FullName();
		cout << "\nEmail       : " <<Client.Email;
		cout << "\nPhone       : " <<Client.Phone;
		cout << "\nAcc. Number : " <<Client.AccountNumber();
		cout << "\nPassword    : " <<Client.PinCode;
		cout << "\nBalance     : " <<Client.AccountBalance;
		cout << "\n___________________\n";

	}


public :
	static void ShowAddNewClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
			return;

		_DrawScreenHeader("\t  Add New Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber));
		{
			cout << "\nAccount Number is Already Used , Enter  Other Account Number :";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject();
	    _ReadClientInfo(NewClient);
		clsBankClient::enSaveResults SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
			cout << "\nAccount Added Successfully ;-)";
			_PrintClient(NewClient);
			break;
		case clsBankClient::enSaveResults::svFaildEmptyOpject:
			cout << "\nError , account was not saved because it`s empty";
			break;
		case clsBankClient::enSaveResults::svFaildAccountnumberExist:
			cout << "\nError , account was not saved because account number is used";
			break;
		}

	}
	

};

