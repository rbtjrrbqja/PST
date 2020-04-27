#include <iostream>

using namespace std;

string A;
int B, T;

int func()
{
	int len = A.length(), ret = A[0] - '0';

	for (int i = 1; i < len; i++)
		ret = (10 * ret + A[i] - '0') % B;

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		if (func() != 0)
			cout << "0\n";
		else
			cout << "1\n";
	}

	return 0;
}