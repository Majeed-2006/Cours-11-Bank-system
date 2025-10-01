#pragma once
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
	static void  _Login()
	{
		bool LoginFaild = false;
		string UserName, Password;

		do
		{
			if (LoginFaild)
			{
				cout << "\ninvalid UserName/Password!\n\n";
			}

			cout << "\nEnter User Name : ";
			getline(cin, UserName);

			cout << "\nEnter Password : ";
			getline(cin, Password);

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);

		clsMainScreen::ShowMainMenue();

	}


public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
	    _Login();
	}


};

