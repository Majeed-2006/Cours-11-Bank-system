#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeletClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include <iomanip>
#include "Global.h"
class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenueOptions
	{
        eClientList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClientInfo = 4, eFindClient = 5, eTransactions = 6, eManageUser = 7, eLogout = 8
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do ? [ 1 To 8 ] ?";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 8);
        return Choice;
    }
	static void _PrintAllCLientsDataScreen()
	{
		clsClientListScreen::ShowCliensList();
	}	
	static void _ShowAddNewClientScreen() {
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void _ShowDeleteClientScreen() 
	{ 
		clsDeletClientScreen::ShowDeletClientScreen();
	}
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowFindClientScreen() {
		clsShowFindClientScreen::ShowFindClientScreen(); 
	}
	static void _ShowTransactionsMenueScreen()
	{
		clsTransactionScreen::ShowTransactionsMenueScreen();
	}	
	static void _ShowManageUsersMenueScreen() {
	}
	static void _Logout() 
	{
		CurrentUser = clsUser::Find("", "");
	}
	static void _GoBackToMainMenue()
	{
	}

	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case eClientList:
			system("Cls");
			_PrintAllCLientsDataScreen();
			_GoBackToMainMenue();
			break;

		case eAddNewClient:
			system("Cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;

		case eDeleteClient:

			system("Cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;

		case eUpdateClientInfo:

			system("Cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;

		case eFindClient:

			system("Cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;

		case eTransactions:
			system("Cls");
			_ShowTransactionsMenueScreen();
			_GoBackToMainMenue();
			break;

		case eManageUser:
			system("Cls");
			_ShowManageUsersMenueScreen();
			break;

		case eLogout:
			system("Cls");
			_Logout();
			break;
		}
	}
	
public:
    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};

