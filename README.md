Bank & Currency Exchange System (C++)
A comprehensive, modular Console Application built in C++ using Object-Oriented Programming (OOP) principles, Clean Architecture (UI/Business Logic separation), custom utility libraries, and file persistence.

Comprehensive Features
Client Management
Full CRUD: Add, Update, Find, Delete, and List Bank Clients.

Balances Overview: Total Balances calculations with dynamic summaries.

Transactions Module
Core Operations: Deposit, Withdraw, and Transfer between accounts.

Transfer Log History: Detailed audit trail of all transactions with timestamp, accounts, and amounts.

Currency Exchange Center
Currency Lookup: Search by Country Name or Code.

Rate Management: Update conversion rates.

Currency Calculator: Multi-currency converter.

User Management & Access Control
User Control: Full CRUD for system users.

Permission Engine (RBAC): Restrict/allow access per user for specific screens.

Audit Logs: Login Register tracking user access history.

Project Architecture & Modules
The application follows a Decoupled Screen-Based UI System separated from domain models and data access:

Plaintext
Bank-System-Project/
├── Domain Models & Data:
│   ├── clsPerson.h / clsBankClient.h / clsUser.h / clsCurrency.h
│   ├── clsDate.h / clsString.h / clsUtil.h / clsInputValidate.h
│   └── Clients.txt / Currencies.txt / LoginRegister.txt
│
├── Screens (User Interface Layer):
│   ├── Main & Management:     clsMainScreen.h, clsManageUsersScreen.h
│   ├── Client Operations:     clsAddNewClientScreen.h, clsDeleteClientScreen.h, clsFindClientScreen.h, clsClientListScreen.h
│   ├── User Operations:       clsAddNewUserScreen.h, clsDeleteUserScreen.h, clsFindUserScreen.h, clsListUsersScreen.h
│   ├── Transactions:          clsTransactionScreen.h, clsDepositScreen.h, clsWithdrawScreen.h, clsTranfareScreen.h, clsTransfareListScreen.h
│   └── Currency Exchange:     clsCurrencyExchangeScreen.h, clsCurrencyCalculatorScreen.h, clsUpdateRateScreen.h, clsFindCurrencyScreen.h
