#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int T, n, d;
int cntArr[201];

// Function to find median
float findMid()
{
	float ret = 0;

	for (int i = 0; i < 201; i++)
	{
		if (ret == 0 && cntArr[i] >= d / 2)
			ret += (float)i;
		
		if (ret != 0 && cntArr[i] >= d / 2 + 1)
		{
			if (d % 2 == 1)
				return (float)i;

			ret += (float)i;
			break;
		}
	}

	ret /= 2;
	
	return ret;
}

// Using counting sorting algorithm
int func(vector<int>& arr)
{
	int cnt = 0;

	// Input initial information into the counting array.
	for (int i = 0; i < d; i++)
		cntArr[arr[i]]++;

	for (int i = 1; i < 201; i++)
		cntArr[i] += cntArr[i - 1];

	// Update counting arrangement
	for (int i = d; i < n; i++)
	{
		if (findMid() * 2 <= arr[i])
			cnt++;

		for (int j = 0; j < 201; j++)
		{
			if (j >= arr[i - d]) cntArr[j]--;
			if (j >= arr[i]) cntArr[j]++;
		}
	}

	return cnt;
}

int main()
{
	std::ios::sync_with_stdio(false);

	// Test Case
	cin >> T;

	while (T--)
	{
		memset(cntArr, 0, sizeof(cntArr));

		// Total number of dates, Date range
		cin >> n >> d;
		vector<int> arr(n, 0);

		for (int i = 0; i < n; i++)
			cin >> arr[i];
		
		cout << func(arr) << endl;
	}

	return 0;
}

// Time limit : 3 sec
// nlogn 시간복잡도의 정렬 알고리즘을 사용하면 n = 200000, d = 100000 인 경우 시간초과 발생
// 카운팅 정렬 알고리즘을 사용하여 시간 복잡도 n 에 정렬 구현가능
// worst case 는 10 ^ 5 * 10 ^ 5 