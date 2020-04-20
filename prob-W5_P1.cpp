#include <iostream>
#include <algorithm>

using namespace std;

int T;

bool IsAlpha(char c)
{
	if (c < 65 || c > 122 || (c > 90 && c < 97))
		return false;

	return true;
}

bool IsSame(char c1, char c2)
{
	if (c1 == c2 || abs(c1 - c2) == 32)
		return true;

	return false;
}

string IsPal(string s)
{
	int leftIdx = -1, rightIdx = s.length();
	string ret = "Yes\n";

	while (true)
	{
		leftIdx++; rightIdx--;

		while (!IsAlpha(s[leftIdx]))
			leftIdx++;

		while (!IsAlpha(s[rightIdx]))
			rightIdx--;

		if (leftIdx >= rightIdx)
			break;

		if (!IsSame(s[leftIdx], s[rightIdx]))
		{
			ret = "No\n";
			break;
		}
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;

		cout << IsPal(s);
	}

	return 0;
}