#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int T, M, N;
int num[8], answer;
stack<char> s;

int func(stack<char> tmp)
{
	if (tmp.size() == N - 1)
	{
		int n = num[0];
		int i = 1;
		vector<int> v;

		while (!tmp.empty())
		{
			if (tmp.top() == '*')
			{
				n *= num[i];
			}
			else
			{
				v.push_back(n);
				n = num[i];
			}
			i++;
			tmp.pop();
		}

		int ret = n;

		for (int i = 0; i < v.size(); i++)
			ret += v[i];

		if (ret == answer)
			return 1;
		else
			return 0;
	}

	int ret = 0;

	tmp.push('*');
	ret += func(tmp);

	tmp.pop();

	tmp.push('+');
	ret += func(tmp);

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> M >> N;
		string ans = "";
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
				cin >> num[j];

			cin >> answer;

			if (func(s) != 0)
				ans += "1 ";
			else
				ans += "0 ";
		}

		cout << ans << endl;
	}

	return 0;
}