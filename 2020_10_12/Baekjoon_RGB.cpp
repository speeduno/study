#include <iostream>
#include <vector>
using namespace std;

int min(int, int);

int main()
{
	int answer = 0;

	int N;
	cin >> N;

	vector<vector<int>> RGB;	

	int Dp[1000][3] = { 0 };

	for (int i = 0; i < N; i++)
	{
		vector<int>temp;	
		for (int j = 0; j < 3; j++)
		{	
			int color;
			cin >> color;

			temp.push_back(color);
		}
			
		RGB.push_back(temp);		

		temp.clear();
	}	

	Dp[0][0] = RGB[0][0];	
	Dp[0][1] = RGB[0][1];	
	Dp[0][2] = RGB[0][2];	

	for (int i = 1; i < N; i++)
	{		
		Dp[i][0] = min(Dp[i - 1][1], Dp[i - 1][2]) + RGB[i][0];


		Dp[i][1] = min(Dp[i - 1][0], Dp[i - 1][2]) + RGB[i][1];


		Dp[i][2] = min(Dp[i - 1][0], Dp[i - 1][1]) + RGB[i][2];



		cout << RGB[i][0] << ":" << RGB[i][1] << ":" << RGB[i][2] << endl;
		cout << Dp[i][0] << ":" << Dp[i][1] << ":" << Dp[i][2] << endl;
	}

	answer = Dp[N - 1][0];
	for (int i = 0; i < 3; i++)
	{
		if (Dp[N-1][i] < answer)
		{
			answer = Dp[N - 1][i];
		}
	}

	cout << answer << endl;

	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}