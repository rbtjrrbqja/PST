#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int T, B;
string A;

string IntToString(int i)
{
	string ret = "";

	while (i > 0)
	{
		ret += i % 10 + '0';
		i /= 10;
	}

	int len = ret.length();

	for (int i = 0; i < len / 2; i++)
	{
		char tmp = ret[i];
		ret[i] = ret[len - i - 1];
		ret[len - i - 1] = tmp;
	}

	return ret;
}

int func()
{
	int len = A.length();

	while (len >= 6)
	{
		int numA = atoi(A.substr(0, 6).c_str());

		string back = A.substr(6);
		string newFront = IntToString(numA % B);

		A = newFront + back;
		len = A.length();
	}

	int numA = atoi(A.c_str());

	if ((numA % B) == 0)
		return 1;

	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> A >> B;
		cout << func() << endl;
	}

	return 0;
}