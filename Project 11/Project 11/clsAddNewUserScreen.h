#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsAddNewUserScreen : protected clsScreen
{

	static void _ReadUserInfo(clsUser &User)
	{
		cout << "\nEnter a First Name :";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter a Last Name :";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email :";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone :";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password :";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions :";
		User.Permissions= clsInputValidate::ReadFloatNumber();
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName();
		cout << "\nPassword    : " << User.Password;
		cout << "\nPerimissions     : " << User.Permissions;
		cout << "\n___________________\n";

	}
	static int _ReadPermissionsToSet()
	{

		short res = 0;
		cout << "\nDo you want to give full acces y/n ?";
		char ans;
		cin >> ans;
		if (tolower(ans) == 'y')
		{
			return -1;
		}


		cout << "\nDo you want to give accsess to :";

		cout << "\n\nShow Client List y/n ? :";
		cin >> ans;
		if (tolower(ans) == 'y')
			res += clsUser::enPermissions::pListClients;

		cout << "\n\nAdd new Client y/n ? :";
		cin >> ans;
		if (tolower(ans) == 'y')
			res += clsUser::enPermissions::pAddNewClient;

		cout << "\n\nDelete Client y/n ? :";
		cin >> ans;
		if (tolower(ans) == 'y')
			res += clsUser::enPermissions::pDeleteClient;

		cout << "\nUpdate Client y/n ? :";
		cin >> ans;
		if (tolower(ans) == 'y')
			res += clsUser::enPermissions::pUpdateClient;

		cout << "\nFind Client y/n ? :";
		cin >> ans;
		if (tolower(ans) == 'y')
			res += clsUser::enPermissions::pFindclient;

		cout << "\nTransactions y/n ? :";
		cin >> ans;
		if (tolower(ans) == 'y')
			res += clsUser::enPermissions::pTransactionClient;

		cout << "\nManage Users y/n ? :";
		cin >> ans;
		if (tolower(ans) == 'y')
			res += clsUser::enPermissions::pManageUser;

	}
public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t  Add New User Screen");

		string UserName = "";
		cout << "\nPlease Enter User Name : ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName));
		{
			cout << "\nUser Name is Already Used , Enter  Other Account Number :";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject();
		_ReadUserInfo(NewUser);
		clsUser::enSaveResults SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case  clsUser::enSaveResults::svSucceeded:
			cout << "\nAccount Added Successfully ;-)";
			_PrintUser(NewUser);
			break;
		case clsUser::enSaveResults::svFaildEmptyOpject:
			cout << "\nError , account was not saved because it`s empty";
			break;
		case clsUser::enSaveResults::svFaildAccountnumberExist:
			cout << "\nError , account was not saved because account number is used";
			break;
		}
	}
};

