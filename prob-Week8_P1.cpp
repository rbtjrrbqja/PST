#include <iostream>

using namespace std;

int T, M, N;
int score[101], slot[102];
// 1 - 100        0 / 1 - 100 / 101
int func()
{
	int sum = 0, combo = 1;

	for (int i = 2; i <= M + 1; i++)
	{
		if (slot[i - 1] < slot[i])
			combo++;
		else
		{
			sum += score[combo];
			combo = 1;
		}
	}

	return sum;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> M >> N;

		for (int i = 1; i <= M; i++)
			cin >> score[i];

		int num, slotNum;

		for (int i = 1; i <= M; i++)
		{
			cin >> num >> slotNum;
			slot[slotNum] = num;
		}

		cout << func() << endl;
	}

	return 0;
}