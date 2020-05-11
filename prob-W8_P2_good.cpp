#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int T, cache[1001][1001];
string s1, s2;

int func()
{
	int len1 = s1.length();
	int len2 = s2.length();

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i] == s2[j])
				cache[i][j] = cache[i - 1][j - 1] + 1;
			else
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
		}
	}

	return cache[len1][len2];
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		memset(cache, 0, sizeof(cache));
		cin >> s1 >> s2;
		cout << func() << endl;
	}

	return 0;
}