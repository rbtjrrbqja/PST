#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int T, M, N;
char num[8];
int answer;

// * 42, + 43
string infixToPostfix(string s)
{
	stack<char> oper;
	string ret = "";
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		if (s[i] != '+' && s[i] != '*')
		{
			ret += s[i];
			continue;
		}

		if (oper.empty())
		{
			oper.push(s[i]);
			continue;
		}

		if (oper.top() > s[i])
			oper.push(s[i]);
		else 
		{
			while(!oper.empty() && oper.top() <= s[i])
			{
				ret += oper.top();
				oper.pop();
			}

			oper.push(s[i]);
		}
	}

	while (!oper.empty())
	{
		ret += oper.top();
		oper.pop();
	}

	return ret;
}

// postfix to result int
int evaluate(string s)
{
	stack<int> num;
	int len = s.length();
	
	for (int i = 0; i < len; i++)
	{
		if (s[i] != '*' && s[i] != '+')
		{
			num.push(s[i] - '0');
			continue;
		}

		int tmp = num.top();
		num.pop();

		if (s[i] == '*')
			tmp *= num.top();
		else
			tmp += num.top();

		num.pop();
		num.push(tmp);
	}

	return num.top();
}

bool func()
{
	string infix = "";

	for (int i = 0; i < N; i++)
	{
		infix += num[i];

		if (i != N - 1)
			infix += " ";
	}

	int opSet = (int)pow(2, N - 1) - 1;

	while (opSet >= 0)
	{
		int mask = 1;

		// 1 -> +, 0 -> *
		for (int i = 0; i < N - 1; i++)
		{
			if (opSet & mask)
				infix[i * 2 + 1] = '+';
			else
				infix[i * 2 + 1] = '*';

			mask = mask << 1;
		}

		//cout << "infix : " << infix << endl;
		string postfix = infixToPostfix(infix);
		//cout << "postfix : " << postfix << endl;
		int result = evaluate(postfix);
		//cout << "result : " << result << endl << endl;

		if (result == answer)
			return true;

		opSet--;
	}

	return false;
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

			if (func())
				ans += "1 ";
			else
				ans += "0 ";
		}

		cout << ans << endl;
	}

	return 0;
}