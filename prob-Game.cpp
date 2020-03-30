#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef pair<int, int> Pair;

string itemName;
int T, n, startTime, endTime;
vector<Pair> timeTable;
vector<Pair> tmpArr;

// compare function for vector<Pair> sort
bool cmp(Pair a, Pair b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int func()
{
	for (int i = 0; i < n; i++)
		if (tmpArr.empty() || tmpArr.back().second <= timeTable[i].first)
			tmpArr.push_back(timeTable[i]);
	
	return (int)tmpArr.size();
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> n;

		// vectors initialization
		timeTable.clear();
		tmpArr.clear();

		// input data
		for (int i = 0; i < n; i++)
		{
			cin >> itemName >> startTime >> endTime;
			timeTable.push_back(Pair{startTime, endTime});
		}

		sort(timeTable.begin(), timeTable.end(), cmp);

		cout << func() << endl;
	}

	return 0;
}
