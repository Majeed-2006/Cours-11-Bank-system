#pragma once
#include <fstream>
#include<vector>
#include "clsPerson.h"
#include "clsString.h"

class clsUser : public clsPerson
{
	enum enMode { EmptyMode=1, UpdateMode=2,AddNewMode=3};
   
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkForDelete = false;




    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

    }

    static string _ConvertUserObjectToLine(clsUser User, string seperator = "#//#")
    {

        string line;
        line += User.FirstName + seperator;
        line += User.LastName + seperator;
        line += User.Email + seperator;
        line += User.Phone + seperator;
        line += User.UserName() + seperator;
        line += User.Password + seperator;
        line += to_string(User.Permissions);
        return line;
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static  vector <clsUser> _LoadUserDateFromFile()
    {
        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                clsUser Client = _ConvertLinetoUserObject(Line);
                vUsers.push_back(Client);
            }
            MyFile.close();
        }
        return vUsers;
    }

    void _Update()
    {
        vector<clsUser> _vUsers = _LoadUserDateFromFile();
        for (clsUser& C : _vUsers)
        {
            if (C.UserName() == UserName())
            {
                C = *this;
                break;
            }
        }
        _SaveUserDataToFile(_vUsers);
    }

    static void _SaveUserDataToFile(vector<clsUser> _vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out);
        if (MyFile.is_open())
        {
            string Line;
            for (clsUser& C : _vUsers)
            {
                if (!C._MarkForDelete)
                {
                    Line = _ConvertUserObjectToLine(C);
                    MyFile << Line << endl;
                }
            }
            MyFile.close();
        }
    }

    void _AddDataLineToFile(string Line)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }




public:

    enum enPermissions { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindclient = 16, pTransactionClient = 32, pManageUser = 64 };

    clsUser(enMode Mode,string FirstName, string LastName, string Email,string Phone, string UserName, string Password, int Permissions)
        : clsPerson(FirstName, LastName, Email, Phone)
    {

        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return _Mode == EmptyMode;
    }

    bool MarkedForDelet()
    {
        return _MarkForDelete;
    }


    string UserName()
    {
        return _UserName;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }
    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;


    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }
    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


    static clsUser Find(string UserName)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User= _ConvertLinetoUserObject(Line);
                if (User.UserName() == Password && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    static bool IsUserExist(string Password)
    {
        clsUser Client = clsUser::Find(Password);
        return !Client.IsEmpty();
    }

    enum enSaveResults { svFaildEmptyOpject = 0, svSucceeded = 1, svFaildAccountnumberExist = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case EmptyMode:
            return svFaildEmptyOpject;

        case UpdateMode:
            _Update();
            return svSucceeded;
            break;
        case AddNewMode:
            if (IsUserExist(_UserName))
                return svFaildAccountnumberExist;
            else {

                _AddNew();
                _Mode = UpdateMode;
                return svSucceeded;
            }


        }
    }

    static clsUser GetAddNewUserObject()
    {
        return clsUser(enMode::AddNewMode, " ", " ", " ", " ", " ", " ", 0);
    }

    bool Delete()
    {
        vector<clsUser> vUsers = _LoadUserDateFromFile();
        for (clsUser& c : vUsers)
        {
            if (c.UserName() == _UserName)
            {
                c._MarkForDelete = true;
                break;
            }

        }
        _SaveUserDataToFile(vUsers);
        *this = _GetEmptyUserObject();
        return true;
    }

    static  vector<clsUser> GetUsersList()
    {
        return _LoadUserDateFromFile();
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;
        if ((this->Permissions & Permission) == Permission)
            return true;
        else
            return false;
    }
};

