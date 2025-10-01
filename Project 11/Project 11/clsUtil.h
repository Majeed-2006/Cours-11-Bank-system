#pragma once

#include "clsDate.h"
	class clsUtil
	{
		static void PrintHead()
		{
			cout << "\n\n\t\t\tMultiplication Table Frome 1 To 10\n\n";
			cout << "\t";
			for (size_t i = 1; i <= 10; i++)
			{
				cout << i << "\t";
			}
			cout << "\n------------------------------------------------------------------------------------------------------------------------\n";

		}

		static string ColumSperator(int i)
		{
			if (i < 10)
				return "   |";
			else
				return "  |";
		}

	public:
		enum enOprationType { eAdd = '+', eSubtract = '-', eMultiply = '*', eDivide = '/' };
		enum enPrimeNumber { ePrime = 1, eNotPrime = 2 };
		enum enIsPerfect { eNotPerfect = 0, ePerfect = 1 };
		enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialChracter = 3, Digit = 4 };

		static void Srand()
		{
			srand((unsigned)time(NULL));
		}

		static void Swap(int& A, int& B)
		{
			int Temp;
			Temp = A;
			A = B;
			B = Temp;
		}
		static void Swap(bool& A, bool& B)
		{
			bool Temp;
			Temp = A;
			A = B;
			B = Temp;
		}
		static void Swap(double& A, double& B)
		{
			double Temp;
			Temp = A;
			A = B;
			B = Temp;
		}
		static void Swap(char& A, char& B)
		{
			char Temp;
			Temp = A;
			A = B;
			B = Temp;
		}
		static void Swap(string& A, string& B)
		{
			string Temp;
			Temp = A;
			A = B;
			B = Temp;
		}
		static void Swap(clsDate& A, clsDate& B)
		{
			clsDate Temp;
			Temp = A;
			A = B;
			B = Temp;
		}
		static  int ReadNumberInRange(int from, int to)
		{
			int grade;
			do
			{
				cout << "enter your Number From"<<from<<" to "<<to<<" : ";
				cin >> grade;
			} while (grade<from || grade>to);
			return grade;
		}

		static float calculate(float number1, float number2, enOprationType OT)
		{
			switch (OT)
			{
			case enOprationType::eAdd:
				return number1 + number2;
			case enOprationType::eSubtract:
				return number1 - number2;
			case enOprationType::eMultiply:
				return number1 * number2;
			case enOprationType::eDivide:
				return number1 / number2;
			default:
				return number1 + number2;
			}
		}
		
		static enPrimeNumber CheckPrime(int number)
		{
			int m = round(number / 2);
			for (int i = 2;i <= m;i++)
			{
				if (number % i == 0)
				{
					return enPrimeNumber::eNotPrime;
				}

			}
			return enPrimeNumber::ePrime;
		}
		
		static void PrintMultiplicationTable()
		{
			PrintHead();
			for (int i = 1; i <= 10; i++)
			{
				cout << " " << i << ColumSperator(i) << "\t";
				for (int j = 0; j <= 10; j++)
				{
					cout << i * j << "\t";
				}
				cout << endl;
			}
		}
		
		static void PrintPrimeNumber(int number)
		{
			cout << "\n" << "prime numbers from 1 to " << number << " are : " << endl;
			for (int i = 1; i <= number; i++)
			{
				if (CheckPrime(i) == enPrimeNumber::ePrime)
					cout << i << endl;
			}
		}
		
		static enIsPerfect CheckPerfectNumber(int number)
		{
			int sum = 0, count = round(number / 2);
			for (size_t i = 1; i <= count; i++)
			{
				if (number % i == 0)
					sum += i;
			}
			if (sum == number)
				return enIsPerfect::ePerfect;
			else
				return enIsPerfect::eNotPerfect;
		}
		
		static void PrintallperfectNumbers(int number)
		{
			cout << "\n" << "perfect numbers from 1 to " << number << " are : " << endl;
			for (int i = 1; i <= number; i++)
			{
				if (CheckPerfectNumber(i) == enIsPerfect::ePerfect)
					cout << i << endl;
			}
		}
		
		
		
		static int ReverseNumber(int number)
		{
			int remainder = 0, reverse = 0;
			while (number > 0)
			{
				remainder = number % 10;
				number = number / 10;
				reverse = reverse * 10 + remainder;
			}
			return reverse;
		}
		
		static int SumDigits(int number)
		{
			int sum = 0, remainder = 0;
			while (number > 0)
			{
				remainder = number % 10;
				sum += remainder;
				number /= 10;
			}
			return sum;
		}
		
		static int CheckDigit(int number, short digit)
		{
			int remainder = 0, count = 0;
			while (number > 0)
			{
				remainder = number % 10;
				number /= 10;
				if (remainder == digit)
				{
					count++;
				}

			}
			return count;
		}
		
		static void PrintAllDigitsFrequancy(int number)
		{
			cout << endl;
			for (int i = 0;i < 10;i++)
			{
				short digitfrequency = 0;
				digitfrequency = CheckDigit(number, i);
				if (digitfrequency > 0)
				{
					cout << "digit " << i << " frequency is " << digitfrequency << " times.\n";
				}
			}
		}
		
		static void PrintDigits(int reverse)
		{
			int remainder = 0;
			while (reverse > 0)
			{
				remainder = reverse % 10;
				reverse = reverse / 10;
				cout << remainder << endl;
			}
		}
		
		static bool IsPalindrome(int number)
		{
			return number == ReverseNumber(number);
		}	
		
		static string Encryption(string text, short kay)
		{
			string encrypted_text = "";
			for (int i = 0;i < text.size();i++)
			{
				int temp = (int)text[i];

				if (temp == 90 || temp == 122 || temp == 89 || temp == 121)
					temp -= (26 - kay);
				else
					temp += kay;
				encrypted_text += (char)temp;
			}
			return encrypted_text;
		}
		
		static string Decryption(string encripted_text, short kay)
		{
			string decrypted_text = "";
			for (int i = 0;i < encripted_text.size();i++)
			{
				int temp = (int)encripted_text[i];

				if (temp == 66 || temp == 98 || temp == 65 || temp == 97)
					temp += (26 - 2);
				else
					temp -= kay;
				decrypted_text += (char)temp;
			}
			return decrypted_text;
		}
		
		static int RandomNumber(int from, int to)
		{
			int randnum = rand() % (to - from + 1) + from;
			return randnum;
		}	
		
		static char GetRandomChar(enCharType chartype)
		{
			switch (chartype)
			{
			case SmallLetter:
				return char(RandomNumber(97, 122));
				break;
			case CapitalLetter:
				return char(RandomNumber(65, 90));
				break;
			case SpecialChracter:
				return char(RandomNumber(33, 47));
				break;
			case Digit:
				return char(RandomNumber(48, 57));
				break;
			}
		}
		
		static string GenerateWord(enCharType chartype, short length)
		{

			string word = "";
			while (length > 0)
			{
				word += GetRandomChar(chartype);
				length--;
			}
			return word;
		}
		
		static string GenerateKay()
		{
			string kay = "";
			for (int i = 1;i <= 4;i++)
			{
				kay += GenerateWord(enCharType::CapitalLetter, 4);
				if (i == 4)
					break;
				else
					kay += "-";
			}
			return kay;
		}
		
		static void GenerateKays(int number_kays)
		{
			for (int i = 1;i < number_kays;i++)
			{
				cout << "kay [" << i << "] : ";
				cout << GenerateKay() << endl;
			}
		}
		
		static void PrimeNumberInArray(int array[100], int arraysize, int primenumbers[100], int& primecount)
		{

			for (size_t i = 0; i < arraysize; i++)
			{
				if (CheckPrime(array[i]) == enPrimeNumber::ePrime)
				{
					primenumbers[primecount] = array[i];
					primecount++;
				}
			}
		}
		
		static void FillArrayWith1ToN(int array[100], int arraysize)
		{
			for (size_t i = 0; i < arraysize; i++)
			{
				array[i] = i + 1;
			}
		}
	    
		static void swap(int& a, int& b)
		{
			int temp = a;
			a = b;
			b = temp;

		}
		
		static void shufflearray(int array[100], int arraysize)
		{
			for (size_t i = 0; i < arraysize; i++)
			{
				swap(array[RandomNumber(1, arraysize - 1)], array[RandomNumber(1, arraysize - 1)]);
			}
		}
		
		static void ReverseCopyArray(int array[100], int arraysize, int array2[100])
		{

			for (int i = 0; i < arraysize; i++)
			{
				array2[i] = array[arraysize - 1 - i];
			}
		}
		
		static void ArrayKays(string array[100], int arraysize)
		{
			for (int i = 0;i < arraysize;i++)
			{
				array[i] = GenerateKay();
			}
		}
		
		static int GetNumber(int array[100], int arraysize, int number_search)
		{

			for (size_t i = 0; i < arraysize; i++)
			{
				if (array[i] == number_search)
					return  i + 1;

			}
			return 0;
		}
		
		static bool IsFound(int array[100], int arraysize, int number_search)
		{
			return GetNumber(array, arraysize, number_search) != -1;
		}
		
		static void  NumberToArray(int array[100], int& array2size, int number)
		{
			array[array2size] = number;
			array2size++;
		}
		
		static void ArrayUnikeNumber(int array[10], int arraysize, int newarray[10], int& newarraysize)
		{
			for (size_t i = 0; i < arraysize; i++)
			{
				if (!IsFound(newarray, newarraysize, array[i]))
				{
					NumberToArray(newarray, newarraysize, array[i]);
				}



			}
		}
		
		static int CalcEvenNumbers(int array[100], int arraysize)
		{
			int evencount = 0;
			for (size_t i = 0; i < arraysize; i++)
			{
				if (array[i] % 2 == 0)
					evencount++;
			}
			return evencount;
		}
		
		static int CalcPositiveNumbers(int array[100], int arraysize)
		{
			int positivecount = 0;
			for (size_t i = 0; i < arraysize; i++)
			{
				if (array[i] >= 0)
					positivecount++;
			}
			return positivecount;
		}

		static string Tabs(short NumberOfTabs)
		{
			string t = "";
			for (int i = 0; i < NumberOfTabs; i++)
			{
				t += "\t";
			}
			return t;
		}


		static string NumberToTxt(long long number)
		{
			if (number == 0)
			{
				return "";
			}
			if (number >= 1 && number <= 19)
			{
				string NumbersFrom0To19[] = { "","one","two","three","four","five","six","seven","eight","nine","ten","eleven" "twelve",
				"thirteen","fourteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };

				return NumbersFrom0To19[number] + " ";
			}
			if (number >= 20 && number <= 99)
			{
				string BigNumbers[] = { "","","twanty" ,"thirty","fourty","fifty","sixty","seventy","eighty","ninty" };
				return BigNumbers[number / 10] + " " + NumberToTxt(number % 10);
			}
			if (number >= 100 && number <= 199)
			{
				return "One Hunderd " + NumberToTxt(number % 100);
			}
			if (number >= 200 && number <= 999)
			{
				return NumberToTxt(number / 100) + "hundred " + NumberToTxt(number % 100);
			}
			if (number >= 1000 && number <= 1999)
			{
				return "One thaousand" + NumberToTxt(number % 1000);
			}
			if (number >= 2000 && number <= 999999)
			{
				return NumberToTxt(number / 1000) + "thousand " + NumberToTxt(number % 1000);
			}
			if (number >= 1000000 && number <= 1999999)
			{
				return "One Million " + NumberToTxt(number % 1000000);
			}
			if (number >= 2000000 && number <= 999999999)
			{
				return NumberToTxt(number / 1000000) + "Million " + NumberToTxt(number % 1000000);
			}
			if (number >= 1000000000 && number <= 1999999999)
			{
				return " One Billion " + NumberToTxt(number % 1000000000);
			}
			else
			{
				return NumberToTxt(number / 1000000000) + "Billion " + NumberToTxt(number % 1000000000);
			}
		}

	};
