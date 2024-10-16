#include <iostream>
#include <string>
using namespace std;

enum enHeader { Register = 1 , currency_converter = 2};

enum enCurrencies { USD = 1, JOD = 2, EUR = 3, EGP = 4, YEN = 5, FF = 6 };

// User Address: city, country, steetname.
struct stAddress
{
	string city;
	string country;
	string StreetName;
};

// User Information: name, age, income, phone, address.
struct stInfo
{
	string FirstName;
	string LastName;
	short age;
	string phone;
	stAddress address;
	int YearlyIncome;
	int BankValue = 7500;
};

// Clear the console from text
void Clear()
{
	system("cls");
}

int ReadPositiveNumber(string message, int From, int To)
{
	int num;
	cout << message << endl;
	cin >> num;

	while (num < From || num > To)
	{
		cout << "Wrong number it should be between " << From << " and " << " To " << To << endl;
		cout << message << endl;
		cin >> num;
	}
	return num;
}

bool Login()
{
	int password;
	int counter = 3;
	Clear();
	do
	{
		password = ReadPositiveNumber("Please, Enter the password:", 1000, 9999);

		if (password == 1234)
			return 1;
		else
		{
			system("color CF");
			counter--;
			cout << "you have " << counter << " chances\n" << endl;
		}

	} while (password != 1234 && counter >= 1);
	
	return 0;
}

stInfo ReadInfo()
{
	stInfo Info;
	cout << "-------------------------------\n";

	cout << "Enter your first name: ";
	cin >> Info.FirstName;
	cout << "Enter your last name: ";
	cin >> Info.LastName;
	cout << "Enter your age: ";
	cin >> Info.age;
	cout << "Enter your phone number: ";
	cin >> Info.phone;
	cout << "Enter your country name: ";
	cin >> Info.address.country;
	cout << "Enter your city name: ";
	cin >> Info.address.city;
	cout << "Enter your street name: ";
	cin >> Info.address.StreetName;
	cout << "Enter your yearly income: ";
	cin >> Info.YearlyIncome;

	cout << "\n-------------------------------\n";
	
	return Info;

}

void PrintInfo( bool login)
{
	if (login)
	{
		system("color 2F");
		stInfo Info = ReadInfo();
		cout << "-------------------------------\n";

		cout << "Name: " << Info.FirstName << ' ' << Info.LastName << endl;
		cout << "Age: " << Info.age << endl;
		cout << "Phone: " << Info.phone << endl;
		cout << "Country: " << Info.address.country << endl;
		cout << "City: " << Info.address.city << endl;
		cout << "Street name: " << Info.address.StreetName << endl;
		cout << "Income: " << Info.YearlyIncome << endl;
		cout << "Bank Balance: " << Info.BankValue << endl;

		cout << "\n-------------------------------\n";
	}
	else
	{
		system("color 4F");
		cout << "The bank card is locked!!" << endl;
	}

}

