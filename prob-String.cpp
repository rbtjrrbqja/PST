#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int T, Salpha[52], Ralpha[52];
string S, R;

// compare Salpha array and Ralpha array
bool compare()
{
	for (int i = 0; i < 52; i++)
		if (Ralpha[i] != 0 && Salpha[i] < Ralpha[i])
			return false;

	return true;
}

// check alphabet count and write number of alphabet into array
void alphabetCount(char c, int arr[], int n)
{
	if (c > 'Z')
		arr[c - 'a'] += n;
	else
		arr[c - 'A' + 26] += n;
}

int func()
{
	int startIdx = 0, endIdx = 0, minLen = S.length() + 1;

	// initialize Ralpha array
	for (int i = 0; i < (int)R.length(); i++)
		alphabetCount(R[i], Ralpha, 1);

	while (endIdx < (int)S.length())
	{
		alphabetCount(S[endIdx], Salpha, 1);

		// if window of S contains all alphabets of R
		while (compare())
		{
			int winLen = endIdx - startIdx + 1;

			minLen = min(minLen, winLen);

			alphabetCount(S[startIdx], Salpha, -1);

			// start index + 1
			startIdx++;
		}

		// end index + 1;
		endIdx++;
	}

	// return value
	return (minLen == S.length() + 1) ? 0 : minLen;
}

int main()
{
	cin >> T;

	while (T--)
	{
		memset(Ralpha, 0, sizeof(Ralpha));
		memset(Salpha, 0, sizeof(Salpha));

		cin >> S >> R;
		cout << func() << endl;
	}

	return 0;
}