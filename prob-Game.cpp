#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef pair<int, int> Pair;

string itemName;
int T, n, startTime, endTime, cache[10001];
vector<Pair> timeTable;
vector<Pair> tmpArr;

// compare function for vector<Pair> sort
bool cmp(Pair a, Pair b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
}

int func(int index)
{
	// out of range
	if (index >= n)
		return 0;

	int& ret = cache[index];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = index; i < timeTable.size(); i++)
	{
		if (tmpArr.empty() || tmpArr.back().second <= timeTable[i].first)
		{
			tmpArr.push_back(timeTable[i]);
			ret = max(ret, func(i + 1) + 1);
			tmpArr.pop_back();
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
		cin >> n;

		// cache, vectors initialization
		memset(cache, -1, sizeof(cache));
		timeTable.clear();
		tmpArr.clear();

		// input data
		for (int i = 0; i < n; i++)
		{
			cin >> itemName >> startTime >> endTime;
			timeTable.push_back(Pair{startTime, endTime});
		}

		sort(timeTable.begin(), timeTable.end(), cmp);
		cout << func(0) << endl;
	}

	return 0;
}