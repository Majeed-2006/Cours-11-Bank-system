#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

	class clsString
	{
		enum enWhaToCount { Smallletters = 1, capitalletters = 2, all = 3 };
		struct sClient
		{
			string AccountNumber;
			string PinCode;
			string Name;
			string Phone;
			double AccountBalance;
		};
		string _Value;


		short CountLetters(string txt, enWhaToCount WhatToCount = enWhaToCount::all)
		{
			if (WhatToCount == all)
				return txt.length();
			short Count = 0;
			for (size_t i = 0; i < txt.size(); i++)
			{
				if (WhatToCount == capitalletters && isupper(txt[i]))
					Count++;

				else if (WhatToCount == Smallletters && islower(txt[i]))
					Count++;
			}
			return Count;
		}
	public:
		clsString()
		{

		}

		clsString(string Value)
		{
			_Value = Value;
		}

		void SetValue(string Value)
		{
			_Value = Value;
		}
		string GetValue()
		{
			return _Value;;
		}

		_declspec(property(get = GetValue, put = SetValue))string Value;



		static short CountWords(string S1)
		{
			string delim = " "; // delimiter
			short Counter = 0;
			short pos = 0;
			string sWord; // define a string variable

			// use find() function to get the position of the delimiters
			while ((pos = S1.find(delim)) != std::string::npos)
			{
				sWord = S1.substr(0, pos); // store the word
				if (sWord != "")
				{
					Counter++;
				}

				// erase() until position and move to next word
				S1.erase(0, pos + delim.length());
			}

			if (S1 != "")
			{
				Counter++; // it counts the last word of the string
			}

			return Counter;
		}

		short CountWords()
		{
			return CountWords(_Value);
		}



		static short Length(string S1)
		{
			return S1.length();
		}

		short Length()
		{
			return Length(_Value);

		}



		static string FirstLetterToLower(string S1)
		{
			bool isFirstLetter = true;
			for (short i = 0; i < S1.length(); i++)
			{
				if (S1[i] != ' ' && isFirstLetter)
					S1[i] = tolower(S1[i]);
				isFirstLetter = (S1[i] == ' ' ? true : false);
			}
			return S1;
		}

		void FirstLetterToLower()
		{
			_Value = FirstLetterToLower(_Value);
		}



		static string FirstLetterToUpper(string txt)
		{

			bool IsfirstLetter = true;
			for (short i = 0; i < txt.size(); i++)
			{
				if (isalpha(txt[i]) && IsfirstLetter)
				{
					txt[i] = toupper(txt[i]);
				}
				IsfirstLetter = (!isalpha(txt[i]) ? true : false);
			}
			return txt;
		}

		void FirstLetterToUpper()
		{
			FirstLetterToUpper(_Value);
		}



		static string AllLettersToLower(string txt)
		{
			for (short i = 0;i < txt.length();i++)
			{
				txt[i] = tolower(txt[i]);
			}
			return txt;
		}

		string AllLettersToLower()
		{
			return AllLettersToLower(_Value);
		}



		static string AllLettersToUpper(string S1)
		{
			for (short i = 0; i < S1.length(); i++)
				S1[i] = toupper(S1[i]);
			return S1;
		}

		void  AllLettersToUpper()
		{
			_Value = AllLettersToUpper(_Value);
		}



		static char InvertLetter(char letter)
		{
			return isupper(letter) ? tolower(letter) : toupper(letter);

		}



		static string InvertString(string txt)
		{
			for (size_t i = 0; i < txt.size(); i++)
			{

				txt[i] = InvertLetter(txt[i]);
			}
			return txt;
		}

		string InvertString()
		{
			return InvertString(_Value);
		}



		static short CountLetters(string txt, short Number = 3)
		{
			clsString String1(txt);
			return String1.CountLetters(txt, enWhaToCount(Number));
		}

		short CountLetters(short Number = 3)
		{
			return CountLetters(_Value, Number);
		}



		static string ConvertRecordToLine(sClient client, string seperator = "#//#")
		{
			string line;
			line += client.AccountNumber + seperator;
			line += client.PinCode + seperator;
			line += client.Name + seperator;
			line += client.Phone + seperator;
			line += to_string(client.AccountBalance);
			return line;
		}




		static short CountLetterInString(string txt, char letter)
		{
			short count = 0;
			for (size_t i = 0; i < txt.length(); i++)
			{
				if (txt[i] == letter)
					count++;
			}
			return count;
		}

		short CountLetterInString(char Letter)
		{
			return CountLetterInString(_Value, Letter);
		}



		static bool IsVowel(char Letter)
		{
			Letter = tolower(Letter);
			return(Letter == 'a' || Letter == 'e' || Letter == 'o' || Letter == 'i' || Letter == 'u');
		}



		static short CountVowels(string txt)
		{
			short count = 0;
			for (size_t i = 0; i < txt.length(); i++)
			{
				if (IsVowel(txt[i]))
					count++;
			}
			return count;
		}

		short CountVowels()
		{
			return CountVowels(_Value);
		}



		static void PrintVowelString(string txt)
		{
			cout << "\nVowels in string are : ";
			string VowelText = "";
			for (size_t i = 0; i < txt.length(); i++)
			{
				if (IsVowel(txt[i]))
					cout << txt[i] << "  ";

			}

		}

		void PrintVowelString()
		{
			PrintVowelString(_Value);

		}



		static void PrintWords(string txt)
		{
			string delim = " ";
			cout << "\nyour string words are : \n\n";
			string word;
			short pos = 0;
			while ((pos = txt.find(delim)) != std::string::npos)
			{
				word = txt.substr(0, pos);
				if (word != "")
				{
					cout << word << endl;
				}
				txt.erase(0, pos + delim.length());
			}
			if (txt != "")
				cout << txt << endl;
		}

		void PrintWords()
		{
			PrintWords(_Value);
		}



		static string TrimLeft(string txt)
		{
			for (short i = 0; i < txt.size(); i++)
			{
				if (txt[i] != ' ')
					return txt.substr(i, txt.length() - i);
			}
			return " ";
		}

		string Trimleft()
		{
			return TrimLeft(_Value);
		}



		static string TrimRight(string txt)
		{
			short end = txt.size() - 1;
			for (short i = end; i >= 0; i--)
			{
				if (txt[i] != ' ')
					return txt.substr(0, i + 1);

			}
			return" ";
		}

		string TrimRight()
		{
			return TrimRight(_Value);
		}



		static short CountCapitalLetters(string S1)
		{
			short Counter = 0;
			for (short i = 0; i < S1.length(); i++)
				if (isupper(S1[i]))
					Counter++;
			return Counter;
		}

		short CountCapitalLetters()
		{
			return CountCapitalLetters(_Value);
		}



		static short CountSmallLetters(string S1)
		{
			short Counter = 0;
			for (short i = 0; i < S1.length(); i++)
				if (islower(S1[i]))
					Counter++;
			return Counter;
		}

		short CountSmallLetters()
		{
			return CountSmallLetters(_Value);
		}



		static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
		{
			short Counter = 0;
			for (short i = 0; i < S1.length(); i++)
			{
				if ((MatchCase && S1[i] == Letter) || (!MatchCase && tolower(S1[i]) == tolower(Letter)))
					Counter++;
			}
			return Counter;
		}

		short CountSpecificLetter(char Letter, bool MatchCase = true)
		{
			return CountSpecificLetter(_Value, Letter, MatchCase);
		}



		static string Trim(string txt)
		{

			return TrimRight(TrimLeft(txt));
		}

		string Trim()
		{

			return Trim(_Value);
		}


		static string JoinString(vector<string> vTxt, string Delim)
		{
			string txt = "";
			for (string s : vTxt)
			{
				txt += s + Delim;
			}
			return txt.substr(0, txt.length() - Delim.length());
		}


		static string ReversString(string txt, string Delim)
		{
			string ReversTxt = "";
			vector<string> vTxt = Split(txt, " ");
			vector<string>::iterator iter = vTxt.end();
			while (iter != vTxt.begin())
			{
				iter--;
				ReversTxt += *iter + " ";
			}
			ReversTxt = ReversTxt.substr(0, ReversTxt.length() - 1);
			return ReversTxt;
		}

		string ReversString(string Delim)
		{
			return ReversString(_Value, Delim);
		}


		static string ReplacString(string s1, string StringToReplace, string StringReplaceTo)
		{
			short pos = s1.find(StringToReplace);
			while (pos != std::string::npos)
			{
				s1 = s1.replace(pos, StringToReplace.length(), StringReplaceTo);
				pos = s1.find(StringToReplace);

			}
			return s1;
		}

		string ReplacString(string Word, string NewWord)
		{
			return ReplacString(_Value, Word, NewWord);
		}


		static vector<string> Split(string S1, string Delim)
		{

			vector<string> vString;

			short pos = 0;
			string sWord; // define a string variable  

			// use find() function to get the position of the delimiters  
			while ((pos = S1.find(Delim)) != std::string::npos)
			{
				sWord = S1.substr(0, pos); // store the word   
				// if (sWord != "")
				// {
				vString.push_back(sWord);
				//}

				S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
			}

			if (S1 != "")
			{
				vString.push_back(S1); // it adds last word of the string.
			}

			return vString;
		}

		vector<string> Split(string Delim)
		{
			return Split(_Value, Delim);
		}



		static sClient ConvertLineToRecord(string line, string seperator = "#//#")
		{
			vector<string>vClientline = Split(line, "#//#");
			sClient client;
			client.AccountNumber = vClientline[0];
			client.PinCode = vClientline[1];
			client.Name = vClientline[2];
			client.Phone = vClientline[3];
			client.AccountBalance = stod(vClientline[4]);
			return client;
		}

		sClient ConvertLineToRecord(string Seperator)
		{
			return ConvertLineToRecord(_Value, Seperator);
		}



		static void PrintFirstLetter(string txt)
		{

			bool IsfirstLetter = true;
			for (short i = 0; i < txt.size(); i++)
			{
				if (isalpha(txt[i]) && IsfirstLetter)
				{
					cout << txt[i];
					break;
				}
				IsfirstLetter = (!isalpha(txt[i]) ? true : false);
			}
		}

		void PrintFirstLetter()
		{
			PrintFirstLetter(_Value);
		}



		static string RemovePunctuation(string txt)
		{
			string NewTxt = "";
			for (short i = 0;i < txt.length();i++)
			{
				if (!ispunct(txt[i]))
					NewTxt += txt[i];
			}
			return NewTxt;
		}

		string RemovePunctuation()
		{
			return  RemovePunctuation(_Value);
		}


	};

