#pragma once
#include "clsUser.h"
#include "clsScreen.h"
class clsListUsersScreen :protected clsScreen
{

    static void _PrintUserRecord(clsUser User)
    {
        cout<<setw(8)<<left << "| " << setw(12) << left << User.FirstName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.UserName();
        cout << "| " << setw(12) << left << User.Password;
        cout << endl;
    }

public:
	static void ShowUsersList()
	{
        vector<clsUser> vUsers = clsUser::GetUsersList();
        string Title = "\t  User List Screen";
        string SubTitle = "\t   (" + to_string(vUsers.size()) + ")  User (s)";
        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vUsers.size() == 0)
            cout << "\t\t\t\t NO Clients Avaliable In The System!";
        else
            for ( clsUser User : vUsers)
            {
                _PrintUserRecord(User);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}
};

