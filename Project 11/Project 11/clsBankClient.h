#pragma once
#include "clsPerson.h"
#include "clsInputValidate.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode=2};
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));

    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string seperator = "#//#")
    {
        
            string line;
            line += Client.FirstName + seperator;
            line += Client.LastName + seperator;
            line += Client.Email + seperator;
            line += Client.Phone + seperator;
            line += Client.AccountNumber() + seperator;
            line += Client.PinCode + seperator;
            line += to_string(Client.AccountBalance);
            return line;
        }
    
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static  vector <clsBankClient> _LoadClientDateFromFile()
    {
        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }

    void _Update()
    {
        vector<clsBankClient> _vClients = _LoadClientDateFromFile();
        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientDataToFile(_vClients);
    }

    static void _SaveClientDataToFile(vector<clsBankClient> _vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);
        if (MyFile.is_open())
        {
            string Line;
            for (clsBankClient& C : _vClients)
            {
                if (!C._MarkForDelete) 
                {
                    Line = _ConvertClientObjectToLine(C);
                    MyFile << Line << endl;
                }
            }
            MyFile.close();
        }
    }

    void _AddDataLineToFile(string Line)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }
    
public:

    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }



    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;



    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;



    static clsBankClient Find(string AccountNumber)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return !Client.IsEmpty();
    }

    enum enSaveResults {svFaildEmptyOpject=0,svSucceeded=1,svFaildAccountnumberExist=2};

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
            if (IsClientExist(_AccountNumber))
            {
                return svFaildAccountnumberExist;
            }
            else 
            {

                _AddNew();
                _Mode = UpdateMode;
                return svSucceeded;
            }


        }
    }

    static clsBankClient GetAddNewClientObject()
    {
        return clsBankClient(enMode::AddNewMode, " ", " ", " ", " ", " ", " ", 0);
    }

    bool Delete()
    {
        vector<clsBankClient> vClients = _LoadClientDateFromFile();
        for (clsBankClient& c : vClients)
        {
            if (c.AccountNumber() == _AccountNumber)
            {
                c._MarkForDelete = true;
                break;
            }
            
        }
        _SaveClientDataToFile(vClients);
        *this = _GetEmptyClientObject();
        return true;
    }

   static  vector<clsBankClient> GetClientsList()
    {
        return _LoadClientDateFromFile();
    }

   static float GetTotalBalances()
   {
       vector<clsBankClient> vClients = clsBankClient::GetClientsList();
       float TotalBalances=0;
       for (clsBankClient c : vClients)
       {
           TotalBalances += c.AccountBalance;
       }
       return TotalBalances;
   }

   void Deposit(double Amount)
   {
       _AccountBalance += Amount;
       Save();
   }

   bool Withdraw(double Amount)
   {
       if (Amount > _AccountBalance)
       {
           return false;
       }
       else
       {
           _AccountBalance -= Amount;
           Save();
           return true;
       }
   }

 
};