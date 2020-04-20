#include <iostream>
#include <memory.h>
#include <queue>
#include <cmath>

using namespace std;

struct Info
{
	int x;
	int y;
	int z;
};

// testcase, row, col
int T, M, N;

// map information
char map[22][22];

// check visit with key
int visit[22][22][64];

// mask value for find all keys
int mask;

// next 4-direction
int nextX[4] = {-1, 0, 1, 0};
int nextY[4] = {0, 1, 0, -1};

// start position
Info startPos;


// initialize variables and arrays
void Init()
{
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 22; j++)
			map[i][j] = '#';

	memset(visit, 0, sizeof(visit));
	mask = 0;
}

int Bfs(int x, int y)
{
	//cout << mask << endl;


	// start position
	queue<Info> q;
	q.push(Info{x, y, 0});
	visit[x][y][0] = 1;
	int level = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		for (int idx = 0; idx < qSize; idx++)
		{
			// current pos
			Info current = q.front();
			int key = current.z;
			q.pop();

			//cout << current.x << "/" << current.y << "/" << key << ":" << level << endl;

			// check break
			if (mask == key)
				return level;

			for (int i = 0; i < 4; i++)
			{
				int nx = current.x + nextX[i];
				int ny = current.y + nextY[i];
				char roomChar = map[nx][ny];

				if (roomChar == '*' || roomChar == '@')
				{
					if (visit[nx][ny][key] == 0)
					{
						q.push(Info{ nx, ny, key });
						visit[nx][ny][key] = 1;
					}
				}

				if (roomChar >= 'a' && roomChar <= 'f')
				{
					int newKey = key;
					
					if(!(key & (int)pow(2, roomChar - 'a')))
						newKey += (int)pow(2, roomChar - 'a');

					if (!visit[nx][ny][newKey])
					{
						q.push(Info{nx, ny, newKey});
						visit[nx][ny][newKey] = 1;
					}
				}

				if (roomChar >= 'A' && roomChar <= 'F')
				{
					if ((key & (int)pow(2, roomChar - 'A')) && !visit[nx][ny][key])
					{
						q.push(Info{ nx, ny, key });
						visit[nx][ny][key] = 1;
					}
				}
			}
		}

		level++;
	}

	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		Init();

		cin >> M >> N;

		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];

				if (map[i][j] >= 'a' && map[i][j] <= 'f')
					mask += (int)pow(2, map[i][j] - 'a');

				if (map[i][j] == '@')
					startPos = Info{i, j, 0};
			}
		}

		cout << Bfs(startPos.x, startPos.y) << endl;
	}

	return 0;
}