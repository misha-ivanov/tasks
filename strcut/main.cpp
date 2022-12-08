/* 
 * The mi_strcat() function contcatenates(joins) two strings
 * 
 * [size of the first element(adress)], [size of the second element(adress)]
 * "abcdef" - [a][b][c][d][e][f][\0]
 * 
 * Example:
 * Input: "Aloha", " world"
 * Output: "Aloha world"
 * 
 */

#include <iostream>

char* istring();

void ostring(char* string);

char* mi_strcat(char* destination, const char* source);

using namespace std;

int main()
{
	char* str_a;
	char* str_b;
	char* str_final;
	str_a = istring();
	str_b = istring();
	str_final = mi_strcat(str_a, str_b);
	ostring(str_final);

	return 0;
}


char* istring()
{
	int length;
	char* tmp_str;
	cout << "Enter a length of string:" << endl;
	cin >> length;
	tmp_str = new char[length + 1];
	cout << "Enter a string:" << endl;
	for (int i = 0; i < length; i++)
		cin >> tmp_str[i];
	tmp_str[length] = '\0';
	return tmp_str;
}

void ostring(char* str)
{
	cout << str;
}

char* mi_strcat(char* destination, const char* source)
{
	if ((destination == NULL) || (source == NULL))
	{
		return destination;
	}
		int length = 0, counter = 0;
		while (destination[counter] != '\0')
			counter++;
		length = counter;
		counter = 0;
		while (source[counter] != '\0')
			counter++;
		counter++;
		length = length + counter; //memory of word in byte (including '\0')
		counter = 0;

		char* str = new char[length]; //creating the word
		str[length - 1] = '\0';

		while (destination[counter] != '\0') //filling the word
		{
			str[counter] = destination[counter];
			counter++;
		}
		length = counter;
		counter = 0;
		while (source[counter] != '\0')
		{
			str[length + counter] = source[counter];
			counter++;
		}
		return str;
}