#include <iostream>
#include <vector>
#include <memory.h>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, a, b, x;
const int MOD = 1013;

int func(vector<int>& nums)
{
	int cnt = 0;

	do
	{
		int ret = 0;

		for (int i = 0; i < N; i++)
			ret += (long long)pow(x, i) * nums[i] % MOD;

		ret %= MOD;

		if (a <= ret && ret <= b)
			cnt++;

	} while (next_permutation(nums.begin(), nums.end()));

	return cnt;
}


int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> N;
		vector<int> nums(N, 0);

		for (int i = 0; i < N; i++)
			cin >> nums[i];

		cin >> a >> b >> x;
		
		sort(nums.begin(), nums.end());
		cout << func(nums) << endl;
	}

	return 0;
}