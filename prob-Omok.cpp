#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

typedef pair<int, int> Pair;

int T, x, y;
int board[16][16];

const int nextX[8] = { 0,  1, 1, 1, 0, -1, -1, -1};
const int nextY[8] = {-1, -1, 0, 1, 1,  1,  0, -1};

bool CheckIndex(int x, int y)
{
	if (x < 1 || y < 1 || x > 15 || y > 15)
		return false;

	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		memset(board, 0, sizeof(board));

		vector<Pair> position(1, Pair{ 0, 0 });

		// vector에 바둑돌 위치정보 insert
		for (int i = 1; i <= 225; i++)
		{
			cin >> x >> y;
			position.push_back(Pair{x, y});
		}

		// vector 를 순회하며 board에 입력후 오목 확인
		for (int i = 1; i <= 225; i++)
		{
			char turn;

			// 검은돌 : 1, 흰돌 : 2
			if (i % 2 == 1)
			{
				board[position[i].first][position[i].second] = 1;
				turn = 'B';
			}
			else
			{
				board[position[i].first][position[i].second] = 2;
				turn = 'W';
			}

			// 현재 둔 돌
			int current = board[position[i].first][position[i].second];

			// 각 방향의 연속된 돌의 개수
			int dir[4] = { 1, 1, 1, 1 };

			// 8방향 루프
			for (int j = 0; j < 8; j++)
			{
				int curX = position[i].first;
				int curY = position[i].second;

				while (CheckIndex(curX + nextX[j], curY + nextY[j]))
				{
					if (board[curX + nextX[j]][curY + nextY[j]] == current)
						dir[j % 4]++;
					else
						break;

					curX = curX + nextX[j];
					curY = curY + nextY[j];
				}
			}

			if (dir[0] == 5 || dir[1] == 5 || dir[2] == 5 || dir[3] == 5)
			{
				cout << i << " " << turn << endl;
				break;
			}
		}
	}

	return 0;
}