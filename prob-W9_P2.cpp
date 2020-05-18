#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int T, N, K;
int weight[501];
int value[501];
int cache[501][100001];

int func()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j - weight[i] >= 0)
				cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - weight[i]] + value[i]);
			else
				cache[i][j] = cache[i - 1][j];
		}
	}

	return cache[N][K];
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		memset(cache, 0, sizeof(cache));

		cin >> N >> K;

		for (int i = 1; i <= N; i++)
			cin >> weight[i];

		for (int i = 1; i <= N; i++)
			cin >> value[i];

		cout << func() << endl;
	}

	return 0;
}