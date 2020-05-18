#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, K;

struct Obj
{
	int weight;
	int value;
	int vPw;
};

bool cmp(const Obj &o1, const Obj &o2)
{
	return o1.vPw > o2.vPw;
}

int main()
{
	cin >> T;
	std::ios::sync_with_stdio(false);

	while (T--)
	{
		cin >> N >> K;

		vector<Obj> info(N, Obj{ 0, 0, 0 });

		for (int i = 0; i < N; i++)
			cin >> info[i].weight;

		for (int i = 0; i < N; i++)
		{
			cin >> info[i].value;
			info[i].vPw = int(info[i].value / info[i].weight);
		}

		sort(info.begin(), info.end(), cmp);

		int total = 0;

		for (int i = 0; i < N; i++)
		{
			if (info[i].weight <= K)
			{
				total += info[i].value;
				K -= info[i].weight;
			}
			else
			{
				total += K * info[i].vPw;
				break;
			}
		}

		cout << total << endl;
	}

	return 0;
}