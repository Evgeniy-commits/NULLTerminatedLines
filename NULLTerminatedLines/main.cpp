#include<iostream>
#include<Windows.h>
using namespace std;

int StringLenghth(const char str[]);
char* ToUpper(char str[]);
char* ToLower(char str[]);
char* Shrink(char str[]);
bool isPalindrom(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 100;
	//char str[SIZE] = {};
	char str[] = "Аргентина манит негра";
	/*cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);*/
	cout << str << endl;
	cout << StringLenghth(str) << endl;
	cout << ToUpper(str) << endl;
	//cout << ToLower(str) << endl;
	cout << Shrink(str) << endl;
	cout << "Строка " << (isPalindrom(str) ? "" : "НЕ ") << "является палиндромом" << endl;


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