#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientListScreen : protected clsScreen
{
    static void _PrintClientRecord(clsBankClient client)
    {
        cout << "| " << setw(15) << left << client.AccountNumber();
        cout << "| " << setw(20) << left << client.FullName();
        cout << "| " << setw(12) << left << client.Phone;
        cout << "| " << setw(20) << left << client.Email;
        cout << "| " << setw(10) << left << client.PinCode;
        cout << "| " << setw(12) << left << client.AccountBalance;
        cout << endl;
    }
public:
    static void ShowCliensList()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
            return;

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ")  Client (s)";
        _DrawScreenHeader(Title, SubTitle);
      

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vClients.size() == 0)
            cout << "\t\t\t\t NO Clients Avaliable In The System!";
        else
            for (clsBankClient client : vClients)
            {
                _PrintClientRecord(client);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

