#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int>& c, vector<vector<int>>& a)
{
	if (c[start]) return;

	c[start] = true;
	cout <<start << endl;

	sort(a[start].begin(), a[start].end());

	for (int i = 0; i < a[start].size(); i++)
	{
		int y = a[start][i];
		dfs(y, c, a);
	}
}

void bfs(int start, vector<int>c, vector<vector<int>> a)
{
	queue<int> q;
	q.push(start);
	c[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		cout << x << endl;

		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (!c[y])
			{
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main()
{
	int V;
	cin >> V;

	int M;
	cin >> M;

	vector<vector<int>> fs(V + 1);
	vector<int>line(V +1);

	int start;
	cin >> start;

	int dans = start;
	int bans = start;

	int temp = M;
	while (temp > 0)
	{
		int temp1, temp2;
		cin >> temp1;
		cin >> temp2;

		fs[temp1].push_back(temp2); 
		fs[temp2].push_back(temp1);

		temp--;
	}	

	dfs(dans, line, fs);

	for (int i = 0; i < line.size(); i++)
	{
		line[i] = false;
	}

	bfs(bans, line, fs);

	return 0;
}