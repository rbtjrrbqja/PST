#include <iostream>
#include <memory.h>

using namespace std;

int T, N, table[10001], visit[10001], finish[10001], cnt;

void func(int node)
{
	visit[node] = 1;
	int nextNode = table[node];

	if (visit[nextNode] == 0)
		func(nextNode);
	else if (finish[nextNode] == 0)
	{
		while (nextNode != node)
		{
			cnt++;
			nextNode = table[nextNode];
		}

		cnt++;
	}

	finish[node] = 1;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		memset(visit, 0, sizeof(visit));
		memset(finish, 0, sizeof(finish));
		cnt = 0;

		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> table[i];

		for (int i = 1; i <= N; i++)
			if(visit[i] == 0)
				func(i);

		cout << N - cnt << "\n";
	}

	return 0;
}