// let the user choose what currency he want to change it to what currency and enter the amount of money.
void CurrencyConverter()
{		
	float Money;    // How much money he want to convert it
	int ChoiceFrom;// The currency he want convert it
	int ChoiceTo; // The currency he want convert to

	cout << " (1) USD\t (2) JOD\t (3) EUR\n (4) EGP\t (5) YEN\t (6) FF" << endl;
	cout << "\nEnter the currency's number you want to convert it: \n";
	cin >> ChoiceFrom;
	while (ChoiceFrom > 6 || ChoiceFrom < 1)
	{
		cout << "\nWrong Number your choice should be between 1 and 6, try again: \n";
		cin >> ChoiceFrom;
		Clear();
	cout << " (1) USD\t (2) JOD\t (3) EUR\n (4) EGP\t (5) YEN\t (6) FF" << endl;

	}
	cout << "Enter the currency's number you want to convert to: \n";
	cin >> ChoiceTo;
	while (ChoiceTo > 6 || ChoiceTo < 1)
	{
		cout << "\nWrong Number your choice should be between 1 and 6, try again: \n";
		cin >> ChoiceTo;
		Clear();
	cout << " (1) USD\t (2) JOD\t (3) EUR\n (4) EGP\t (5) YEN\t (6) FF" << endl;

	}
	cout << "Enter how much money you want to convert it: \n";
	cin >> Money;
	while (Money < 0)
	{
		cout << "\nYou Should enter a positive value or 0: \n";
		cin >> Money;
		Clear();
	cout << " (1) USD\t (2) JOD\t (3) EUR\n (4) EGP\t (5) YEN\t (6) FF" << endl;
	}

	float MoneyEntered = Money;

	float JOD = 0.71;
	float EUR = 0.89;
	float EGP = 48.45;
	float YEN = 143.93;	
	float FF = 215.70;

	if (ChoiceTo == enCurrencies::USD) // I don't do it with nested switch because i think it will be harder to read as a programmer
	{
		switch (ChoiceFrom)
		{
		case enCurrencies::USD: 
			cout << "It is the same Currency" << endl;
			break;
		case enCurrencies::JOD:
			Money = Money * (1 / JOD);
			cout << MoneyEntered << " JOD is = " << Money << " USD " << endl;
			break;
		case enCurrencies::EUR:
			Money = Money * (1 / EUR);
			cout << MoneyEntered << " EUR is = " << Money << " USD " << endl;
			break;
		case enCurrencies::EGP:
			Money = Money * (1 / EGP);
			cout << MoneyEntered << " EGP is = " << Money << " USD " << endl;
			break;
		case enCurrencies::YEN:
			Money = Money * (1 / YEN);
			cout << MoneyEntered << " YEN is = " << Money << " USD " << endl;
			break;
		case enCurrencies::FF:
			Money = Money * (1 / FF);
			cout << MoneyEntered << " FF is = " << Money << " USD " << endl;
			break;
		}
	}
	else if (ChoiceTo == enCurrencies::JOD)
	{
		switch (ChoiceFrom)
		{
		case enCurrencies::USD:
			Money = Money * JOD;
			cout << MoneyEntered << " USD is = " << Money << " JOD " << endl;
			break;
		case enCurrencies::JOD:
			cout << "It is the same Currency." << endl;
			break;
		case enCurrencies::EUR:
			Money = Money * (1 / EUR) * JOD;
			cout << MoneyEntered << " EUR is = " << Money << " JOD " << endl;
			break;
		case enCurrencies::EGP:
			Money = Money * (1 / EGP) * JOD;
			cout << MoneyEntered << " EGP is = " << Money << " JOD " << endl;
			break;
		case enCurrencies::YEN:
			Money = Money * (1 / YEN) * JOD;
			cout << MoneyEntered << " YEN is = " << Money << " JOD " << endl;
			break;
		case enCurrencies::FF:
			Money = Money * (1 / FF) * JOD;
			cout << MoneyEntered << " FF is = " << Money << " JOD " << endl;
			break;
		}
	}
	else if (ChoiceTo == enCurrencies::EUR)
	{
		switch (ChoiceFrom)
		{
		case enCurrencies::USD:
			Money = Money * EUR;
			cout << MoneyEntered << " USD is = " << Money << " EUR " << endl;
			break;
		case enCurrencies::JOD:
			Money = Money * (1 / JOD) * EUR;
			cout << MoneyEntered << " JOD is = " << Money << " EUR " << endl;
			break;
		case enCurrencies::EUR:
			cout << "It is the same Currency." << endl;
			break;
		case enCurrencies::EGP:
			Money = Money * (1 / EGP) * EUR;
			cout << MoneyEntered << " EGP is = " << Money << " EUR " << endl;
			break;
		case enCurrencies::YEN:
			Money = Money * (1 / YEN) * EUR;
			cout << MoneyEntered << " YEN is = " << Money << " EUR " << endl;
			break;
		case enCurrencies::FF:
			Money = Money * (1 / FF) * EUR;
			cout << MoneyEntered << " FF is = " << Money << " EUR " << endl;
			break;
		}
	}
	else if (ChoiceTo == 4)
	{
		switch (ChoiceFrom)
		{
		case enCurrencies::USD:
			Money = Money * EGP;
			cout << MoneyEntered << " USD is = " << Money << " EGP " << endl;
			break;
		case enCurrencies::JOD:
			Money = Money * (1 / JOD) * EGP;
			cout << MoneyEntered << " JOD is = " << Money << " EGP " << endl;
			break;
		case 3:
			Money = Money * (1 / EUR) * EGP;
			cout << MoneyEntered << " EUR is = " << Money << " EGP " << endl;
			break;
		case enCurrencies::EGP:
			cout << "It is the same Currency." << endl;
			break;
		case enCurrencies::YEN:
			Money = Money * (1 / YEN) * EGP;
			cout << MoneyEntered << " YEN is = " << Money << " EGP " << endl;
			break;
		case enCurrencies::FF:
			Money = Money * (1 / FF) * EGP;
			cout << MoneyEntered << " FF is = " << Money << " EGP " << endl;
			break;
		}
	}
	else if (ChoiceTo == 5)
	{
		switch (ChoiceFrom)
		{
		case enCurrencies::USD:
			Money = Money * YEN;
			cout << MoneyEntered << " USD is = " << Money << " YEN " << endl;
			break;
		case enCurrencies::JOD:
			Money = Money * (1 / JOD) * YEN;
			cout << MoneyEntered << " JOD is = " << Money << " YEN " << endl;
			break;
		case 3:
			Money = Money * (1 / EUR) * YEN;
			cout << MoneyEntered << " EUR is = " << Money << " YEN " << endl;
			break;
		case 4:
			Money = Money * (1 / EGP) * YEN;
			cout << MoneyEntered << " EGP is = " << Money << " YEN " << endl;
			break;
		case 5:
			cout << "It is the same Currency." << endl;
			break;
		case 6:
			Money = Money * (1 / FF) * YEN;
			cout << MoneyEntered << " FF is = " << Money << " YEN " << endl;
			break;
		}
	}
	else if (ChoiceTo == 6)
	{
		switch (ChoiceFrom)
		{
		case enCurrencies::USD:
			Money = Money * FF;
			cout << MoneyEntered << " USD is = " << Money << " FF " << endl;
			break;
		case enCurrencies::JOD:
			Money = Money * (1 / JOD) * FF;
			cout << MoneyEntered << " JOD is = " << Money << " FF " << endl;
			break;
		case 3:
			Money = Money * (1 / EUR) * FF;
			cout << MoneyEntered << " EUR is = " << Money << " FF " << endl;
			break;
		case 4:
			Money = Money * (1 / EGP) * FF;
			cout << MoneyEntered << " EGP is = " << Money << " FF " << endl;
			break;
		case 5:
			Money = Money * (1 / YEN) * FF;
			cout << MoneyEntered << " YEN is = " << Money << " FF " << endl;
			break;
		case 6:
			cout << "It is the same Currency." << endl;
			break;
		}
	}

}

// Show the user the services and the let him choose one and do it.
void HeaderControl()
{
	cout << "\n --------------------------------\n";

	cout << " (1) Register\n";
	cout << " (2) Currency Converter" << endl;

	cout << "\n --------------------------------" << endl;

	cout << "\n Enter the service's number: ";

	int Choice;
	cin >> Choice;

	while (Choice <= 0 || Choice > 3)
	{
		cout << " Wrong number, Try again: " << endl;
		cin >> Choice;
	}
	switch (Choice)
	{
		case enHeader::Register:
			PrintInfo(Login());
			break;
		case enHeader::currency_converter:
			CurrencyConverter();
			break;	
		default:
			cout << "hi, if you see this you may have a problem or me i guess, hahahahha!!!" << endl;
	}
}

int main()
{	

	HeaderControl();

	return 0;
}
