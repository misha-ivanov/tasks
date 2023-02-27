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

void ostring(const char* string);
const char* mi_strcat(const char* destination, const char* source, const char* result);

struct test{
	const char* str1;
	const char* str2;
	const char* result;
};

using namespace std;

int main()
{
	test strcat_test[] = {{"test", "" , "test"}, {"one", "two", "onetwo"}, {"", "", ""}};
	int N = sizeof(strcat_test) / sizeof(strcat_test[0]);
	const char* str_final;
	for (int i = 0; i < N; i++)
	{
		cout << "Test " << i;
		str_final = mi_strcat(strcat_test[i].str1, strcat_test[i].str2, strcat_test[i].result);
		ostring(strcat_test[i].result);
		ostring(str_final);
		cout << endl;
	}
	return 0;
}


void ostring(const char* str)
{
	cout << str;
}

const char* mi_strcat(const char* destination, const char* source, const char* result)
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