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

int main()
{
	int data, result = 0;
	cout << "Enter the number" << endl;
	cin >> data;
	while (data != 0)
	{
		result = 10 * result + data % 10;
		data = int(data / 10);
	}
	cout << "Inverted number is: " << result;
	return 0;
}