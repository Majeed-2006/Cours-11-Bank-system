#pragma once
#include "clsUtil.h"
#include <limits>

	class clsInputValidate
	{

	 public:

		 static bool IsNumberBetween(int number, int a, int b)
		 {
			 return number >= a && number <= b;
		 }

		 static bool IsNumberBetween(float number, float a,  float b)
		 {
			 return number > a && number < b;
		 }

		 static bool IsNumberBetween(double number, double a, double b)
		 {
			 return number > a && number < b;
		 }
		 static bool IsDateBetween(clsDate Date, clsDate a, clsDate b)
		 {
			 bool Case1 = clsDate::IsDate1BeforDate2(a, Date) && clsDate::IsDate1BeforDate2(Date, b);
			 bool Case2 = clsDate::IsDate1BeforDate2(b, Date) && clsDate::IsDate1BeforDate2(Date, a);
			 bool Case3 = clsDate::IsDatesEqual(Date, a) || clsDate::IsDatesEqual(Date, b);

			 return Case1 || Case2 || Case3;
		 }

		/* static int ReadIntNumber(string Massage = "Invalid Number, enter Again")
		 {
			 string Number;
			 bool Valid = false;
			 do
			 {
				 Valid = true;
				 try {
					 getline(cin, Number);
					 return stoi(Number);
				 }
				 catch (...)
				 {
					 Valid = false;
					 cout << Massage << endl;
				 }
			 } while (!Valid);
		 }
		 */

		 static int ReadIntNumber(string Message = "Invalid Number, enter Again")
		 {
			 int Number;
			 while (!(cin >> Number))
			 {
				 cin.clear();
				 cin.ignore(numeric_limits<streamsize>::max(), '\n');
				 cout << Message;
			 }
			 return Number;
		 }

		 static int ReadIntNumberBetween(int from,int to, string Message = "Invalid Number, enter Again")
		 {
			 int Number = ReadIntNumber("Invalid Number, Enter Again");
			 while (!IsNumberBetween(Number, from, to))
			 {
				 cout << Message << endl;
				 Number = ReadIntNumber("Invalid Number, Enter Again");

			 }
			 return Number;
		 }

		 static double ReadDoubleNumber(string Message = "Invalid Number, enter Again")
		 {
			 double Number;
			 while (!(cin >> Number))
			 {
				 cin.clear();
				 cin.ignore(numeric_limits<streamsize>::max(), '\n');
				 cout << Message;
			 }
			 return Number;
		 }

		 static double ReadDoubleNumberBetween(double from, double to, string Message = "AHA")
		 {
			 double Number = ReadDoubleNumber("Invalid Number, Enter Again");
			 while (!IsNumberBetween(Number, from, to))
			 {
				 cout << Message << endl;
				 Number = ReadDoubleNumber("Invalid Number, Enter Again");

			 }
			 return Number;
		 }

		 static float ReadFloatNumber(string Message = "Invalid Number, enter Again")
		 {
			 float Number;
			 while (!(cin >> Number))
			 {
				 cin.clear();
				 cin.ignore(numeric_limits<streamsize>::max(), '\n');
				 cout << Message;
			 }
			 return Number;
		 }

		 static  bool IsValidDate(clsDate Date)
		 {
			 return clsDate::IsValidDate(Date);
		 }
		 
		 static string ReadString()
		 {
			 string Value;
			 getline(cin >> ws, Value);
			 return Value;
		 }
	};

