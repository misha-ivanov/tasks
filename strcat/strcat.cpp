/* 
 * The mi_strcat() function contcatenates(joins) two strings. Personal limit: 5 letters
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

const int N = 3; // quantity of tests

char* istring();

void ostring(char* string);

char* mi_strcat(char* destination, const char* source, const char* result);

struct Test {
	char str[2][N][5];
	char result[N][10];
};

using namespace std;

int main()
{
	Test test = { {{"test", "" , NULL}, {"one", "two", NULL}}, {"testone", "two", NULL}};
	//char* str_a;
	//char* str_b;
	char* str_final;
	//str_a = istring();
	//str_b = istring();
	for (int i = 0; i < N; i++)
	{
		cout << "Test " << i;
		str_final = mi_strcat(test.str[0][i], test.str[1][i], test.result[i]);
		ostring(test.result[i]);
		ostring(str_final);
	}
	return 0;
}


/*char* istring()
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
}*/

void ostring(char* str)
{
	cout << str;
}

char* mi_strcat(char* destination, const char* source, const char* result)
{
	if ((destination == NULL) || (source == NULL))
	{
		return destination;
	}
		int length = 0, counter = 0, f = 0;
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

		while ((destination[counter] != '\0')&&(f == 0)) //filling the word
		{
			str[counter] = destination[counter];
			if(str[counter] != result[counter])
			{
				cout << ": failed" << endl;
				f = 1;
			}
			counter++;
		}
		length = counter;
		counter = 0;
		while ((source[counter] != '\0')&&(f == 0))
		{
			str[length + counter] = source[counter];
			if (str[length + counter] != result[length + counter])
			{
				cout << ": failed" << endl;
				f = 1;
			}
			counter++;
		}
		if(f == 0)
			cout << ": success" << endl;
		return str;
}