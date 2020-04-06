#include <iostream>

using namespace std;

int T, N, num, disk[10001];

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> N;

		int count = 0, target = N;

		for (int i = 1; i <= N; i++)
		{
			cin >> num;
			disk[num] = i;
		}

		for (int i = N; i > 0; i--)
		{
			if (disk[target] > disk[target - 1])
				count++;

			target--;
		}

		cout << count << "\n";
	}

	return 0;
}