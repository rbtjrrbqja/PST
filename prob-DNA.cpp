#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int T, M, N;
int countArr[4][1000]; // A C G T
string DNA[1000];
string standard;

// Function to find the representative sequence
// The representative sequence is the most common character in the sequence 
// (if it is the same, it is alphabetically preceded)
string func1()
{
	string ret = "";

	// Investigate the number of times each sequence character appears
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			switch (DNA[i][j])
			{
				case 'A':
					countArr[0][j]++;
					break;
				case 'C':
					countArr[1][j]++;
					break;
				case 'G':
					countArr[2][j]++;
					break;
				case 'T':
					countArr[3][j]++;
					break;
			}
		}
	}

	// Select the character that appears the most, return sequence
	for (int i = 0; i < N; i++)
	{
		int tmp1 = countArr[0][i] >= countArr[1][i] ? 0 : 1;
		int tmp2 = countArr[2][i] >= countArr[3][i] ? 2 : 3;

		int tmp3 = countArr[tmp1][i] >= countArr[tmp2][i] ? tmp1 : tmp2;

		switch (tmp3)
		{
			case 0:
				ret += 'A';
				break;
			case 1:
				ret += 'C';
				break;
			case 2:
				ret += 'G';
				break;
			case 3:
				ret += 'T';
				break;
		}
	}

	return standard = ret;
}

// Find Sum of Hamming distance
int func2()
{
	int ret = 0;

	for (int i = 0; i < M; i++)
	{
		int tmp = 0;

		for (int j = 0; j < N; j++)
			if (standard[j] != DNA[i][j])
				tmp++;
		
		ret += tmp;
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	// Test Case
	cin >> T;

	while (T--)
	{
		memset(countArr, 0, sizeof(countArr));
		// Number of Sequence, Length of Sequence
		cin >> M >> N;

		for (int i = 0; i < M; i++)
			cin >> DNA[i];

		cout << func1() << "\n";
		cout << func2() << "\n";
	}

	return 0;
}