#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

template <
	class T, 
	class Container,
	class Compare
> class Priority_queue
{
private:
	Container list;
	Compare cmp;

	void ReSorting()
	{
		int idx = 0, len = list.size(), left, right, tmp = 0;

		while (idx < len)
		{
			left = idx * 2 + 1;
			right = idx * 2 + 2;

			if (left >= len)
				break;

			if (left < len && right < len)
			{
				if (cmp(list[left], list[right]))
					tmp = right;
				else
					tmp = left;
			}
			else if (left < len && right >= len)
				tmp = left;

			if (cmp(list[idx], list[tmp])) 
			{
				swap(list[idx], list[tmp]);
				idx = tmp;
			}
			else
				break;
		}
	}
public:
	Priority_queue() { }

	void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	void push(T data)
	{
		list.push_back(data);

		int idx = list.size() - 1;

		while (idx > 0)
		{
			if (cmp(list[(idx - 1) / 2], list[idx]))
				swap(list[(idx - 1) / 2], list[idx]);

			idx = (idx - 1) / 2;
		}
	}

	void pop()
	{
		swap(list[0], list[(int)list.size() - 1]);
		list.pop_back();
		ReSorting();
	}

	T top()
	{
		return list[0];
	}

	void PrintQueue()
	{
		for (unsigned int i = 0; i < list.size(); i++)
			cout << list[i] << " ";
		cout << endl;
	}

	bool empty()
	{
		return list.empty();
	}

	bool find(T data)
	{
		return (std::find(list.begin(), list.end(), data) != list.end());
	}

};

struct cmp {
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main()
{
	srand((unsigned int)time(NULL));

	Priority_queue<int, vector<int>, cmp> test;

	for (int i = 0; i < 10; i++)
	{
		test.push(rand() % 1000);
		test.PrintQueue();
	}

	cout << test.find(293) << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << test.top() << " ";
		test.pop();
	}
	cout << endl;
	
	cout << test.empty() << endl;

	return 0;
}