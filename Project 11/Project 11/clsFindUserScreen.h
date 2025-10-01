#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsFindUserScreen : protected clsScreen
{
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
public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind User Screen");

        string UserName;
        cout << "\n Enter User Name : ";
       UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one";
           UserName = clsInputValidate::ReadString();
        }

        clsUser Client = clsUser::Find(UserName);

        if (!Client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\n Client Was Not Found :-(\n";
        }
    }

};

