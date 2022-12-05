#include "istring.h"
#include <iostream>

using namespace std;

char* istring() 
{
	int length;
	char* tmp_str;
	cout << "Enter a length of string:" << endl;
	cin >> length;
	tmp_str = new char[length+1];
	cout << "Enter a string:" << endl;
	for (int i = 0; i < length; i++)
		cin >> tmp_str[i];
	tmp_str[length] = '\0';
	return tmp_str;
}