#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int T;
string s1, s2;

int func(int idx1, int idx2)
{
	if (idx1 >= s1.length() || idx2 >= s2.length())
		return 0;

	int ret = 0;

	for (int i = idx1; i < s1.length(); i++)
	{
		char cur = s1[i];
		int cnt = idx2;

		while (cnt < s2.length() && cur != s2[cnt])
			cnt++;

		if (cnt >= s2.length())
			continue;

		ret = max(ret, func(i + 1, cnt + 1) + 1);
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> s1 >> s2;
		cout << func(0, 0) << endl;
	}

	return 0;
}