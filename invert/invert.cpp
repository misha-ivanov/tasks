/*
 * The invert_int() function contcatenates(joins) an int
 *
 *
 * Example:
 * Input: 76008
 * Output: 80067
 *
 */

#include <iostream>

using namespace std;

const int N = 3;

struct Test {
	int input[N];
	int result[N];
}; 

int main()
{
	Test test = 
		{ 
		{0, 102, 100},
		{0, 201, 1} 
		};
	int data, result;
	for (int i = 0; i < N; i++)
	{
		data = test.input[i];
		result = 0;
		while (data != 0)
		{
			result = 10 * result + data % 10;
			data = int(data / 10);
		}
		if (result == test.result[i])
			cout << "Test " << i << ": success" << endl;
		else
			cout << "Test " << i << ": failed" << endl;
	}
	return 0;
}