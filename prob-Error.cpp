#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int T, M, N, len, countArr[26];
string alphabet[26], bitString;

string func()
{
	string ret = "";

	for (int i = 0; i < len; i++)
	{
		// hamming distance check
		for (int j = 0; j < M; j++)
			if (bitString[i] != alphabet[j][i % N])
				countArr[j]++;
	
		if (i != 0 && (i + 1) % N == 0)
		{
			// choose min hamming distance alphabet
			int minIndex = 0, compare = N;

			for (int j = 0; j < M; j++) 
			{
				if (countArr[j] < compare) {
					compare = countArr[j];
					minIndex = j;
				}
			}

			ret += ('A' + minIndex);

			memset(countArr, 0, sizeof(countArr));
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
		cin >> M >> N;

		for (int i = 0; i < M; i++)
			cin >> alphabet[i];

		cin >> len >> bitString;

		cout << func() << endl;
	}

	return 0;
}