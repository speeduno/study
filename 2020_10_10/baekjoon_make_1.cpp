#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int N;
	cin >> N;

	vector<int>dp(1000001);

	dp[1] = 0;

	int answer = 0;

	//DP문제
	//올라갈 것인가 내려갈것인가
	//올라간다.

	for(int i = 2; i<= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
		{
			if (dp[i] > dp[i / 2])
			{
				dp[i] = dp[i / 2] +1;
			}
		}

		if (i % 3 == 0)
		{
			if (dp[i] > dp[i / 3])
			{
				dp[i] = dp[i / 3] + 1;
			}
		}		

		cout << dp[i] << endl;
	}

	answer = dp[N];

	cout << answer << endl;
	return 0;
}