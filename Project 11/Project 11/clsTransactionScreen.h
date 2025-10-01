#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"

class clsTransactionScreen : protected clsScreen
{
	enum enTransactionMenueOption
	{
		eDeposit = 1 ,eWithdraw =2, eShowTotalBalance =3,eShowMainMenue=4
	};

	static short _ReadTransactionsOption()
	{
		cout <<setw(37)<< "Choose what do you want to do? [1 to 4]\n";
		short chose;
	    chose = clsInputValidate::ReadIntNumberBetween(1,4);
		return chose;
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to transactions menue...";
		system("pause>0");
		ShowTransactionsMenueScreen();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();

	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawscreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _PerformTrancactionsOptions(enTransactionMenueOption TransactionMenueOption)

	{
		switch (TransactionMenueOption)
		{
		case eDeposit:
			system("Cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;

		case eWithdraw:
			system("Cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;

		case eShowTotalBalance:
			system("Cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;

		}
	}

	public:

	static void ShowTransactionsMenueScreen()
		{

		if (!CheckAccessRights(clsUser::enPermissions::pTransactionClient))
			return;

		_DrawScreenHeader("\t Transactions Screen");
		system("Cls");
		cout<<setw(37) << left<< "==========================================\n\n";
		cout<<setw(37) << left<< "\t   Transactions Menue Screen\n\n";
		cout<<setw(37) << left<< "==========================================\n";
		cout<<setw(37) << left<< "     [1] Deposit.\n";
		cout<<setw(37) << left<< "     [2] Withdraw.\n";
		cout<<setw(37) << left<< "     [3] Total Balance.\n";
		cout<<setw(37) << left<< "     [4] Main Menue.\n";
		cout<<setw(37) << left<< "==========================================\n";
		_PerformTrancactionsOptions(enTransactionMenueOption(_ReadTransactionsOption()));
		}
	
};

