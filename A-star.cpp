#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int MAP_SIZE = 10;

class Node {
private:
	int x, y, g, h, f;
	// x, y is index position of map array
	// g is distance from start position
	// h is distance from destination
	// f is g + h;

	bool open, closed;
	// open = true -> this node is in open priority queue, open = false -> not
	// closed = true -> this node is in closed priority queue, closed = false -> not

	Node* parent;
	// parent node of this node

public:
	Node(int x, int y) : x(x), y(y), g(0), h(0), f(0), open(false), closed(false), parent(NULL) { };
	Node(int x, int y, int g, int h, Node* parent = NULL) : x(x), y(y), g(g), h(h), f(g + h), open(false), closed(false), parent(parent) { }
	// initializer

	void SetG (int n)        { g = n; }
	void SetH (int n)        { h = n; }
	void SetF ()             { f = g + h; }
	void SetXY(int n, int m) { x = n; y = m; }
	void SetO(bool n)        { open = n; }
	void SetC(bool n)        { closed = n; }
	void SetP(Node* n)       { parent = n; }

	int   GetX() { return x; }
	int   GetY() { return y; }
	bool  GetO() { return open; }
	bool  GetC() { return closed; }
	int   GetG() { return g; }
	int   GetH() { return h; }
	int   GetF() { return f; }
	Node* GetP() { return parent; }

	// get, set functions
};

struct cmp {
	bool operator() (Node* a, Node* b)
	{
		return a->GetF() > b->GetF();
	}
};
// for priority queue
// Sort ascending by f

int mapArr[MAP_SIZE][MAP_SIZE];
Node* nodeArr[MAP_SIZE][MAP_SIZE];

// map info, node info

priority_queue <Node*, vector<Node*>, cmp> open;
priority_queue <Node*, vector<Node*>, cmp> closed;

int nextX[8] = { 0, 1, 1, 1, 0,-1,-1,-1 };
int nextY[8] = {-1,-1, 0, 1, 1, 1, 0,-1 };
// 8 direction from node

bool checkIndex(int x, int y)
{
	if (x < 0 || y < 0 || x >= MAP_SIZE || y >= MAP_SIZE)
		return false;

	return true;
}
// index valid check

int CalDis(int startX, int startY, int endX, int endY)
{
	int x = abs(startX - endX);
	int y = abs(startY - endY);

	int diagonal = min(x, y);
	x -= diagonal;
	y -= diagonal;

	return diagonal * 14 + (x + y) * 10;
}
// calculate distance, consider diagonal distance 

// main A* algorithm
bool FindPath(int endX, int endY)
{
	while (!open.empty()) 
	{
		Node* current = open.top();
		open.pop();
		closed.push(current);
		current->SetC(true);
		current->SetO(false);
		// current = node in OPEN with the lowest f
		// remove current from OPEN
		// add current to CLOSED

		if (current->GetX() == endX && current->GetY() == endY)
		{
			cout << "Find Path\n";
			return true;
		}
		// if current == destination -> function end; 

		for (int i = 0; i < 8; i++)
		{
			int nx = current->GetX() + nextX[i];
			int ny = current->GetY() + nextY[i];

			// check index validation
			if (checkIndex(nx, ny))
			{
				// if neighbout node is not traversable or is in closed
				if (mapArr[nx][ny] == 1 || nodeArr[nx][ny]->GetC())
					continue;

				// new path to neighbour is shorter or neighbour is not in OPEN
				if (!nodeArr[nx][ny]->GetO() ||
					(nodeArr[nx][ny]->GetO() &&
						nodeArr[nx][ny]->GetF() > CalDis(current->GetX(), current->GetY(), nx, ny) + CalDis(nx, ny, endX, endY)))
				{
					nodeArr[nx][ny]->SetG(CalDis(current->GetX(), current->GetY(), nx, ny));
					nodeArr[nx][ny]->SetH(CalDis(nx, ny, endX, endY));
					nodeArr[nx][ny]->SetF();
					nodeArr[nx][ny]->SetP(current);
					// set f of neighbour
					// set parent of neighbour to current

					if (!nodeArr[nx][ny]->GetO())
					{
						nodeArr[nx][ny]->SetO(true);
						open.push(nodeArr[nx][ny]);
					}
					// if neighbour is not in OPEN
					// add neighbour to OPEN
				}
			}
		}
	}

	cout << "No Path\n";
	return false;
	// open.empty() == true -> there are no next node in this case
}

int main()
{
	int startX, startY, endX, endY;
	memset(mapArr, 0, sizeof(mapArr));

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			cin >> mapArr[i][j];
			nodeArr[i][j] = new Node(i, j);
		}
	}
	// input map info and initialize node info

	cout << "Start : ";
	cin >> startX >> startY;

	cout << "End : ";
	cin >> endX >> endY;

	Node* start = new Node(startX, startY, 0, CalDis(startX, startY, endX, endY));
	open.push(start);
	start->SetO(true);

	if (FindPath(endX, endY))
	{
		Node* ans = closed.top();

		while (ans != NULL)
		{
			mapArr[ans->GetX()][ans->GetY()] = 5;
			ans = ans->GetP();
		}

		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				cout << mapArr[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}

// sample input
/*
0 0 0 1 0 1 1 1 1 1
0 0 0 1 0 1 0 0 0 0
0 1 0 1 0 1 1 0 0 0
0 1 0 1 0 0 1 0 1 1
0 1 0 1 0 0 1 0 1 0
0 1 0 0 0 1 1 0 1 0
0 1 0 1 0 0 0 0 1 0
0 1 0 1 0 1 0 0 0 0
0 1 0 1 0 1 1 1 1 1
0 1 0 1 0 0 0 0 0 0
0 0
9 9
*/
// sample output
/*
5 0 0 1 0 1 1 1 1 1
0 5 0 1 0 1 0 0 0 0
0 1 5 1 0 1 1 0 0 0
0 1 5 1 0 0 1 0 1 1
0 1 5 1 0 0 1 0 1 0
0 1 0 5 0 1 1 0 1 0
0 1 0 1 5 0 0 0 1 0
0 1 0 1 5 1 0 0 0 0
0 1 0 1 5 1 1 1 1 1
0 1 0 1 0 5 5 5 5 5
*/