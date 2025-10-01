#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsMainScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersScreen : protected clsScreen
{
	enum enManageUsersMenueOption 
	{
		eListUsers =1, eAddNewUser=2,eDeleteUser=3,eUpdateUser=4,eFindUser=5,eMainMenue=6
	};
	static void _ShowUsersList()
	{
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeletUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _GoBackToManageUsersScreen()
	{
		cout << "\n\nPress any kay to go back to Manage Users menue...";
		system("pause>0");
		ShowManageUsersScreen();
	}
	static void _PerformManageUsersOptions(enManageUsersMenueOption ManageUsers)
	{
		switch (ManageUsers)
		{
		case eListUsers:
			system("Cls");
			_ShowUsersList();
			_GoBackToManageUsersScreen();
			break;

		case eAddNewUser:
			system("Cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersScreen();
			break;

		case eDeleteUser:
			system("Cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersScreen();
			break;

		case eUpdateUser:
			system("Cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersScreen();
			break;

		case eFindUser:
			system("Cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}


	}

	static int _ReadManageUsersOption()
	{
		cout<<setw(37) <<left << "Chose what do you want to do? [1 to 6]\n";
		int choice = clsInputValidate::ReadIntNumberBetween(1, 6,"Invalid Number, Enter a Number Between 1 and 6");
		return choice;
	}
public:
	static void   ShowManageUsersScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pManageUser))
			return;
		system("Cls");
		_DrawScreenHeader("\t Manage Users Screen");
		cout << setw(37)<<left << "==========================================\n\n";
		cout << setw(37)<<left << "\t   Manage Users Menue \n";
		cout << setw(37)<<left << "==========================================\n";
		cout << setw(37)<<left << "     [1] List User.\n";
		cout << setw(37)<<left << "     [2] Add New User.\n";
		cout << setw(37)<<left << "     [3] Delete User.\n";
		cout << setw(37)<<left << "     [4] Update User.\n";
		cout << setw(37)<<left << "     [5] Find User.\n";
		cout << setw(37)<<left << "     [6] Main Menue.\n";
		cout << setw(37)<<left << "==========================================\n";

		_PerformManageUsersOptions(enManageUsersMenueOption(_ReadManageUsersOption()));
	}
};

