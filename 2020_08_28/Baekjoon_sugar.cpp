#include<iostream>

using namespace std;

// 다시 생각하기

int main()
{
	int sugar;
	cin >> sugar;

	int answer = 0;
	int m = 5;
	int n = 3;

	int temp = sugar;
	int max_n = sugar / n;

	for (int i = 0; i <= max_n; i++)
	{
		temp = sugar - (n * i);

		if (temp % m == 0)
		{
			answer = ((i)+(temp / m));
			break;
		}


		if (i == max_n)
		{
			if (temp != 0)
				answer = -1;
		}
	}

	cout << answer << endl;

	return 0;
}