/*
 * The caps_string() function convert capital letters to lower case and conversly
 *
 * Example:
 * Input: "Score 2:0"
 * Output: "sCORE 2:0"
 */

#include <iostream>
using namespace std;

const int N = 4;
struct test {
	const char* str;
	const char* result;
};

char* caps_string(const char* data_str, const char* result_str);

int main(){
	test test_str[] = { { "Abs", "aBS"}, {"He`ll-~o", "hE`LL-~O"}, {"",""}, {"a40 5", "A40 5"}};
	for (int i = 0; i < N; i++)
	{
		cout << endl << "Test #" << i+1 << ": ";
		cout << caps_string(test_str[i].str, test_str[i].result);
	}
	return 0;
}



char* caps_string(const char* data_str, const char* result_str) 
{
	int i = 0, f = 0;
	while (data_str[i] != '\0')
		i++;
	char* tmp_str = new char[i];
	for(int tmp = 0; tmp < i; tmp++)
	{
		if (((int)data_str[tmp] >= int('a')) && ((int)data_str[tmp] <= int('z')))
			tmp_str[tmp] = char(int(data_str[tmp]) - abs(int('A') - int('a')));
		else
			if (((int)data_str[tmp] >= int('A')) && ((int)data_str[tmp] <= int('Z')))
				tmp_str[tmp] = char(int(data_str[tmp]) + abs(int('A') - int('a')));
			else
				tmp_str[tmp] = data_str[tmp];
		if (tmp_str[tmp] != result_str[tmp])
			f = 1;
	}
	if (f == 0)
		cout << " success" << endl << "Result:";
	else
		cout << " failed" << endl << "Result: ";
	return tmp_str;
};