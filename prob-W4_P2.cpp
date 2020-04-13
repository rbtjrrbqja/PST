#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

typedef pair<int, int> Pair;

int T, L, board[500][500];
Pair startPos, endPos;

const int nextX[8] = { 2,2,-2,-2,1,1,-1,-1 };
const int nextY[8] = { 1,-1,1,-1,2,-2,2,-2 };

const int MAX_INT = 987654321;

bool IndexCheck(int x, int y)
{
	if (x < 0 || y < 0 || x >= L || y >= L)
		return false;

	return true;
}

int func(int x, int y)
{
	queue<Pair> q;
	q.push(Pair{x, y});
	board[x][y] = 0;

	while (!q.empty())
	{
		Pair current = q.front();
		q.pop();

		if (current.first == endPos.first && current.second == endPos.second)
			return board[endPos.first][endPos.second];

		for (int i = 0; i < 8; i++)
		{
			int nx = current.first + nextX[i];
			int ny = current.second + nextY[i];

			if (IndexCheck(nx, ny) && board[nx][ny] == MAX_INT)
			{
				q.push(Pair{ nx, ny });
				board[nx][ny] = min(board[nx][ny], board[current.first][current.second] + 1);
			}
		}
	}

	return 0;
}

void Init()
{
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			board[i][j] = MAX_INT;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> L;

		Init();

		cin >> startPos.first >> startPos.second;
		cin >> endPos.first >> endPos.second;

		cout << func(startPos.first, startPos.second) << endl;
	}

	return 0;
}