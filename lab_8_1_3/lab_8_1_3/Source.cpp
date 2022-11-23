#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s, const char c)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, c))
	{
		pos = t - s + 1;
		k++;
	}
	return k;
}

int Count2(char* s, const char d)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, d))
	{
		pos = t - s + 1;
		k++;
	}
	return k;
}

int Count3(char* s, const char f)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, f))
	{
		pos = t - s + 1;
		k++;
	}
	return k;
}

char* Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1, '+'))
	{
		if (s[p - s + 1] == '+')
		{
			pos2 = p - s + 2;
			strncat(t, s + pos1, pos2 - pos1 - 2);
			strcat(t, "***");
			pos1 = pos2;
		}
	}

	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}

char* Change1(char* dest)
{
	char* t = new char[strlen(dest)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(dest + pos1, '-'))
	{
		if (dest[p - dest + 1] == '-')
		{
			pos2 = p - dest + 2;
			strncat(t, dest + pos1, pos2 - pos1 - 2);
			strcat(t, "***");
			pos1 = pos2;
		}
	}

	strcat(t, dest + pos1);
	strcpy(dest, t);
	return t;
}

char* Change2(char* dest1)
{
	char* t = new char[strlen(dest1)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(dest1 + pos1, '='))
	{
		if (dest1[p - dest1 + 1] == '=')
		{
			pos2 = p - dest1 + 2;
			strncat(t, dest1 + pos1, pos2 - pos1 - 2);
			strcat(t, "***");
			pos1 = pos2;
		}
	}

	strcat(t, dest1 + pos1);
	strcpy(dest1, t);
	return t;
}

int main()
{
	char str[101];
	char c = '+';
	char d = '-';
	char f = '=';

	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contains " << Count(str, c) << " symbols '+'" << endl;
	cout << "String contains " << Count2(str, d) << " symbols '-'" << endl;
	cout << "String contains " << Count3(str, f) << " symbols '='" << endl;

	char* dest = new char[151];
	dest = Change(str);
	char* dest1 = new char[151];
	dest1 = Change1(dest);
	char* dest2 = new char[151];
	dest2 = Change2(dest1);
	cout << "Modified string: " << dest2 << endl;

	return 0;
}