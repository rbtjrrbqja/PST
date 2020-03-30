#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int MAZE_SIZE = 40;
const int MAZE_MAP_SIZE = MAZE_SIZE * 2 + 1;

// 4-direction, N E S W
const int nextX[4] = {0, 1, 0, -1};
const int nextY[4] = {1, 0, -1, 0};

// simple spaw function
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

class Node
{
private:
	int x;
	int y;
	bool visit;
	Node* prev;
	// for choose next direction randomly
	vector<int> dir;

public:

	Node(int x, int y): x(x), y(y), visit(false), prev(NULL) 
	{ 
		dir.resize(4, 0);
		
		for (int i = 0; i < 4; i++)
			dir[i] = i;

		for (int i = 0; i < 4; i++)
			swap(dir[i], dir[rand() % 4]);
	}

	Node* GetPrev() const
	{
		return prev;
	}

	void SetPrev(Node* n)
	{
		prev = n;
	}

	int GetX() const
	{
		return x;
	}

	int GetY() const
	{
		return y;
	}

	bool GetVisit() const 
	{
		return visit;
	}

	void SetVisit(bool b)
	{
		visit = b;
	}

	int GetDirLen() const
	{
		return dir.size();
	}

	// pop and return
	int DirPop()
	{
		int ret = dir.back();
		dir.pop_back();
		return ret;
	}
};

bool checkIndex(int x, int y)
{
	if (x < 0 || y < 0 || x >= MAZE_SIZE || y >= MAZE_SIZE)
		return false;

	return true;
}

vector<vector<Node*>> maze(MAZE_SIZE, vector<Node*>(MAZE_SIZE, NULL));
vector<vector<int>> mazeMap(MAZE_MAP_SIZE, vector<int>(MAZE_MAP_SIZE, 1));

void makeMaze(Node* prev, Node* cur, int size)
{
	int x, y;

	cur->SetPrev(prev);

	// first node
	if (cur->GetPrev() == NULL)
		mazeMap[0][1] = 0;
	else
	{
		// others
		x = prev->GetX() - cur->GetX();
		y = prev->GetY() - cur->GetY();
		mazeMap[(cur->GetX() + 1) * 2 - 1 + x][(cur->GetY() + 1) * 2 - 1 + y] = 0;
	}

	cur->SetVisit(true);
	mazeMap[(cur->GetX() + 1) * 2 - 1][(cur->GetY() + 1) * 2 - 1] = 0;

	// backtracking
	while (true)
	{
		if (cur->GetDirLen() == 0)
			break;
		
		int idx = cur->DirPop();
		int nx = cur->GetX() + nextX[idx];
		int ny = cur->GetY() + nextY[idx];

		if (checkIndex(nx, ny))
			if (!maze[nx][ny]->GetVisit())
				makeMaze(cur, maze[nx][ny], size + 1);
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAZE_SIZE; i++)
		for (int j = 0; j < MAZE_SIZE; j++)
			maze[i][j] = new Node(i, j);

	makeMaze(NULL, maze[0][0], 0);

	for (int i = 0; i < MAZE_MAP_SIZE; i++) {
		for (int j = 0; j < MAZE_MAP_SIZE; j++) {
			if (mazeMap[i][j] == 1)
				cout << "бс";
			else
				cout << "  ";
		}
		cout << endl;
	}

	return 0;
}