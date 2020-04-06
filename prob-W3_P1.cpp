#include <iostream>

using namespace std;

int T, N, stick[10001];

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> N;

		int count = 0, target = N;

		for (int i = 1; i <= N; i++) {
			cin >> stick[i];
		}

		while (target != 0)
		{
			for (int i = 1; i <= N; i++)
			{
				if (stick[i] == target)
				{
					stick[i] = -1;
					target--;
				}
			}

			count++;
		}

		cout << count << "\n";
	}

	return 0;
}