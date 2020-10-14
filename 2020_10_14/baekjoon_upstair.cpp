#include<iostream>

using namespace std;

int max(int, int);

int main()
{
	int str[301] = { 0 };
	int dp[301] = { 0 };

	int number = 0;
	cin >> number; 

	for (int i = 0; i < number; i++)
	{
		int stair;
		cin >> stair;

		str[i] = stair;
	}

	int answer[2] = { 0 };
	dp[0] = str[0];
	dp[1] = max(str[0] + str[1], str[1]);
	dp[2] = max(str[0] + str[2], str[1] + str[2]);

	bool swt = false;
	int stack = 1;


	for (int i = 3; i < number; i++)
	{
		dp[i] = max(dp[i - 2] + str[i], dp[i - 3] + str[i - 1] + str[i]);

		cout << dp[i] << endl;
	}

	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}