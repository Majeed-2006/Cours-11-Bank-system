#pragma once
#pragma warning(disable : 4996)
#include "clsString.h"
#include <ctime>
	class clsDate
	{

		short _Day;
		short _Month;
		short _Year;



	public:

		enum enDateCompare { Befor = 1, Equal = 2, After = 3 };

		clsDate()
		{
			time_t t = time(0);
			tm* now = localtime(&t);
			_Day = now->tm_mday;
			_Month = now->tm_mon + 1;
			_Year = now->tm_year + 1900;
		}

		clsDate(string Date)
		{
			clsString String1;
			String1.SetValue(Date);
			vector<string> vDate = String1.Split("/");
			_Day = (short)stoi(vDate[0]);
			_Month = (short)stoi(vDate[1]);
			_Year = (short)stoi(vDate[2]);
		}

		clsDate(short Day, short Month, short Year)
		{
			_Day = Day;
			_Month = Month;
			_Year = Year;
		}

		clsDate(short Days, short Year)
		{
			clsDate Date;
			Date.Day = 0;
			Date.Month = 1;
			Date.Year = Year;
			AddToDate(Date, Days);
			_Day = Date.Day;
			_Month = Date.Month;
			_Year = Year;
		}



		void SetDay(short Day)
		{
			_Day = Day;
		}

		short GetDay()
		{
			return _Day;

		}

		_declspec(property(get = GetDay, put = SetDay))short  Day;



		void SetMonth(short Month)
		{
			_Month = Month;
		}

		short GetMonth()
		{
			return _Month;

		}

		_declspec(property(get = GetMonth, put = SetMonth))short Month;



		static clsDate ReadDate()
		{
			clsDate date;
			date.Day = ReadDay();
			date.Month = ReadMonth();
			date.Year = ReadYear();
			return date;
		}



		void SetYear(short Year)
		{
			_Year = Year;
		}

		short GetYear()
		{
			return _Year;

		}

		_declspec(property(get = GetYear, put = SetYear))short  Year;



		void Print()
		{
			cout << DateToString(*this) << endl;
		}



		static short ReadYear()
		{
			cout << "Enter a Year : ";
			short number;
			cin >> number;
			return number;
		}



		static clsDate GetSystemDate(clsDate Date)
		{
			time_t  t = time(0);
			tm* now = localtime(&t);
			short Day, Month, Year;
			Year = now->tm_year + 1900;
			Month = now->tm_mon + 1;
			Day = now->tm_mday;
			return clsDate(Day, Month, Year);

		}



		static string DateToString(clsDate Date)
		{
			return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
		}

		string DateToString()
		{
			return DateToString(*this);
		}



		static bool IsLeapYear(short Year)
		{
			return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
		}

		bool IsLeapYear()
		{
			return IsLeapYear(_Year);
		}



		static short NumberOfDaysInYear(short Year)
		{
			return IsLeapYear(Year) ? 366 : 365;
		}

		short NumberOfDaysInYear()
		{
			return NumberOfDaysInYear(_Year);
		}



		static short NumberOfHoursInYear(short Year)
		{
			return NumberOfDaysInYear(Year) * 24;
		}

		short NumberOfHoursInYear()
		{
			return  NumberOfHoursInYear(_Year);
		}



		static int NumberOfMinutesInYear(short Year)
		{
			return NumberOfHoursInYear(Year) * 60;
		}

		int NumberOfMinutesInYear()
		{
			return NumberOfMinutesInYear(_Year);
		}


		static int NumberOfSecondsInYear(short Year)
		{
			return NumberOfMinutesInYear(Year) * 60;
		}

		int NumberOfSecondsInYear()
		{
			return NumberOfSecondsInYear(_Year);
		}


		static short ReadMonth()
		{
			short Month;
			cout << "enter a month to check :";
			cin >> Month;
			return Month;
		}



		static short NumberOfDaysInMonth(short Year, short Month)
		{
			if (Month < 1 || Month> 12)
				return 0;

			short ArrDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
			return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : ArrDays[Month];
		}

		short NumberOfDaysInMonth()
		{
			return NumberOfDaysInMonth(_Year, _Month);
		}



		static short NumberOfHoursInMonth(short Year, short Month)
		{
			return NumberOfDaysInMonth(Year, Month) * 24;
		}

		short NumberOfHoursInMonth()
		{
			return NumberOfHoursInMonth(_Year, _Month);
		}



		static int NumberOfMinutesInMonth(short Year, short Month)
		{
			return NumberOfHoursInMonth(Year, Month) * 60;
		}

		int NumberOfMinutesInMonth()
		{
			return NumberOfMinutesInMonth(_Year, _Month);
		}



		static int NumberOfSecondsInMonth(short Year, short Month)
		{
			return NumberOfMinutesInMonth(Year, Month) * 60;
		}

		int NumberOfSecondsInMonth()
		{
			return NumberOfSecondsInMonth(_Year, _Month);

		}



		static short ReadDay()
		{
			short Day;
			cout << "enter a Day to check :";
			cin >> Day;
			return Day;
		}



		static short DayOfWeekOrder(short Year, short Month, short Day)
		{
			short a = (14 - Month) / 12;
			short y = Year - a;
			short m = Month + 12 * a - 2;
			return  (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
		}

		static short DayOfWeekOrder(clsDate Date)
		{
			short a = (14 - Date.Month) / 12;
			short y = Date.Year - a;
			short m = Date.Month + 12 * a - 2;
			return  (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
		}

		short DayOfWeekOrder()
		{

			return  DayOfWeekOrder(*this);
		}



		static string DayName(short DayOrder)
		{

			string DaysName[8] = { "Sun","Mon","Tue","wed","Thu","Fri","Sat" };
			return DaysName[DayOrder];
		}



		static string MonthName(short Month)
		{
			string MonthesName[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
			return MonthesName[Month];
		}

		string MonthName()
		{
			return MonthName(_Month);
		}



		static void PrintMonthCalendar(short Year, short Month)
		{
			short NumberOfDays = NumberOfDaysInMonth(Year, Month), Day = DayOfWeekOrder(Year, Month, 1);
			printf("\n-------------------%s-------------------\n\n", MonthName(Month).c_str());
			printf("  Sun  Mon  Tue  wed  Thu  Fri  Sat\n");
			short i = 0;
			for (;i < Day;i++)
			{
				printf("     ");
			}
			for (short j = 1;j <= NumberOfDays;j++)
			{
				printf("%5d", j);
				if (++i == 7)
				{
					i = 0;
					printf("\n");
				}
			}
			printf("\n\n-----------------------------------------");
		}

		void PrintMonthCalendar()
		{
			PrintMonthCalendar(_Year, _Month);
		}



		static void PrintYearCalendar(short Year)
		{
			printf("\n\n------------------------------------------------\n\n");
			printf("                   Calendar - %d\n", Year);
			printf("\n------------------------------------------------\n");

			for (short Month = 1;Month <= 12;Month++)
			{
				PrintMonthCalendar(Year, Month);
			}
		}

		void PrintYearCalendar()
		{
			PrintYearCalendar(_Year);
		}



		static short NumberOfDaysFromTheBeginingOfYear(clsDate Date)
		{
			short NumberOfDaysFromBegining = 0;
			for (short i = 1;i <= Date.Month - 1;i++)
			{
				NumberOfDaysFromBegining += NumberOfDaysInMonth(Date.Year, i);

			}
			NumberOfDaysFromBegining += Date.Day;
			return NumberOfDaysFromBegining;
		}

		short NumberOfDaysFromTheBeginingOfYear()
		{

			return NumberOfDaysFromTheBeginingOfYear(*this);
		}



		static clsDate AddToDate(clsDate& Date, short NumberOfDays)
		{
			short MonthDays, ReminingDays = NumberOfDaysFromTheBeginingOfYear(Date) + NumberOfDays;
			Date.Month = 1;
			while (true)
			{
				MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
				MonthDays;

				if (MonthDays < ReminingDays)
				{
					ReminingDays -= MonthDays;
					Date.Month++;
					if (Date.Month > 12)
					{
						Date.Month = 1;
						Date.Year++;
					}
				}
				else
				{
					Date.Day = ReminingDays;
					break;
				}


			}
			return Date;
		}

		void AddToDate(short NumberOfDays)
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			Date = AddToDate(Date, NumberOfDays);
			_Day = Date.Day;
			_Month = Date.Month;
			_Year = Date.Year;
		}



		static bool IsDate1BeforDate2(clsDate Date1, clsDate Date2)
		{
			return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
		}



		static bool IsDatesEqual(clsDate Date1, clsDate Date2)
		{
			return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
		}



		static bool IsLastDay(clsDate Date)
		{
			return NumberOfDaysInMonth(Date.Year, Date.Month) == Date.Day;
		}

		bool IsLastDay()
		{

			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;

			return IsLastDay(Date);
		}



		static bool IsLastMonth(short Month)
		{
			return Month == 12;
		}

		bool IsLastMonth()
		{
			return IsLastMonth(_Month);
		}



		static clsDate AddOneDay(clsDate Date)
		{
			if (IsLastDay(Date))
			{
				if (IsLastMonth(Date.Month))
				{
					Date.Day = 1;
					Date.Month = 1;
					Date.Year++;
				}
				else
				{
					Date.Day = 1;
					Date.Month++;
				}
			}
			else
			{
				Date.Day++;
			}
			return Date;
		}

		void AddOneDay()
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			Date = AddOneDay(Date);
			_Day = Date.Day;
			_Month = Date.Month;
			_Year = Date.Year;
		}



		static short DiffBetweenDates(clsDate Date1, clsDate Date2)
		{
			short NumberOfDaysInDate1 = NumberOfDaysFromTheBeginingOfYear(Date1);
			short NumberOfDaysInDate2 = NumberOfDaysFromTheBeginingOfYear(Date2);
			return NumberOfDaysInDate2 - NumberOfDaysInDate1;
		}



		static void SwapDates(clsDate& Date1, clsDate& Date2)
		{
			clsDate TempDate;
			TempDate = Date1;
			Date1 = Date2;
			Date2 = TempDate;
		}



		static string FormatDate(clsDate Date, string Format = "dd/mm/yyyy")
		{
			string Line = Format;
			Line = clsString::ReplacString(Line, "dd", to_string(Date.Day));
			Line = clsString::ReplacString(Line, "mm", to_string(Date.Month));
			Line = clsString::ReplacString(Line, "yyyy", to_string(Date.Year));

			return Line;
		}

		string FormatDate(string Format = "dd/mm/yyyy")
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			return FormatDate(Date, Format);
		}



		static bool IsValidDate(clsDate Date)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Year, Date.Month))
				return false;
			if (Date.Month > 12 || Date.Month < 1)
				return false;
			return true;
		}

		bool IsValidDate()
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			return IsValidDate(Date);
		}



		static bool IsBusinessDay(clsDate Date)
		{

			return !IsWeekend(Date);
		}

		bool IsBusinessDay()
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			return IsBusinessDay(Date);
		}



		static clsDate CalcEndDate(clsDate Date, short VacationDays)
		{

			while (VacationDays > 0)
			{
				if (IsBusinessDay(Date))
				{
					VacationDays--;

				}
				Date = AddOneDay(Date);
			}
			return Date;
		}

		void CalcEndDate(short VacationDays)
		{

			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			Date = CalcEndDate(Date, VacationDays);
			_Day = Date.Day;
			_Month = Date.Month;
			_Year = Date.Year;
		}



		static clsDate AddXDays(short x, clsDate& Date)
		{
			for (short i = 0;i < x;i++)
			{
				Date = AddOneDay(Date);
			}
			return Date;
		}

		void AddXDays(short x)
		{
			AddXDays(x, *this);
		}



		static clsDate AddOneWeek(clsDate& Date)
		{
			for (short i = 0;i < 7;i++)
			{
				Date = AddOneDay(Date);
			}
			return Date;
		}

		void AddOneWeek()
		{
			AddOneWeek(*this);
		}



		static clsDate AddXWeeks(short x, clsDate& Date)
		{
			for (short i = 0;i < x;i++)
			{
				Date = AddOneWeek(Date);
			}
			return Date;
		}

		void AddXWeeks(short x)
		{
			AddXWeeks(x, *this);
		}



		static clsDate AddOneMonth(clsDate& Date)
		{
			if (Date.Month == 12)
			{
				Date.Year++;
				Date.Month = 1;
			}
			else
			{
				Date.Month++;
			}
			short DaysNumber = NumberOfDaysInMonth(Date.Year, Date.Month);
			if (Date.Day > DaysNumber)
				Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);

			return Date;
		}

		void AddOneMonth()
		{

			AddOneMonth(*this);

		}



		static clsDate AddXMonths(short x, clsDate& Date)
		{
			for (short i = 0;i < x;i++)
			{
				Date = AddOneMonth(Date);
			}
			return Date;
		}

		void AddXMonths(short x)
		{
			AddXMonths(x, *this);
		}



		static clsDate AddOneYear(clsDate& Date)
		{
			Date.Year++;
			return Date;
		}

		void AddOneYear()
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			Date = AddOneYear(Date);
			_Day = Date.Day;
			_Month = Date.Month;
			_Year = Date.Year;
		}



		static clsDate AddXYears(short x, clsDate& Date)
		{
			Date.Year += x;
			return Date;
		}

		void AddXYears(short x)
		{

			AddXYears(x, *this);
		}



		static clsDate AddOneDecade(clsDate& Date)
		{
			Date = AddXYears(10, Date);
			return Date;
		}

		void AddOneDecade()
		{

			AddOneDecade(*this);
		}



		static clsDate AddXDecades(short x, clsDate& Date)
		{
			Date.Year += 10 * x;
			return Date;
		}

		void addXDecades(short x)
		{

			AddXDecades(x, *this);

		}



		static clsDate AddOneCentury(clsDate& Date)
		{
			Date.Year += 100;
			return Date;
		}

		void AddOneCentury()
		{

			AddOneCentury(*this);

		}



		static clsDate AddOneMillennium(clsDate& Date)
		{
			Date.Year += 1000;
			return Date;
		}

		void AddOneMillennium()
		{

			AddOneMillennium(*this);

		}



		static bool IsFirstDay(short Day)
		{
			return Day == 1;
		}

		bool IsFirstDay()
		{
			return IsFirstDay(_Day);
		}



		static bool IsFirstMonth(short Month)
		{
			return Month == 1;
		}

		bool IsFirstMonth()
		{

			return IsFirstMonth(_Month);
		}



		static clsDate SubOneDay(clsDate& Date)
		{
			if (IsFirstDay(Date.Day))
			{
				if (IsFirstMonth(Date.Month))
				{
					Date.Year--;
					Date.Month = 12;
					Date.Day = 31;
				}
				else
				{
					Date.Month--;
					Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
				}
			}
			else
			{
				Date.Day--;
			}
			return Date;
		}

		void SubOneDay()
		{

			SubOneDay(*this);

		}



		static clsDate SubXDays(short x, clsDate& Date)
		{
			for (short i = 0;i < x;i++)
			{
				Date = SubOneDay(Date);
			}
			return Date;
		}

		void SubXDays(short x)
		{

			SubXDays(x, *this);

		}



		static clsDate SubOneWeek(clsDate& Date)
		{
			for (short i = 0;i < 7;i++)
			{
				Date = SubOneDay(Date);
			}
			return Date;
		}

		void SubOneWeek()
		{
			SubOneWeek(*this);

		}



		static clsDate SubXWeeks(short x, clsDate& Date)
		{
			for (short i = 0;i < x;i++)
			{
				Date = SubOneWeek(Date);
			}
			return Date;
		}

		void SubXWeeks(short x)
		{

			SubXWeeks(x, *this);
		}



		static 	clsDate SubOneMonth(clsDate& Date)
		{
			if (IsFirstMonth(Date.Month))
			{
				Date.Year--;
				Date.Month = 12;
			}
			else
			{
				Date.Month--;
			}
			short DaysNumber = NumberOfDaysInMonth(Date.Year, Date.Month);
			if (Date.Day > DaysNumber)
				Date.Day = DaysNumber;
			return Date;
		}

		void SubOneMonth()
		{
			SubOneMonth(*this);

		}



		static clsDate SubXMonths(short x, clsDate& Date)
		{
			for (short i = 0; i < x; i++)
			{
				Date = SubOneMonth(Date);
			}
			return Date;
		}

		void SubXMonths(short x)
		{
			SubXMonths(x, *this);

		}



		static clsDate SubOneYear(clsDate& Date)
		{
			Date.Year--;
			return Date;
		}

		void SubOneYear()
		{

			SubOneYear(*this);

		}



		static clsDate SubXYears(short x, clsDate& Date)
		{
			Date.Year -= x;
			return Date;
		}

		void SubXYears(short x)
		{
			SubXYears(x, *this);
		}



		static clsDate SubOneDecade(clsDate& Date)
		{
			Date.Year -= 10;
			return Date;
		}

		void SubOneDecade()
		{
			SubOneDecade(*this);

		}



		static clsDate SubXDecades(short x, clsDate& Date)
		{
			Date.Year -= 10 * x;
			return Date;
		}

		void SubXDecades(short x)
		{

			SubXDecades(x, *this);

		}



		static clsDate SubOneCentury(clsDate& Date)
		{
			Date.Year -= 100;
			return Date;
		}

		void SubOneCentury()
		{

			SubOneCentury(*this);

		}



		static clsDate SubOneMillennium(clsDate& Date)
		{
			Date.Year -= 1000;
			return Date;
		}

		void SubOneMillennium()
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			Date = SubOneMillennium(Date);
			_Day = Date.Day;
			_Month = Date.Month;
			_Year = Date.Year;
		}



		static short DaysUntilEndOfWeek(clsDate Date)
		{
			return 6 - DayOfWeekOrder(Date);
		}

		short DaysUntilEndOfWeek()
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			return DaysUntilEndOfWeek(Date);
		}



		static short DaysUntilEndOfMonth(clsDate Date)
		{
			return NumberOfDaysInMonth(Date.Year, Date.Month) - Date.Day;;
		}

		short DaysUntilEndOfMonth()
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			return DaysUntilEndOfMonth(Date);
		}



		static short DaysUntilEndOfYear(clsDate Date)
		{
			short  NumberOfDays = NumberOfDaysFromTheBeginingOfYear(Date);
			return IsLeapYear(Date.Year) ? 366 - NumberOfDays : 365 - NumberOfDays;


		}

		short DaysUntilEndOfYear()
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			return DaysUntilEndOfYear(Date);
		}



		static short CalcVacationDays(clsDate Date1, clsDate Date2)
		{
			short VacationDays = 0, DiffYears;
			while (IsDate1BeforDate2(Date1, Date2))
			{
				if (IsBusinessDay(Date1))
				{
					VacationDays++;
				}
				Date1 = AddOneDay(Date1);
			}
			return VacationDays;
		}

		short CalcVacationDays(clsDate Date2)
		{
			return CalcVacationDays(*this, Date2);
		}



		static bool IsWeekend(clsDate Date)
		{
			short DayOrder = DayOfWeekOrder(Date);
			return DayOrder == 5 || DayOrder == 6;
		}

		bool Isweekend()
		{
			clsDate Date;
			Date.Day = _Day;
			Date.Month = _Month;
			Date.Year = _Year;
			return IsWeekend(Date);
		}



		static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
		{
			if (IsDate1BeforDate2(Date1, Date2))
				return enDateCompare::Befor;
			if (IsDatesEqual(Date1, Date2))
				return enDateCompare::Equal;

			return enDateCompare::After;
		}

		enDateCompare CompareDates(clsDate Date2)
		{
			return CompareDates(*this, Date2);

		}



		static short CalcBusinessDays(clsDate Date1, clsDate Date2)
		{
			return CalcVacationDays(Date1, Date2);
		}

		short CalcBusinessDays(clsDate Date2)
		{
			return CalcBusinessDays(*this, Date2);
		}



		static int GetDiffInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
		{
			int Days = 0;
			while (IsDate1BeforDate2(Date1, Date2))
			{
				Days++;
				Date1 = AddOneDay(Date1);
			}
			return IncludeEndDay ? ++Days : Days;
		}

		int GetDiffInDays(clsDate Date2, bool IncludeEndDay = false)
		{
			return GetDiffInDays(*this, Date2, IncludeEndDay);
		}


		static short CalcMyAgeInDays(clsDate DateOfBirth)
		{
			return GetDiffInDays(DateOfBirth, clsDate::GetSystemDate(DateOfBirth), true);
		}

		short CalcMyAgeInDays()
		{
			return CalcMyAgeInDays(*this);
		}











	};

