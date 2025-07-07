#include<iostream>
#include<Windows.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

int StringLenghth(const char str[]);
char* ToUpper(char str[]);
char* ToLower(char str[]);
char* Shrink(char str[]);
bool isPalindrom(const char str[]);
bool isIntNumber(const char str[]);
int toIntNumber(const char str[]);
bool isBinNumber(const char str[]);
bool isHexNumber(const char str[]);
unsigned long long bin2dec(const char str[]);
unsigned long long hex2dec(const char str[]);
bool isIPaddress(char str[]);
bool isMACaddress(char str[]);

//#define BASIC_STRING_OPERATIONS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASIC_STRING_OPERATIONS
	const int SIZE = 100;
	//char str[SIZE] = {};
	char str[] = "Аргентина манит негра";
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << StringLenghth(str) << endl;
	cout << ToUpper(str) << endl;
	//cout << ToLower(str) << endl;
	cout << Shrink(str) << endl;
	cout << "Строка " << (isPalindrom(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	cout << "Строка " << (isIntNumber(str) ? "" : "НЕ ") << "является числом" << endl;
	cout << str << " * 2 = " << toIntNumber(str) * 2 << endl;
#endif // BASIC_STRING_OPERATIONS

	const int SIZE = 65;
	char str[SIZE] = {};
	cout << "Введите ip - адрес: ";
	cin.getline(str, SIZE);
	//cout << "Строка " << (isBinNumber(str) ? "" : "НЕ ") << "является двоичным числом" << endl;
	//cout << bin2dec(str) << endl;
	//cout << "Строка " << (isHexNumber(str) ? "" : "НЕ ") << "является шестнадцатиричным числом" << endl;
	//cout << hex2dec(str) << endl;
	//00:AB:CD:EF:11:22
	//cout << "Строка " << (isIPaddress(str) ? "" : "НЕ ") << "является IP-адресом" << endl;
	cout << "Строка " << (isMACaddress(str) ? "" : "НЕ ") << "является MAC-адресом" << endl;
}

int StringLenghth(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

char* ToUpper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z') str[i] -= ' ';
		if (str[i] >= 'а' && str[i] <= 'я') str[i] -= ' ';*/
		str[i] = toupper(str[i]);
	}
	return str;
}

char* ToLower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'A' && str[i] <= 'Z') str[i] += ' ';
		if (str[i] >= 'А' && str[i] <= 'Я') str[i] += ' ';*/
		str[i] = tolower(str[i]);
	}
	return str;
}

char* Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++) str[j] = str[j + 1];
		}
	}
	return str;
}
char* RemoveSymbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
	return str;
}
bool isPalindrom(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	for (int i = 0; str[i]; i++) buffer[i] = str[i];
	ToUpper(buffer);
	n = strlen(RemoveSymbol(buffer, ' '));
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool isIntNumber(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') continue;
		if (str[i] < '0' || str[i] > '9') return false;
	}
	return true;
}

int toIntNumber(const char str[])
{
	if (!isIntNumber(str)) return INT_MIN;
	int number = 0;
	for (int i = 0; str[i]; i++)
	{
		number = number * 10 + str[i] - '0';
	}
	return number;
}

bool isBinNumber(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1') return false;
	}
	return true;
}

bool isHexNumber(const char str[])
{
	for (int i = str[0] == '0' && str[1] == 'x' ? 2 : 0; str[i]; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'F') && (str[i] < 'a' || str[i] > 'f'))
			return false;
	}
	return true;
}

unsigned long long bin2dec(const char str[])
{
	if (!isBinNumber(str)) return ULLONG_MAX;
	unsigned long long int decimal = 0;
	for (int i = 0; str[i]; i++)
	{
		decimal = decimal * 2 + str[i] - '0';
	}
	return decimal;
}

unsigned long long hex2dec(const char str[])
{
	if (!isHexNumber(str)) return ULLONG_MAX;
	unsigned long long int decimal = 0;
	for (int i = str[0] == '0' && str[1] == 'x' ? 2 : 0; str[i]; i++)
	{
		char hex_digit = str[i];
		if (hex_digit >= '0' && hex_digit <= '9') hex_digit -= '0';
		if (hex_digit >= 'A' && hex_digit <= 'F') (hex_digit -= 'A') += 10;
		if (hex_digit >= 'a' && hex_digit <= 'f') (hex_digit -= 'a') += 10;
		decimal = decimal * 16 + hex_digit;
	}
	return decimal;
}

//bool isIPaddress(const char str[])
//{
//	int n = strlen(str);
//	if (n < 7 || n > 15) return false;
//	char bytes[4][4] = {};
//	for (int i = 0, j = 0, k = 0; str[i]; i++)
//	{
//		if (str[i] == '.')
//		{
//			j++;
//			if (j > 3) return false;
//			k = 0;
//			continue;
//		}
//		bytes[j][k++] = str[i];
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		if (toIntNumber(bytes[i]) > 255) return false;
//		cout << bytes[i] << "\t";
//	}
//	cout << endl;
//	return true;
//}

//bool isIPaddress(const char str[])
//{
//	int n = strlen(str);
//	if (n < 7 || n > 15) return false;
//	char byte[4] = {};
//	for (int i = 0, j = 0, points = 0; str[i]; i++)
//	{
//		if (str[i] == '.')
//		{
//			j = 0;
//			points++;
//			if (points > 3) return false;
//			if (toIntNumber(byte) > 255) return false;
//			continue;
//		}
//		byte[j++] = str[i];
//		if (j > 3) return false;
//	}
//	return true;
//}
//
bool isIPaddress(char str[])
{
	int n = strlen(str);
	if (n < 7 || n > 15) return false;
	char* context = NULL;
	char* token = strtok_s(str, ".", &context);;
		for (int count = 1; token != NULL; count++)
	{
		return (toIntNumber(token) > 255 ? false : strlen(token) > 3 ? false : true);
		token = strtok_s(NULL, ".", &context);
	}
	return true;
}


bool isMACaddress(char str[])
{
	int n = strlen(str);
	if (n != 17) return false;
	char* context = NULL;
	char* token = strtok_s(str, ":", &context);
	for (int count = 1; token != NULL; count++)
	{
		return (!isHexNumber(token) ? false : strlen(token) > 2 ? false : true);
		token = strtok_s(NULL, ":", &context);
	}
	return true;
}



