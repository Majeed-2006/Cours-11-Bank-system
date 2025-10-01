#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen
{
	static void _PrintUser(clsUser User)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << User.FirstName;
		cout << "\nLastName       : " << User.LastName;
		cout << "\nFull Name      : " << User.FullName();
		cout << "\nEmail          : " << User.Email;
		cout << "\nPhone          : " << User.Phone;
		cout << "\nUser Name      : " << User.UserName();
		cout << "\nPassword       : " << User.Password;
		cout << "\nPerimissions   : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:
	static void ShowDeletUserScreen()
	{
        _DrawScreenHeader("\tDelet User Screen");

        string UserName;
        cout << "\n Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this client y/n ?";
        char Ans;
        cin >> Ans;
        if (Ans == 'y' || Ans == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Succesfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError, User Was Not Deleted";
            }
        }
	}
};

