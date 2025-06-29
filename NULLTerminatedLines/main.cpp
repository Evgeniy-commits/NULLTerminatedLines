#include<iostream>
#include<Windows.h>
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
bool isIPaddress(const char str[]);


//#define BASIC_STRING_OPERATIONS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASIC_STRING_OPERATIONS
	const int SIZE = 100;
	//char str[SIZE] = {};
	char str[] = "��������� ����� �����";
	cout << "������� ������: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << StringLenghth(str) << endl;
	cout << ToUpper(str) << endl;
	//cout << ToLower(str) << endl;
	cout << Shrink(str) << endl;
	cout << "������ " << (isPalindrom(str) ? "" : "�� ") << "�������� �����������" << endl;
	cout << "������ " << (isIntNumber(str) ? "" : "�� ") << "�������� ������" << endl;
	cout << str << " * 2 = " << toIntNumber(str) * 2 << endl;
#endif // BASIC_STRING_OPERATIONS

	const int SIZE = 65;
	char str[SIZE] = {};
	//cout << "������� �������� �����: ";
	cin.getline(str, SIZE);
	//cout << "������ " << (isBinNumber(str) ? "" : "�� ") << "�������� �������� ������" << endl;
	//cout << bin2dec(str) << endl;
	//cout << "������ " << (isHexNumber(str) ? "" : "�� ") << "�������� ����������������� ������" << endl;
	//cout << hex2dec(str) << endl;
	cout << "������ " << (isIPaddress(str) ? "" : "�� ") << "�������� IP-�������" << endl;
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
		if (str[i] >= '�' && str[i] <= '�') str[i] -= ' ';*/
		str[i] = toupper(str[i]);
	}
	return str;
}

char* ToLower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'A' && str[i] <= 'Z') str[i] += ' ';
		if (str[i] >= '�' && str[i] <= '�') str[i] += ' ';*/
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

bool isIPaddress(const char str[])
{
	int n = strlen(str);
	if (n < 7 || n > 15) return false;
	char bytes[4][4] = {};
	for (int i = 0, j = 0, k = 0; str[i]; i++)
	{
		if (str[i] == '.')
		{
			j++;
			if (j > 3) return false;
			k = 0;
			continue;
		}
		bytes[j][k++] = str[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (toIntNumber(bytes[i]) > 255) return false;
		cout << bytes[i] << "\t";
	}
	cout << endl;
	return true;
}